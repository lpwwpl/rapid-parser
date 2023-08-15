#include "waitdinode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    WaitDiNode::WaitDiNode(QString* name,ASTNode* dim/*dimListType* dim*/) :_name(*name),_expression(dim)
    {

    }

    QVariant WaitDiNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString WaitDiNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("WaitDI ");
        str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }

    QString WaitDiNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("WaitDI ");
        str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
