#ifndef RESETNODE_H
#define RESETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class ReSetNode : public ASTNode
    {
    public:
        ReSetNode(ASTNode* expression = NULL);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitReset(this); }
    public:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
