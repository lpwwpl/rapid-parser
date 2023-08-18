#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <QString>
#include <map>
#include <stack>
#include <memory>
#include <vector>
#include <set>
#include <unordered_set>
#include "ast.h"
#include "activationrecord.h"
#include "variablerecord.h"
#include "structdesc.h"
//#include "PreCompiled.h"
namespace Language {

    using TypeNamePair = std::pair<QString, QString>;

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
        std::map<QString, Language::StructDescNode*> _structTypes;
        std::map<QString, VariableRecord> _variables;
        std::unordered_set<std::string> TypeNames{ "int","double","string","boolean","var" };
        std::map<QString, std::vector<TypeNamePair>> _structMembers;

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
        bool DefineStructTypes(QString* ,Language::StructDescNode*);
        bool DefineModules(QString* name, Language::ModuleNode* node);
        bool DefineTypes(QString name);
        QString VariableType(QString name);
        bool DefineVariable(QString* name,enum_v_type type, QString v_type);
        void ClearVariables();

        Language::FunctionNode* EntryPoint();
        ActivationRecord* GetActivationRecord();
        void PushAR();
        void PopAR();
        QVariant PopArgument();
        void PushArgument(QVariant argument);
        void PushCommandLineArguments(const int argc, char** argv);

        void AssignVariable(QString name, enum_v_type type, QString, QVariant value);
        void DeclareVariable(QString name);
        VariableRecord GetVariableValue(QString name);
        bool isDefined(QString varName) {
            if (_variables.find(varName) == _variables.end()) return false;
            else return true;//return _variables[varName];
        }

        void addStructMember(QString structName, QString memType, QString memName);

        long getStructMemberIndex(QString structName, QString memberName);
        QString getVarType(VariableRecord&);

    };
}
#endif // SYMBOLTABLE_H
