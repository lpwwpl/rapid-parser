#include "setdo.h"
#include "symboltable.h"
#include "errors.h"



namespace Language
{
    SetDoNode::SetDoNode(ASTNode* name,ASTNode* dim/*dimListType* dim*/) :_name(name),_expression(dim)
    {

    }

    QVariant SetDoNode::Execute()
    {
        signalRunInst();
        return QVariant();
        //return ASTNode::Execute();
    }
    QString SetDoNode::toRaw(uint level)
    {

        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append(INTENT);
        }
        str.append("SetDo ");
        str.append(_name->toRaw());
        str.append(",");
        str.append(_expression->toRaw());
        str.append(";");
        return str;
    }
}
