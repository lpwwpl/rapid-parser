#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <QString>
#include <map>
#include <stack>
#include <memory>
#include <set>
#include "ast.h"
#include "activationrecord.h"
#include "variablerecord.h"
#include "structdesc.h"
//#include "PreCompiled.h"
namespace Language {
    class RobotAbbExport SymbolTable
    {
    private:
        SymbolTable();
        static std::unique_ptr<SymbolTable> _instance;
        static std::once_flag _onceFlag;

        Language::FunctionNode* _entrypoint;
        std::stack<ActivationRecord*> _activationRecordStack;
        std::stack<QVariant> _argumentStack;
        std::map<QString, Language::ModuleNode*> _modules;
        std::map<QString, Language::FunctionNode*> _functions;
        //std::map<QString, Language::StructDescNode*> _structTypes;
        std::map<QString, VariableRecord> _variables;
        std::set<std::string> _types;

    public:
        static SymbolTable& Instance();
        std::map<QString, VariableRecord> Variables()
        {
            return _variables;
        }
        std::map<QString, Language::ModuleNode*> Modules()
        {
            return _modules;
        }
        Language::FunctionNode* Function(QString* name);
        Language::ModuleNode* Module(QString* name);

        bool DefineFunction(QString* name, Language::FunctionNode* node);
  /*      bool DefineStructTypes(QString* ,Language::StructDescNode*);*/
        bool DefineModules(QString* name, Language::ModuleNode* node);
        bool DefineTypes(std::string name);
        QString VariableType(QString name);
        bool DefineVariable(QString* name, QString type);
        void ClearVariables();

        void calcTargetPoint();
        QString toString();
        Language::FunctionNode* EntryPoint();
        ActivationRecord* GetActivationRecord();
        void PushAR();
        void PopAR();
        QVariant PopArgument();
        void PushArgument(QVariant argument);
        void PushCommandLineArguments(const int argc, char** argv);

        QString TypeName(int type) const;

        QString CalcRealVarName(QString name, Language::dimRawType* tempDimList);
        void AssignVariable(QString name, QString, QVariant value);
        void AssignVariable(QString name, QString, QVariant value, Language::dimRawType* tempDimList);
        void DeclareVariable(QString name, Language::dimRawType* tempDimList = NULL);
        VariableRecord GetVariableValue(QString name);
        bool isDefined(QString varName) {
            if (_variables.find(varName) == _variables.end()) return false;
            else return true;//return _variables[varName];
        }
    };
}
#endif // SYMBOLTABLE_H
