#ifndef STRUCTDESCNODE_H
#define STRUCTDESCNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport StructDescNode: public ASTNode
    {
    public:
        StructDescNode(IdentifierNode* id, ListNode<ASTNode> * arguments);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        enum_v_type getType() override { return enum_v_type::klass; }
        void Accept(Visitor& v) override { v.VisitStructDeclaration(this); }
        QString GetName() { return _name; }
        void compute() override;
    public:
        ListNode<ASTNode> * _arguments;
        IdentifierNode* _id;
        QString _name;
    };
}

#endif // FUNCTIONNODE_H
