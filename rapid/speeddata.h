#ifndef SPEEDDATA_H
#define SPEEDDATA_H

#include "astnode.h"

enum eType
{
    eMM_S = 0,
    eMM_MIN =1,
    ePERcent = 2,
};
namespace Language
{
    class RobotAbbExport SpeedDataNode : public ASTNode
    {
    public:
        SpeedDataNode(ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    public:
        ASTNode* _expression;
 
    };
}

#endif // FUNCTIONCALLNODE_H
