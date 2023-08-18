#ifndef ARCCNODE_H
#define ARCCNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport ArccNode: public ASTNode
    {
    public:
        ArccNode(/*QString* name, */ListNode<ASTNode>* expression);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) { v.VisitArcc(this); }
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
