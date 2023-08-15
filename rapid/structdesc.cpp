#include "structdesc.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;

namespace Language
{
    StructDescNode::StructDescNode(QString * name, ListNode<ASTNode> * arguments)
            : ASTNode(),
              _name(*name),
              _arguments(arguments)
    {
         SymbolTable::Instance().DefineTypes(name->toStdString());
    }
    void StructDescNode::compute()
    {

    }
    QVariant StructDescNode::Execute()
    {


        return QVariant();
    }

    QString StructDescNode::toRaw(uint level)
    {
        QString str = QString::fromLatin1("");
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("RECORD");
        str += QString::fromLatin1(SPACE);
        str += _name;
        str += QString::fromLatin1("\n");
        //str += INTENT;
        //str += _arguments->toString();
        str.append(_arguments->toRaw(level + 1));
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("ENDRECORD");
        str += QString::fromLatin1("\n");
        return str;
    }

    QString StructDescNode::toString(uint level)
    {
        QString str = QString::fromLatin1("");
        for (int i = 0; i < level; i++)
        {
            str.append(QString::fromLatin1("    "));
        }
        str += QString::fromLatin1("class");
        str += QString::fromLatin1(SPACE);
        str += _name;
        str += QString::fromLatin1(":");
        str += INTENT;
        str += QString::fromLatin1("def __init__(self):");
        str += QString::fromLatin1("\n");
        str.append(_arguments->toString(level+2));
        str += QString::fromLatin1("\n");
        return str;
    }
}

