#ifndef PULSEDONODE_H
#define PULSEDONODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class PulseDONode : public ASTNode
    {
    public:
        PulseDONode(ASTNode* expression = NULL);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
