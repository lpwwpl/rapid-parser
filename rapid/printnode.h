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
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level);
    private:
            ASTNode * _expression;
            ASTNode* _target;
    };
}

#endif // PRINTNODE_H
