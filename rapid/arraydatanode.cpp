#include "arraydatanode.h"

#include "symboltable.h"
#include "errors.h"
#include "casenode.h"

namespace Language
{
    ArrayDataNode::ArrayDataNode(ASTNode* caseexpr)
    {

        tempDimRawList.push_back(caseexpr);
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

    QString ArrayDataNode::toString(uint level)
    {
        QString str = "";
        for(auto it:tempDimRawList)
            str.append(it->toString());
        return str;
    }
}
