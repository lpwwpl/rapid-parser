#ifndef CASENODE_H
#define CASENODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport CaseNode: public ASTNode
    {
    public:
        CaseNode(ASTNode * expression, ASTNode * body);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitCase(this); }
    public:
        ASTNode* _expression;

    public:
            ASTNode * _body;


            //ASTNode* _var;
    };
}

#endif // IFNODE_H
