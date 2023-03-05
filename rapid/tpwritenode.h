#ifndef TPWRITENODE_H
#define TPWRITENODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class TpWriteNode: public ASTNode
    {
    public:
        TpWriteNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
