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
        void Accept(Visitor& v) override { v.VisitModule(this); }
        void compute() override;
        ListNode<ASTNode>* Arguments() const
        {
            return _body;
        }
        ListNode<ASTNode>* GetArguments() { return _body; }
    public:
        QString _name;
        ListNode<ASTNode>* _body;
    };
}

#endif // ASSIGNMENTNODE_H
