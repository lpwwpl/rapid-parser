#ifndef FUNCTIONNODE_H
#define FUNCTIONNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport FunctionNode: public ASTNode
    {
    public:
        FunctionNode(ASTNode* type, QString * name, ListNode<ParameterNode> * arguments, StatementListNode * body);
        QVariant Execute() override;
        ListNode<ParameterNode> * Arguments() const ;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
        StatementListNode* GetBody() { return _body; }
        ListNode<ParameterNode>* GetArguments() { return _arguments; }
        QString GetName() { return _name; }
        void compute() override;
    public:
        ListNode<ParameterNode> * _arguments;
        StatementListNode * _body;
        QString _name;
        ASTNode* _type;
    };
}

#endif // FUNCTIONNODE_H
