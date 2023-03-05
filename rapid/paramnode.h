#ifndef PARAMNODE_H
#define PARAMNODE_H

#include "astnode.h"

namespace Language
{
    class ParamNode : public ASTNode
    {
    public:
        ParamNode(QString* p1);
      //  ParamNode(QString* p1, QString* p2,ASTNode*);
        ParamNode(QString* p1,  ASTNode*);

        QVariant Execute() override;
        QString toString(uint level = 0) override;
    private:
        QString* p1_name;
       // QString* p2_name;

        ASTNode* _expression;

    };
}

#endif // FUNCTIONCALLNODE_H
