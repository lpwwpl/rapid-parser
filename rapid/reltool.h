#ifndef RELTOOLNODE_H
#define RELTOOLNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RelToolNode : public ASTNode
    {
    public:
        RelToolNode(ASTNode* expression = NULL);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitRelTool(this); }
    public:
        //QString _name;
        ASTNode* _expression;
    };
}
#endif