#include "assignmentnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    JointTargetNode::JointTargetNode(QString* name) : _name(*name)
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
    QString JointTargetNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }



        return "";
    }
}
