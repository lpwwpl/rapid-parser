#include "movejnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    MoveJNode::MoveJNode(/*QString* name,*/ ListNode<ASTNode>* arguments) : /*_name(*name),*/
        _arguments(arguments)
    {

    }


    QVariant MoveJNode::Execute()
    {


        return ASTNode::Execute();
    }

    QString MoveJNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("movej");
        str.append("(");
        for (auto statement : *_arguments)
        {

            if (!statement)continue;
            //statement->Execute();
            str.append(statement->toString(level));
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        str.append(")");
        return str;
    }
}
