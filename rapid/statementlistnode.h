#ifndef STATEMENTLISTNODE_H
#define STATEMENTLISTNODE_H

#include "astnode.h"
#include "listnode.h"

namespace Language
{
class RobotAbbExport StatementListNode: public ListNode<ASTNode>
{
    public:
        StatementListNode(ASTNode * parameter);
        QVariant Execute() override;
        void compute() override;
        QString toString(uint level = 0) ;
        QString toRaw(uint level = 0) override;
    };
}

#endif // STATEMENTLISTNODE_H
