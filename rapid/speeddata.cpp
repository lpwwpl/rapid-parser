#include "speeddata.h"

#include "symboltable.h"
#include "errors.h"
#include <QVector>
namespace Language
{
    SpeedDataNode::SpeedDataNode(ASTNode* expression)
        : ASTNode(), _expression(expression)
    {
    }

    QVariant SpeedDataNode::Execute()
    {
        QVariant v = _expression->Execute();
        QString str = "";
        str.append("speed");
        str.append(" ");
        str.append(v.toString());

        std::cout << str.toStdString() << std::endl;
        return ASTNode::Execute();
    }
    QString SpeedDataNode::toRaw(uint level)
    {
        QString str = "";
        return str;
    }

    //QString SpeedDataNode::toString(uint level)
    //{
    //    QString str = "";
    //    for (int i = 0; i < level; i++)
    //    {
    //        str.append("    ");
    //    }
    //    //str.append("self.");
    //    str.append("speed");

    //    str.append("(");
    //    str.append("\"");
    //    str.append(_expression->toString());
    //    str.append("\"");
    //    str.append(")");
    //    return str;
    //}
}
