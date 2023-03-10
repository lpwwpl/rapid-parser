#ifndef ELSEIFNODE_H
#define ELSEIFNODE_H

#include "astnode.h"

namespace Language
{
    class ElseIfNode: public ASTNode
    {
    public:
        ElseIfNode(ASTNode* body);
        ElseIfNode(ASTNode * expression, ASTNode * body);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
            ASTNode * _body;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
