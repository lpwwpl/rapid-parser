#ifndef PRINTNODE_H
#define PRINTNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport PrintNode: public ASTNode
    {
    public:
        PrintNode(ASTNode * expression);
        PrintNode(ASTNode* , ASTNode*);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override {}
    private:
            ASTNode * _expression;
            ASTNode* _target;
    };
}

#endif // PRINTNODE_H
