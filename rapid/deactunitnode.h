#ifndef DEACTUNITNODE_H
#define DEACTUNITNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport DeActUnitNode: public ASTNode
    {
    public:
        DeActUnitNode(/*QString* name, */ListNode<ASTNode>* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitDeActunit(this); }
        ListNode<ASTNode>* Arguments() const
        {
            return _arguments;
        }
        ListNode<ASTNode>* GetArguments() { return _arguments; }
    public:
        //QString _name;
        ListNode<ASTNode>* _arguments;
    };
}

#endif // ASSIGNMENTNODE_H
