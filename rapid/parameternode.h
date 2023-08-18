#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport ParameterNode: public ASTNode
    {
    public:
        ParameterNode(IdentifierNode* type, IdentifierNode* param, ASTNode * initializer );
        ParameterNode(ASTNode* inout, IdentifierNode* type, IdentifierNode* param, ASTNode* initializer );
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        QString Name();
        void Accept(Visitor& v) override { v.VisitParamNode(this); }
    public:
        QString  _name;
        IdentifierNode* _param;
        IdentifierNode* _type;
        ASTNode* _INOUT;
        ASTNode * _initializer;
    };
}

#endif // PARAMETERNODE_H
