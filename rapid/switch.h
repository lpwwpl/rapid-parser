#ifndef SWITCHNODE_H
#define SWITCHNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport SWitchNode: public ASTNode
    {
    public:
        SWitchNode(ASTNode * expression, ASTNode * caseLists, ASTNode * defaultCase = nullptr);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitSwitch(this); }
    public:
            ASTNode * _caseLists;
            ASTNode * _defaultCase;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
