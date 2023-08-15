#include "tooldatanode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    ToolDataNode::ToolDataNode(QString* name) : _name(*name)
    {

    }


    QVariant ToolDataNode::Execute()
    {


        return ASTNode::Execute();
    }
    QString ToolDataNode::toRaw(uint level)
    {
        QString str = "";
        return str;
    }
    QString ToolDataNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }



        return "";
    }
}
