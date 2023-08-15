#ifndef OFFSNODE_H
#define OFFSNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class OffsNode : public ASTNode
    {
    public:
        OffsNode(ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        //QString _name;
        ASTNode* _expression;
    };
}
#endif