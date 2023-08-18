#ifndef MOVEJNODE_H
#define MOVEJNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport MoveJNode: public ASTNode
    {
    public:
        MoveJNode(/*QString* name,*/ ListNode<ASTNode>* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitMoveJ(this); }
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
