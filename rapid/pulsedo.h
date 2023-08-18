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
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitPulseDO(this); }
    public:
        //QString _name;
        ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
