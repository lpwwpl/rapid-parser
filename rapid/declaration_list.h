#ifndef DECLARELISTNODE_H
#define DECLARELISTNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class RobotAbbExport DeclareListNode : public ListNode<ASTNode>
    {
    public:
        DeclareListNode(ASTNode* caseexpr);
        QVariant Execute() override;
        QString toString(uint level = 0) ;
        QString toRaw(uint level = 0) override;
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
