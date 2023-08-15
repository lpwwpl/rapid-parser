#ifndef PARAMNODE_H
#define PARAMNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport ParamNode : public ASTNode
    {
    public:
        ParamNode(ASTNode* expression);
        ParamNode(ASTNode* param, ASTNode* expression);
      //  ParamNode(QString* p1, QString* p2,ASTNode*);
        //ParamNode(ASTNode* p1,  ASTNode*);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level);
    public:
        ASTNode* _param;
       // QString* p2_name;
        //ASTNode* _type;
        ASTNode* _expression;

    };
}

#endif // FUNCTIONCALLNODE_H
