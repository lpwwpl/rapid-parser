#include "astnode.h"


namespace Language
{
    ASTNode::ASTNode(QString type)
        :_type(type), _prefix(true)
    {
    }
    
    QVariant ASTNode::Execute()
    {
        return QVariant();
    }
    QString ASTNode::toString(uint level)
    {
        return QString("");
    }
    QString ASTNode::toRaw(uint level)
    {
        return toString(level);
    }

    ASTNode::~ASTNode()
    {
    }

    QString ASTNode::Type()
    {
        return _type;
    }
}
