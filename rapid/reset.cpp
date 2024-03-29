#include "reset.h"
#include "symboltable.h"
#include "errors.h"



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
        str.append("ReSet");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }

}
