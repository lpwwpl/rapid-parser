#ifndef WAITTIMENODE_H
#define WAITTIMENODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class WaitTimeNode : public ASTNode
    {
    public:
        WaitTimeNode(ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitWaittime(this); }
    public:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
