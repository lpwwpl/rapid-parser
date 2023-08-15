#include "set.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    SetNode::SetNode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant SetNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString SetNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("Set ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }

    QString SetNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("Set ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
