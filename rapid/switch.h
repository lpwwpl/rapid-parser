#ifndef SWITCHNODE_H
#define SWITCHNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport SWitchNode: public ASTNode
    {
    public:
        SWitchNode(ASTNode * expression, ASTNode * caseLists, ASTNode * defaultCase = nullptr);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
            ASTNode * _caseLists;
            ASTNode * _defaultCase;
            ASTNode * _expression;
    };
}

#endif // IFNODE_H
