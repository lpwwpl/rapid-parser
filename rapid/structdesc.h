#ifndef STRUCTDESCNODE_H
#define STRUCTDESCNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport StructDescNode: public ASTNode
    {
    public:
        StructDescNode( QString * name, ListNode<ASTNode> * arguments);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
        QString GetName() { return _name; }
        void compute() override;
    public:
        ListNode<ASTNode> * _arguments;
        QString _name;
    };
}

#endif // FUNCTIONNODE_H
