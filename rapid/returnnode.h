#ifndef RETURNNODE_H
#define RETURNNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport ReturnNode: public ASTNode
    {
    public:
        ReturnNode(ASTNode * expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
            ASTNode * _expression;
    };
}

#endif // RETURNNODE_H
