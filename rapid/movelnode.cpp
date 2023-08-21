#include "movelnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    MoveLNode::MoveLNode(/*QString* name,*/ ListNode<ASTNode>* arguments) : ASTNode(),/* _name(*name),*/
        _arguments(arguments)
    {
        //FLT_MAX;

      
    }


    QVariant MoveLNode::Execute()
    {

        signalRunInst();
        return ASTNode::Execute();
    }
    void MoveLNode::compute()
    {
        signalParseInst(_arguments);
    }
    QString MoveLNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("MoveL");
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
