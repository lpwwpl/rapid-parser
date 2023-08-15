#ifndef STRUCTINDEXNODE_H
#define STRUCTINDEXNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class StructIndexNode: public ASTNode
    {
    public:
        StructIndexNode(ASTNode* left, ASTNode* right);
        
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    public:
        ASTNode* _left;
        ASTNode* _right;
        QString _name;
    };
}

#endif // ASSIGNMENTNODE_H
