#include "wobjdatanode.h"
#include "symboltable.h"
#include "errors.h"



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
