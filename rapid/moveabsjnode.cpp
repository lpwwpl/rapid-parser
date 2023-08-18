#include "moveabsjnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    MoveABSJNode::MoveABSJNode(/*QString* name, */ListNode<ASTNode>* arguments) : ASTNode(),/* _name(*name),*/
        _arguments(arguments)
    {

    }


    QVariant MoveABSJNode::Execute()
    {
        signalRunInst();

        return ASTNode::Execute();
    }
    void MoveABSJNode::compute()
    {
        signalParseInst(_arguments);
    }
    QString MoveABSJNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("MoveAbsJ");
        str.append(" ");
        for (auto statement : *_arguments)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toRaw(level));
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        str.append(";");
        return str;
    } 
}
