#ifndef STRINGLITERALNODE_H
#define STRINGLITERALNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport StringLiteralNode : public ASTNode
    {
    public:
        StringLiteralNode(QString * value);
        StringLiteralNode(bool,QString* value);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    public:
        QString _value;
        bool bIsType;
    };
}


#endif // STRINGLITERALNODE_H
