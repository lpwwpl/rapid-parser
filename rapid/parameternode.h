#ifndef PARAMETERNODE_H
#define PARAMETERNODE_H

#include "astnode.h"

namespace Language
{
    class ParameterNode: public ASTNode
    {
    public:
        ParameterNode(int type, QString * name, ASTNode * initializer = nullptr);
        ParameterNode(QString* name, ASTNode* initializer = nullptr);
        QVariant Execute() override;
        QString Name();
        QString toString(uint level = 0) override;
    private:
        QString  _name;

        ASTNode * _initializer;
    };
}

#endif // PARAMETERNODE_H
