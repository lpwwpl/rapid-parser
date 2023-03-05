#include "movelnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    MoveLNode::MoveLNode(/*QString* name,*/ ListNode<ASTNode>* arguments) :/* _name(*name),*/
        _arguments(arguments)
    {
        //FLT_MAX;
    }


    QVariant MoveLNode::Execute()
    {


        return ASTNode::Execute();
    }

    QString MoveLNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("self.movel");
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
