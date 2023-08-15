#include "offsnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    OffsNode::OffsNode(ASTNode* dim/*dimListType* dim*/) :_expression(dim)
    {

    }

    QVariant OffsNode::Execute()
    {

        return QVariant();
        //return ASTNode::Execute();
    }
    QString OffsNode::toRaw(uint level)
    {

        QString str = "";
        str.append("Offs");
        //str.append(_name);
        str.append("(");
        ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(_expression);
        if (nodes)
        {
            QString temp;
            int count = nodes->size();
            for (int i=0;i<count;i++)
            {
                auto node = nodes->at(i);
                temp.append(node->toRaw());
                if (i == (count - 1))
                    ;
                else
                    temp.append(",");
            }
            str.append(temp);
        }
        str.append(")");
        return str;
    }

    QString OffsNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("Offs ");
        //str.append(_name);
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
