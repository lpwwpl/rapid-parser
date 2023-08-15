#include "arccnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    ArccNode::ArccNode(/*QString* name,*/ ListNode<ASTNode>* arguments) :ASTNode("ARCC"),/*_name(*name),*/
        _arguments(arguments)
    {
        signalParseInst(_arguments);
    }


    QVariant ArccNode::Execute()
    {

        signalRunInst();
        return ASTNode::Execute();
    }
    QString ArccNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("ArcC");
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
    void ArccNode::compute()
    {
        signalParseInst(_arguments);
    }
    QString ArccNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("arcc");
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
