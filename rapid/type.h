#ifndef TYPENODE_H
#define TYPENODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport TypeNode : public ASTNode
    {
    public:
        TypeNode(ASTNode* expression);
        QVariant Execute() override;
        void Accept(Visitor& v) override {v.VisitT}
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
