#ifndef OFFSNODE_H
#define OFFSNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class OffsNode : public ASTNode
    {
    public:
        OffsNode(ASTNode* expression = NULL);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitOffs(this); }
    public:
        //QString _name;
        ASTNode* _expression;
    };
}
#endif