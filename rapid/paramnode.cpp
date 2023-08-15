#include "paramnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    ParamNode::ParamNode(ASTNode* expression):_expression(NULL),_param(expression)
    {

    }
    ParamNode::ParamNode(ASTNode* param,ASTNode* expression) : _param(param),_expression(expression)
    {

    }
    //ParamNode::ParamNode(QString* p1, QString* p2, ASTNode* expression):p1_name(p1),p2_name(p2), _expression(expression)
    //{

    //}

    //ParamNode::ParamNode(QString* p1, ASTNode* expression) : p1_name(p1), _expression(expression)
    //{

    //}
    QVariant ParamNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString ParamNode::toRaw(uint level)
    {
        QString str = "";
        if (_param)
        {
            str.append(_param->toRaw());
        }
        ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(_expression);
        if (nodes)
        {
            QString temp;
            for (auto node : *nodes)
            {
                temp.append("\\");
                temp.append(node->toRaw());
            }
            temp.replace("\"", "");
            str.append(temp);
        }

   /*     str.append(*p1_name);

        if (_expression)
        {
            QString temp;
            ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(_expression);
            if (nodes)
            {

                for (auto node : *nodes)
                {
                    temp.append("\\");
                    temp.append(node->toRaw());
                }
                temp.replace("\"", "");
            }
            str.append(temp);
        }*/
        return str;
    }
    QString ParamNode::toString(uint level)
    {
        QString str = "";
        str.append(_expression->toString());
    /*    str.append("\"");
        str.append(*p1_name);
       
        if(_expression)
        {
            QString temp;
            ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(_expression);
            if (nodes)
            {
             
                for (auto node:*nodes)
                {
                    temp.append("\\");
                    temp.append(node->toString());
                }
                
                temp.replace("\"","");
            }       
            str.append(temp);
        }

        str.append("\"");*/


        return str;
    }
}
