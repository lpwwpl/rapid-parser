#ifndef SETDONODE_H
#define SETDONODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class SetDoNode : public ASTNode
    {
    public:
        SetDoNode(ASTNode* name,ASTNode* expression = NULL);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitSetDo(this); }
    public:
        ASTNode* _name;
        ASTNode* _expression;

    };
}

#endif // ASSIGNMENTNODE_H
