#ifndef ARCUNITNODE_H
#define ARCUNITNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class ActUnitNode: public ASTNode
    {
    public:
        ActUnitNode(/*QString * name,*/ ListNode<ASTNode>* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        ListNode<ASTNode>* Arguments() const
        {
            return _arguments;
        }
        ListNode<ASTNode>* GetArguments() { return _arguments; }
    private:
         //QString _name;
         ListNode<ASTNode>* _arguments;
    };
}

#endif // ASSIGNMENTNODE_H
