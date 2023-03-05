#include "elseifnode.h"

namespace Language
{
    ElseIfNode::ElseIfNode(ASTNode * expression, ASTNode * bodyTrue)
        : _body(bodyTrue),
          _expression(expression)
    {
    }
    ElseIfNode::ElseIfNode( ASTNode* bodyTrue)
        : _body(bodyTrue)
    {
    }


    QVariant ElseIfNode::Execute()
    {
       /* if (nullptr == _bodyFalse)
        {
            if ( _expression->Execute().toBool())
            {     
                _bodyTrue->Execute();
            }
        }
        else
        {
            if (_expression->Execute().toBool())
            {
                _bodyTrue->Execute();
            }
            else
            {
                _bodyFalse->Execute();
            }*/
        //}
        return ASTNode::Execute();
    }

    QString ElseIfNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("if");
        str.append(" ");
        str.append(_expression->toString());
        str.append(":");
        str.append("\n");
       /* if (!_bodyTrue)
        {
            for (int i = 0; i < level + 1; i++)
            {
                str.append("    ");
            }
            str.append("pass");
            str.append("\n");
        }
        else
        {
            str.append(_bodyTrue->toString(level + 1));
        }
       
        if (_bodyFalse)
        {
          
            for (int i = 0; i < level; i++)
            {
                str.append("    ");
            }
            str.append("else:");
            
            str.append("\n");    
            str.append(_bodyFalse->toString(level + 1));            
        }*/
        return str; 
    }
}
