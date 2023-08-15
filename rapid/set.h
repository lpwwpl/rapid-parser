#ifndef SETNODE_H
#define SETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class SetNode : public ASTNode
    {
    public:
        SetNode(ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
