#ifndef SETNODE_H
#define SETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class SetNode : public ASTNode
    {
    public:
        SetNode(ASTNode* expression = NULL);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitSet(this); }
    public:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
