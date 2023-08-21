#include "actunitnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    ActUnitNode::ActUnitNode(/*QString* name,*/ ListNode<ASTNode>* arguments):ASTNode(),/*_name(*name),*/
        _arguments(arguments)
    {
        signalParseInst(_arguments);
    }

   
    QVariant ActUnitNode::Execute()
    {     

        signalRunInst();
        return ASTNode::Execute();
    }
    QString ActUnitNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }

        str.append("ActUnit");
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
