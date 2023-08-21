#include "tooldatanode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    ToolDataNode::ToolDataNode(QString* name) :ASTNode(), _name(*name)
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
}
