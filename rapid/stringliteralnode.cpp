#include "stringliteralnode.h"

namespace Language
{
    StringLiteralNode::StringLiteralNode(QString * value)
        : ASTNode("STRING"), bIsType(false)
    {
        _value = *value;// ->mid(1, value->length() - 2);
    }
    StringLiteralNode::StringLiteralNode(bool isType,QString* value)
        : ASTNode("STRING"),bIsType(isType)
    {
        if (bIsType)
        {
            _value = *value;
        }
        else
        {
            _value = value->mid(1, value->length() - 2);
        }
    }
    QVariant StringLiteralNode::Execute()
    {
        return _value;
    }
    QString StringLiteralNode::toRaw(uint level)
    {
        QString str = "";
        if (bIsType)
        {
            str.append("\"");
            str.append(_value);
            str.append("\"");
        }
        else
        {
            str.append(_value);
        }
        return str;
    }
    QString StringLiteralNode::toString(uint level)
    {
        QString str = "";
        if (bIsType)
        {
            str.append("\"");
            str.append(_value);
            str.append("\"");
        }
        else
        {
            str.append(_value);
        }
        return str;
    }
}

