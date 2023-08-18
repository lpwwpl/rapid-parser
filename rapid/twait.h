#ifndef TWAITNODE_H
#define TWAITNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport TWaitNode : public ASTNode
    {
    public:
        TWaitNode(ASTNode* expression);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override {}
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
