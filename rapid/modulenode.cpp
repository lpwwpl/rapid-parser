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

    QString ModuleNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        for (auto statement : *_body)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toString(level));          
        }


        return str;
    }
}
