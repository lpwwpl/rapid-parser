#include "tpwritenode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    TpWriteNode::TpWriteNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant TpWriteNode::Execute()
    {
        std::cout << toString().toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString TpWriteNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("self.");
        str.append("twait");
        str.append("(");
        str.append(_expression->toString());
        str.append(")");
        return str;
    }
}
