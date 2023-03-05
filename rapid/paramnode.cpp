#include "paramnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    ParamNode::ParamNode(QString* p1):p1_name(p1), _expression(NULL)
    {

    }
    //ParamNode::ParamNode(QString* p1, QString* p2, ASTNode* expression):p1_name(p1),p2_name(p2), _expression(expression)
    //{

    //}

    ParamNode::ParamNode(QString* p1, ASTNode* expression) : p1_name(p1), _expression(expression)
    {

    }
    QVariant ParamNode::Execute()
    {
        return ASTNode::Execute();
    }
    QString ParamNode::toString(uint level)
    {
        QString str = "";
        str.append(*p1_name);
        if(_expression)
        {
           
            ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(_expression);
            if (nodes)
            {
             
                for (auto node:*nodes)
                {
                    str.append("\\");
                    str.append(node->toString());
                }
            }
             
        }



        return str;
    }
}
