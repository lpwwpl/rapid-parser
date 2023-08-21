#include "modifiernode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    ModifierNode::ModifierNode(ASTNode* left, ASTNode* right) :ASTNode(), _left(left), _right(right)
    {

        

    }
    ModifierNode::ModifierNode(ASTNode* left) :ASTNode(), _left(left),_right(NULL)
    {



    }

    QVariant ModifierNode::Execute()
    {


        return ASTNode::Execute();
    }
    QString ModifierNode::toRaw(uint level)
    {
        QString str = "";
        //for (int i = 0; i < level; i++)
        //{
        //    str.append(INTENT);
        //}
        //
        str.append(_left->toRaw());
        if (_right)
        {
            //str.append("\\");
            str.append(_right->toRaw());
        }
       
        return str;
    }
}
