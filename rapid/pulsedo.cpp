#include "pulsedo.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    PulseDONode::PulseDONode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant PulseDONode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString PulseDONode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("PulseDo ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
