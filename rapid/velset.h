#ifndef VELSETNODE_H
#define VELSETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class VelSetNode : public ASTNode
    {
    public:
        VelSetNode(ASTNode* expression1 = NULL, ASTNode* expression2=NULL);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitVelset(this); }
    public:
        //QString _name;
        ASTNode* _expression1;
        ASTNode* _expression2;
    };
}

#endif // ASSIGNMENTNODE_H
