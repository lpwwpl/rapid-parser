#ifndef VARIABLEDECLARENODE_H
#define VARIABLEDECLARENODE_H

#include "astnode.h"
#include "dimnumnode.h"


namespace Language
{
    class RobotAbbExport VariableDeclareNode: public ASTNode
    {
    public:
        //QString* name
        VariableDeclareNode(ASTNode* e_type, ASTNode* expression);

        QVariant Execute() override;
        void Accept(Visitor& v) override {}
    public:
        ASTNode* _type;
        ASTNode* _expression;
        QString* _name;
        
    };
}

#endif // ASSIGNMENTNODE_H
