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
        std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString TpWriteNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        //str.append("self.");
        str.append("TPWrite");
        str.append(" ");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }    
}
