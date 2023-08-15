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
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    public:
        ASTNode* _left;
        ASTNode* _right;
        QString* _name;
        
    };
}

#endif // ASSIGNMENTNODE_H
