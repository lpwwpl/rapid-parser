#include "casenode.h"

namespace Language
{
    CaseNode::CaseNode(ASTNode * expression, ASTNode * body)
        : _body(body),
          _expression(expression)
    {
    }

    QVariant CaseNode::Execute()
    {
        if (_body)
        {
            return _body->Execute();            
        }
            
        else 
            return  ASTNode::Execute();
    }
    QString CaseNode::toRaw(uint level)
    {
        QString str = "";
        str.append(_body->toRaw(level));
        return str;
    }
}
