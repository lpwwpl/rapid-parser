#ifndef ARCLSTARTNODE_H
#define ARCLSTARTNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport ArcLStartNode: public ASTNode
    {
    public:
        ArcLStartNode(/*QString* name,*/ ListNode<ASTNode>* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitArclStart(this); }
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
