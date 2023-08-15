#include "velset.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    VelSetNode::VelSetNode(ASTNode* exp1,ASTNode* exp2/*dimListType* dim*/) :_expression1(exp1),_expression2(exp2)
    {

    }

    QVariant VelSetNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString VelSetNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("VelSet ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression1->toRaw());
        str.append(",");
        str.append(_expression2->toRaw());
        str.append(";");
        return str;
    }

    QString VelSetNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("VelSet ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression1->toString());
        str.append(",");
        str.append(_expression2->toString());
        str.append(";");
        return str;
    }
}
