#include "arclstartnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    ArcLStartNode::ArcLStartNode(/*QString* name,*/ ListNode<ASTNode>* arguments) : ASTNode(),/*_name(*name),*/
        _arguments(arguments)
    {
        signalParseInst(_arguments);
    }


    QVariant ArcLStartNode::Execute()
    {

        signalRunInst();
        return ASTNode::Execute();
    }
    QString ArcLStartNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("ArcLStart");
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
    void ArcLStartNode::compute()
    {
        signalParseInst(_arguments);
    }
}
