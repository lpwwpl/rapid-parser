#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "astnode.h"
#include "dimnumnode.h"

enum enum_v_scope
{
    PERS = 0,
    TASK_PERS = 1,

    eCONST =2,
    VAR=3,

};


namespace Language
{
    class RobotAbbExport VariableNode: public ASTNode
    {
    public:
        //QString* name
        VariableNode(int e_scope, ASTNode* e_type, ASTNode* expression);
        VariableNode(int e_scope, ASTNode* e_type, ASTNode* src, ASTNode* expression);
        //VariableNode(int e_scope, int e_type, QString* name, ASTNode*);
        //VariableNode(int e_scope, ASTNode* e_type, ASTNode*,ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    public:
        int _e_scope;
        ASTNode* _e_type;
        ASTNode* _src;
        //ASTNode* _dim_num_stm;
        ASTNode* _expression;
        QString _name;
        
    };
}

#endif // ASSIGNMENTNODE_H
