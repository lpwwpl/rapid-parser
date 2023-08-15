#include "arraydatanode.h"

#include "symboltable.h"
#include "errors.h"
#include "casenode.h"

namespace Language
{
    ArrayDataNode::ArrayDataNode(ASTNode* caseexpr): _child(caseexpr)
    {

        //tempDimRawList.push_back(caseexpr);
    }

    QVariant ArrayDataNode::Execute()
    {
        //for (auto statement : *this)
        //{
        //    statement->Execute();
        //    if (dynamic_cast<NumberLiteralNode*>(statement))
        //        break;
        //}

        return ASTNode::Execute();
    }
    QString ArrayDataNode::toRaw(uint level)
    {
        QString str = "";
        str.append(_child->toRaw());
        return str;
    }
    QString ArrayDataNode::toString(uint level)
    {
        QString str = "";
        str.append(_child->toString());
        return str;
    }
}
