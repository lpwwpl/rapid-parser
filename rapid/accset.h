#ifndef ACCSETNODE_H
#define ACCSETNODE_H

#include "astnode.h"

namespace Language
{
    class AccSetNode : public ASTNode
    {
    public:
        AccSetNode(ASTNode* expression1 = NULL, ASTNode* expression2 = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        //QString _name;
        ASTNode* _expression1;
        ASTNode* _expression2;
    };
}

#endif // ASSIGNMENTNODE_H
