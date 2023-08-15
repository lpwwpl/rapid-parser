#include "numberliteralnode.h"

namespace Language
{
    NumberLiteralNode::NumberLiteralNode(double value)
        : ASTNode("NUM"),
          _value(value)
    {
    }

    QVariant NumberLiteralNode::Execute()
    {
        return QString("%1").arg(_value);
    }

    QString NumberLiteralNode::toRaw(uint level)
    {
        return QString::number(_value,'g');
    }
    QString NumberLiteralNode::toString(uint level)
    {
        return QString::number(_value,'g');
    }
}

