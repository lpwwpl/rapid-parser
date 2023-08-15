#include "arclnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    ArcLNode::ArcLNode(/*QString* name,*/ ListNode<ASTNode>* arguments) : ASTNode("ARCL"),/*_name(*name),*/
        _arguments(arguments)
    {
        signalParseInst(_arguments);
    }


    QVariant ArcLNode::Execute()
    {

        signalRunInst();
        return ASTNode::Execute();
    }
    QString ArcLNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("ArcL");
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

    void ArcLNode::compute()
    {
        signalParseInst(_arguments);
    }
    QString ArcLNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("arcL");
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
