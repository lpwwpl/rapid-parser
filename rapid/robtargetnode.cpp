#include "robtargetnode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    RobTargetNode::RobTargetNode(QString* name) : _name(*name)
    {

    }

    QVariant RobTargetNode::Execute()
    {     


        return ASTNode::Execute();
    }
    
    QString RobTargetNode::toString(uint level )
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }



        return str;
    }
}
