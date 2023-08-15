#ifndef SETDONODE_H
#define SETDONODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class SetDoNode : public ASTNode
    {
    public:
        SetDoNode(ASTNode* name,ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        ASTNode* _name;
        ASTNode* _expression;

    };
}

#endif // ASSIGNMENTNODE_H
