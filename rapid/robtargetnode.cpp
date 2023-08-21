#include "robtargetnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    RobTargetNode::RobTargetNode(QString* name) :ASTNode(), _name(*name)
    {

    }

    QVariant RobTargetNode::Execute()
    {     


        return ASTNode::Execute();
    }
    QString RobTargetNode::toRaw(uint level)
    {
        QString str = "";
        return str;
    }
}
