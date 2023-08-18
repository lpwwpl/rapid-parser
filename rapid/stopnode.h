#ifndef STOPNODE_H
#define STOPNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport StopNode : public ASTNode
    {
    public:
        StopNode(ASTNode* expression);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitStop(this); }
    private:
        ASTNode* _expression;
    };
}

#endif // FUNCTIONCALLNODE_H
