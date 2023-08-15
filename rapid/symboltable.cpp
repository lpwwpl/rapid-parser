#include "symboltable.h"
#include <map>
#include "ast.h"
#include "errors.h"
#include <memory>
#include <iostream>
#include <thread>
#include <mutex>
using namespace Language;

extern int lineNumber;

std::unique_ptr<SymbolTable> SymbolTable::_instance = nullptr;
std::once_flag SymbolTable::_onceFlag;


SymbolTable::SymbolTable()
    : _entrypoint(nullptr)
{
    DefineTypes("NUM");
    DefineTypes("BOOL");
    DefineTypes("STRING");
    DefineTypes("ROBTARGET");
    DefineTypes("JOINTTARGET");
    DefineTypes("WOBJDATA");
    DefineTypes("ZONEDATA");
    DefineTypes("SPEEDDATA");
    DefineTypes("TOOLDATA");
    DefineTypes("SEAMDATA");
    DefineTypes("WELDDATA");
}

SymbolTable & SymbolTable::Instance()
{
    std::call_once(_onceFlag,
            [] {
                _instance.reset(new SymbolTable);
        });
        return *_instance.get();
}
Language::ModuleNode* SymbolTable::Module(QString* name)
{
    auto fp = _modules[*name];
    if (nullptr == fp)
    {
        //std::cerr << UNDEFINED_FUNCTION << "(" << name->toStdString() << ")\n";
        //exit(EXIT_FAILURE);
    }
    return fp;
}
Language::FunctionNode * SymbolTable::Function(QString * name)
{
    auto fp = _functions[*name];
    if (nullptr == fp)
    {
        //std::cerr << UNDEFINED_FUNCTION << "(" << name->toStdString() << ")\n";
        //exit(EXIT_FAILURE);
    }
    return fp;
}
bool SymbolTable::DefineModules(QString* name, Language::ModuleNode* node)
{
    if (_modules.count(*name) != 0)
    {
        //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
        //exit(EXIT_FAILURE);
    }

    //if ("main" == *name)
    //    _entrypoint = node;

    _modules[*name] = node;

    return true;
}
 bool SymbolTable::DefineFunction(QString * name, Language::FunctionNode *node)
 {
     if (_functions.count(*name) != 0)
     {
         //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
         //exit(EXIT_FAILURE);
     }

     if ("main" == *name)
         _entrypoint = node;

     _functions[*name] = node;

     return true;
 }

 //bool SymbolTable::DefineStructTypes(QString* name, Language::StructDescNode* node)
 //{
 //    if (_structTypes.count(*name) != 0)
 //    {
 //        //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
 //        //exit(EXIT_FAILURE);
 //    }

 //    _structTypes[*name] = node;

 //    return true;
 //}

 bool SymbolTable::DefineTypes(std::string name)
 {
    if (_types.count(name) != 0)
    {
        //std::cerr << FUNCTION_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
        //exit(EXIT_FAILURE);
    }

    _types.insert(name);

    return true;
 }
 void SymbolTable::calcTargetPoint()
 {
     for (auto it : _modules)
     {
         QString funName = it.first;
         Language::ModuleNode* module = it.second;
        

     }
 }
 QString SymbolTable::toString()
 {
     //std::map<QString, Language::FunctionNode*>
     QString str = "";
     for (auto it : _modules)
     {
         QString funName = it.first;
         Language::ModuleNode* module = it.second;
         if (!module)continue;
         str += module->toString(1);
         str += "\n";
     }
     //for (auto it: _functions)
     //{
     //    QString funName = it.first;
     //    Language::FunctionNode* func = it.second;
     //    if (!func)continue;
     //    str += func->toString(1);
     //    str += "\n";
     //}
     return str;
 }
Language::FunctionNode * SymbolTable::EntryPoint()
{
    if (nullptr == _entrypoint)
    {
        std::cerr << "Dang ! No entrypoint. Bailing out..." << std::endl;
        exit(1);
    }
    return _entrypoint;
}

ActivationRecord * SymbolTable::GetActivationRecord()
{
    if (_activationRecordStack.size() == 0)
        return NULL;
    return _activationRecordStack.top();
}

void SymbolTable::PushAR()
{
    _activationRecordStack.push(new ActivationRecord());
}

void SymbolTable::PopAR()
{
    _activationRecordStack.pop();
}

QVariant SymbolTable::PopArgument()
{
    QVariant retVal = _argumentStack.top();
    _argumentStack.pop();
    return retVal;
}

void SymbolTable::PushArgument(QVariant argument)
{
    _argumentStack.push(argument);
}

void SymbolTable::PushCommandLineArguments(const int argc, char **argv)
{
    for (int i=0; i<argc; i++)
    {
        _argumentStack.push(QVariant(argv[i]));
    }
    _argumentStack.push(argc);
}

QString SymbolTable::TypeName(int type) const
{
    switch(type)
    {
        case token::NumberType: return "Number";
        case token::TextType: return "Text";
        case token::VoidType: return "Void";
        default: std::cerr << "Woops, forgot to map type name...\n";
                              exit(EXIT_FAILURE);
    }
}



void SymbolTable::AssignVariable(QString realVar, QString type, QVariant value)
{
    VariableRecord v;
    v.value = value;
    v.type = type;
    _variables[realVar] = v;
}
void SymbolTable::AssignVariable(QString name, QString type,QVariant value, dimRawType* tempDimList)
{
    QString realVar = CalcRealVarName(name, tempDimList);
    VariableRecord v;
    v.value = value;
    v.type = type;
    _variables[realVar] = v;
}


void SymbolTable::DeclareVariable(QString name, dimRawType* tempDimList)
{
    QString realVar = CalcRealVarName(name, tempDimList);
    bool isDefinedVar = isDefined(realVar);
    if (!isDefinedVar)
    {
        _variables[realVar] = VariableRecord();
    }
}


VariableRecord SymbolTable::GetVariableValue(QString name)
{
    return _variables[name];
}

QString SymbolTable::VariableType(QString name)
{
    if (_variables.count(name) == 0)
    {
        return "";
    }
    return _variables[name].type;
}

bool SymbolTable::DefineVariable(QString * name, QString type)
{
    if (_variables.count(*name) != 0)
    {
        return true;
        //std::cerr << VARIABLE_REDECLARATION << "(" << name->toStdString() << ", line: " << lineNumber << ")\n";
        //exit(EXIT_FAILURE);
    }

    VariableRecord r;
    r.type = type;
    _variables[*name] = r;

    return true;
}

void SymbolTable::ClearVariables()
{
    _variables.clear();
}

QString SymbolTable::CalcRealVarName(QString name, Language::dimRawType* tempDimList)
{
    QString realVar = name;

    int ndim;
    if (tempDimList != NULL)
        ndim = tempDimList->size();
    else
        ndim = 0;

    for (int i = 0; i < ndim; i++)
    {
        QString index = tempDimList->at(i)->toRaw();
        QString dimVar = QString("_%1").arg(index);
        realVar = realVar.append(dimVar);
    }
    return realVar;
}



