#ifndef ARCUNITNODE_H
#define ARCUNITNODE_H

#include "astnode.h"
#include "dimnumnode.h"

namespace Language
{
    class RobotAbbExport ActUnitNode: public ASTNode
    {
    public:
        ActUnitNode(/*QString * name,*/ ListNode<ASTNode>* expression);
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitActUnit(this); }
        QString toRaw(uint level = 0) override;
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
