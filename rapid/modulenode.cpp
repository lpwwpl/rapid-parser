#include "modulenode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    ModuleNode::ModuleNode(QString* name, ListNode<ASTNode>* arguments) : _name(*name),
        _body(arguments)
    {
        SymbolTable::Instance().DefineModules(name, this);
    }


    QVariant ModuleNode::Execute()
    {


        return ASTNode::Execute();
    }

    void ModuleNode::compute()
    {
        for (auto statement : *_body)
        {
            if (!statement)continue;
            //statement->Execute();
            statement->compute();
        }
    }
    QString ModuleNode::toRaw(uint level )
    {
        QString str = "MODULE ";
        str += _name;
        str += "\n";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        for (auto statement : *_body)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toRaw(level+1));
        }
        str += "ENDMODULE";
        str += "\n";
        return str;
    }
    QString ModuleNode::toString(uint level)
    {

        QString str = "";
        for (auto statement : *_body)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toString(level+1));
        }
        return str;
       
    }
}
