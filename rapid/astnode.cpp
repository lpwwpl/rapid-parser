#include "astnode.h"

#include "listnode.h"

namespace Language
{

    ASTNode::ASTNode()
        : _prefix(true)
    {
    }
    
    QVariant ASTNode::Execute()
    {
        return QVariant();
    }


    ASTNode::~ASTNode()
    {
    }



    ParamWithModifierNode::ParamWithModifierNode(ASTNode* expression, ListNode<ASTNode>* dim) :ASTNode(), _var_expr(expression), _dimRawType(dim)
    {
       // _dimRawType.push_back(expression);
        //NumberLiteralNode* node = dynamic_cast<NumberLiteralNode*>(expression);
        //if (node)
        //{
        //    //tempDimList.push_back(node->Execute().toInt());
        //    tempDimRawList.push_back(node);
        //    return;
        //}
        //IdentifierNode* id_node = dynamic_cast<IdentifierNode*>(expression);
        //if(id_node)
        //{
        //    tempDimRawList.push_back(id_node);
        //    //tempDimList.push_back(id_node->Execute().toInt());
        //}
        //OperatorNode* opNode = dynamic_cast<OperatorNode*>(expression);
        //if (opNode)
        //{
        //    tempDimRawList.push_back(opNode);
        //}

    }

    QVariant ParamWithModifierNode::Execute()
    {
        QString str;// = toString();
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return str;
    }

    QString ParamWithModifierNode::toRaw(uint level)
    {
        QString str = "";
        str += _var_expr->toRaw(level);
        for (auto stm : *_dimRawType)
        {
            str.append(stm->toRaw(0));
        }
        return str;
    }

}
