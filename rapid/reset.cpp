#include "reset.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    ReSetNode::ReSetNode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant ReSetNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString ReSetNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("ReSet ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }

    QString ReSetNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("ReSet ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
