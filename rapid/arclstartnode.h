#ifndef ARCLSTARTNODE_H
#define ARCLSTARTNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class ArcLStartNode: public ASTNode
    {
    public:
        ArcLStartNode(/*QString* name,*/ ListNode<ASTNode>* expression);
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
