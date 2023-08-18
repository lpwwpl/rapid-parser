#ifndef MOVEABSJNODE_H
#define MOVEABSJNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport MoveABSJNode: public ASTNode
    {
    public:
        MoveABSJNode(/*QString* name, */ListNode<ASTNode>* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitMoveAbsJ(this); }
        ListNode<ASTNode>* Arguments() const
        {
            return _arguments;
        }
        void compute() override;
        ListNode<ASTNode>* GetArguments() { return _arguments; }
    public:
        //QString _name;
        ListNode<ASTNode>* _arguments;
    };
}

#endif // ASSIGNMENTNODE_H
