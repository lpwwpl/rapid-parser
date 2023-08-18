#ifndef SWITCHCASELISTNODE_H
#define SWITCHCASELISTNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class RobotAbbExport SWitchCaseListNode : public ListNode<ASTNode>
    {
    public:
        SWitchCaseListNode(ASTNode* caseexpr);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitSwitchCase(this); }
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
