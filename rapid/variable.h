#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "astnode.h"
#include "dimnumnode.h"

enum enum_v_scope
{
    PERS = 1,
    TASK_PERS = 2,

    eCONST =3,
    VAR=4,

};

enum enum_v_type
{
    NUM =1,
    eBOOL =2,
    eSTRING=3,
    ROBTARGET=4,
    JOINTTARGET=5,
    WOBJDATA=6,
    ZONEDATA=7,
    SPEEDDATA=8,
    TOOLDATA=9,
    SEAMDATA = 10,
    WELDDATA = 11
};
namespace Language
{
    class VariableNode: public ASTNode
    {
    public:
        //QString* name
        VariableNode(int e_scope,int e_type, ASTNode* expression);
        //VariableNode(int e_scope, int e_type, QString* name, ASTNode*);
        VariableNode(int e_scope, int e_type, ASTNode*,ASTNode*);
        QVariant Execute() override;
        QString toString(uint level = 0) override;

    private:
        int _e_scope;
        int _e_type;
        QString _realVar;
        ASTNode* _dim_num_stm;
        ASTNode* _expression;
        QString* _name;
        
    };
}

#endif // ASSIGNMENTNODE_H
