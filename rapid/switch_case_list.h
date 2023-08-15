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
        QVariant Execute() override;
        QString toString(uint level = 0) ;
        QString toRaw(uint level);
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
