#ifndef WAITDINODE_H
#define WAITDINODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class WaitDiNode : public ASTNode
    {
    public:
        WaitDiNode(QString*  name,ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitWaitDI(this); }
    public:
        QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
