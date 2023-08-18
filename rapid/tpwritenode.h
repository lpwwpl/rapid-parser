#ifndef TPWRITENODE_H
#define TPWRITENODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport TpWriteNode: public ASTNode
    {
    public:
        TpWriteNode(ASTNode* expression);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitTpwrite(this); }
    public:
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
