#include "wobjdatanode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    WobjDataNode::WobjDataNode(QString* name/*, ListNode<ParameterNode>* arguments*/):ASTNode(), _name(*name)/*,
        _arguments(arguments)*/
    {

    }


    QVariant WobjDataNode::Execute()
    {


        return ASTNode::Execute();
    }
    QString WobjDataNode::toRaw(uint level)
    {
        QString str = "";
        return str;
    }
}
