#ifndef MODULENODE_H
#define MODULENODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class ModuleNode: public ASTNode
    {
    public:
        ModuleNode(QString* name, ListNode<ASTNode>* body);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        ListNode<ASTNode>* Arguments() const
        {
            return _body;
        }
        ListNode<ASTNode>* GetArguments() { return _body; }
    private:
        QString _name;
        ListNode<ASTNode>* _body;
    };
}

#endif // ASSIGNMENTNODE_H
