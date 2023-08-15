#ifndef WAITDINODE_H
#define WAITDINODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class WaitDiNode : public ASTNode
    {
    public:
        WaitDiNode(QString*  name,ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
