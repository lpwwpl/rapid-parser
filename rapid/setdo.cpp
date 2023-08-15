#include "setdo.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    SetDoNode::SetDoNode(ASTNode* name,ASTNode* dim/*dimListType* dim*/) :_name(name),_expression(dim)
    {

    }

    QVariant SetDoNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString SetDoNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("SetDo ");
        str.append(_name->toRaw());
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }

    QString SetDoNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("SetDo ");
        str.append(_name->toString());
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
