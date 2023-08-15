#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H

#include "astnode.h"

namespace Language
{
    class RobotAbbExport ParameterNode: public ASTNode
    {
    public:
        ParameterNode(ASTNode* type, QString * name, ASTNode * initializer = nullptr);
        ParameterNode(ASTNode* inout,ASTNode* type,QString* name, ASTNode* initializer = nullptr);
        QVariant Execute() override;
        QString Name();
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
        QString  _name;
        ASTNode* _type;
        ASTNode* _INOUT;
        ASTNode * _initializer;
    };
}

#endif // PARAMETERNODE_H
