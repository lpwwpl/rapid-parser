#include "waittime.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    WaitTimeNode::WaitTimeNode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant WaitTimeNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString WaitTimeNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("WaitTime ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }

    QString WaitTimeNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("WaitTime ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
