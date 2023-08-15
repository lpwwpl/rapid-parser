#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class RobotAbbExport IdentifierNode : public ASTNode
    {
    public:
        IdentifierNode(QString * name);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0);
    public:
        QString _name;
        //bool isType = false;
    };
}

#endif // IDENTIFIERNODE_H
