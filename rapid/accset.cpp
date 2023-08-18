#include "accset.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    AccSetNode::AccSetNode(ASTNode* exp1, ASTNode* exp2/*dimListType* dim*/) :_expression1(exp1), _expression2(exp2)
    {

    }

    QVariant AccSetNode::Execute()
    {
        signalRunInst();
        return QVariant();
        //return ASTNode::Execute();
    }
    QString AccSetNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("AccSet");
        //str.append(_name);
        str.append(" ");
        str.append(_expression1->toRaw());
        str.append(",");
        str.append(_expression2->toRaw());
        str.append(";");
        return str;
    }
}
