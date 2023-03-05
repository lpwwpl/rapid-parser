#ifndef ARRAYDATANODE_H
#define ARRAYDATANODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    typedef std::vector<ASTNode*> dimRawType;
    class ArrayDataNode : public ASTNode
    {
    public:
   
        ArrayDataNode(ASTNode* caseexpr);
        dimRawType tempDimRawList;
        QVariant Execute() override;
        QString toString(uint level = 0) ;
    private:

    };
}

#endif // FUNCTIONCALLNODE_H
