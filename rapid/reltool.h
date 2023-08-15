#ifndef RELTOOLNODE_H
#define RELTOOLNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RelToolNode : public ASTNode
    {
    public:
        RelToolNode(ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        //QString _name;
        ASTNode* _expression;
    };
}
#endif