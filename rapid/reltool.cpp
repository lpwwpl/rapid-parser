#include "reltool.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    RelToolNode::RelToolNode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant RelToolNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString RelToolNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("RelTool ");
        //str.append(_name);
        str.append("(");
        str.append(_expression->toRaw());
        str.append(")");
        return str;
    }

    QString RelToolNode::toString(uint level)
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
