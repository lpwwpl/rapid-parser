#include "twait.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    TWaitNode::TWaitNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TWaitNode::Execute()
    {
        //std::cout << toString().toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString TWaitNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("twait");
        str.append("(");
        str.append(_expression->toRaw());
        str.append(")");
        return str;
    }

    //QString TWaitNode::toString(uint level)
    //{
    //    QString str = "";
    //    for (int i = 0; i < level; i++)
    //    {
    //        str.append("    ");
    //    }
    //    //str.append("self.");
    //    str.append("twait");
    //    str.append("(");
    //    str.append(_expression->toString());
    //    str.append(")");
    //    return str;
    //}
}
