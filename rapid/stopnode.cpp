#include "stopnode.h"

#include "symboltable.h"
#include "errors.h"

namespace Language
{
    StopNode::StopNode(ASTNode* expression)
        : _expression(expression)
    {
    }

    QVariant StopNode::Execute()
    {
        //std::cout << QString("%1").arg("stop").toStdString() << std::endl;
        //std::cout << QString("%1").arg(_expression->Execute().toString()).toStdString() << std::endl;
        signalRunInst();
        return ASTNode::Execute();
    }
    QString StopNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append("stop;");
        return str;
    }
}
