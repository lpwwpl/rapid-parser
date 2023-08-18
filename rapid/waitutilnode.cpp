#include "waitutilnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    WaitUntilNode::WaitUntilNode(ASTNode* dim/*dimListType* dim*/):_expression(dim)
    {
       
    }

    QVariant WaitUntilNode::Execute()
    {
        signalRunInst();
        return QVariant();
        //return ASTNode::Execute();
    }
    QString WaitUntilNode::toRaw(uint level)
    {
     
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("WaitUntil ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
