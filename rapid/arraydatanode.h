#ifndef ARRAYDATANODE_H
#define ARRAYDATANODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
   // typedef std::vector<ASTNode*> dimRawType;
    class RobotAbbExport ArrayDataNode : public ASTNode
    {
    public:
   
        ArrayDataNode(ASTNode* caseexpr);
       // dimRawType tempDimRawList;
        QString toRaw(uint level = 0);
        QVariant Execute() override;
        QString toString(uint level = 0) ;
    public:
        ASTNode* _child;
    };
}

#endif // FUNCTIONCALLNODE_H
