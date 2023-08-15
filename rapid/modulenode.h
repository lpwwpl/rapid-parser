#ifndef MODULENODE_H
#define MODULENODE_H

#include "astnode.h"
#include "dimnumnode.h"
#include "PreCompiled.h"
namespace Language
{
    class RobotAbbExport ModuleNode: public ASTNode
    {
    public:
        ModuleNode(QString* name, ListNode<ASTNode>* body);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        QString toString(uint level = 0) override;
        void compute() override;
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
