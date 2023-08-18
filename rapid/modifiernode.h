#ifndef MODIFIERNODE_H
#define MODIFIERNODE_H

#include "astnode.h"
#include "dimnumnode.h"


namespace Language
{
    class RobotAbbExport ModifierNode: public ASTNode
    {
    public:
        //QString* name
        ModifierNode(ASTNode* left, ASTNode* right);
        ModifierNode(ASTNode* left);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override { v.VisitModifier(this); }
    public:
        ASTNode* _left;
        ASTNode* _right;
        QString* _name;
        
    };
}

#endif // ASSIGNMENTNODE_H
