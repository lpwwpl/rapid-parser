#include "assignmentnode.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    JointTargetNode::JointTargetNode(QString* name) : ASTNode(), _name(*name)
    {

    }


    QVariant JointTargetNode::Execute()
    {


        return ASTNode::Execute();
    }
    QString JointTargetNode::toRaw(uint level)
    {
        QString str = "";
        return str;
    }
}
