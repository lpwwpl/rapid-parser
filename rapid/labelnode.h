#ifndef LABELNODE_H
#define LABELNODE_H

#include "astnode.h"
#include "listnode.h"

namespace Language
{
class RobotAbbExport LabelNode: public ASTNode
{
public:
    ASTNode* _id;

    public:
        LabelNode(ASTNode * id);
        QVariant Execute() override;
        QString toString(uint level = 0) ;
        QString toRaw(uint level = 0) override;
    };
}

#endif // STATEMENTLISTNODE_H
