#include "deactunitnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    DeActUnitNode::DeActUnitNode(/*QString* name,*/ ListNode<ASTNode>* arguments) : ASTNode(),/*_name(*name),*/
        _arguments(arguments)
    {
        signalParseInst(_arguments);
    }


    QVariant DeActUnitNode::Execute()
    {

        signalRunInst();
        return ASTNode::Execute();
    }
    QString DeActUnitNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("DeactUnit");
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
