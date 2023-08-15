#include "identifiernode.h"
#include "symboltable.h"

namespace Language
{
    IdentifierNode::IdentifierNode(QString * name) : _name(*name)
    {
        _type = SymbolTable::Instance().VariableType(*name);
        _prefix = true;
        
        if (_name.startsWith("."))
        {
            _prefix = false;
        }
    }

    QVariant IdentifierNode::Execute()
    {
        //std::cout << toString().toStdString() << std::endl;
        //QVariant v = SymbolTable::Instance().GetVariableValue(_name).value;
        //if (v.isValid())
        //    return v;
        //return SymbolTable::Instance().GetActivationRecord()->GetVariableValue(_name);
        try
        {
            if (SymbolTable::Instance().GetActivationRecord())
            {
                QVariant v = SymbolTable::Instance().GetActivationRecord()->GetVariableValue(_name);
                return v;
            }
            else
            {
                return toString();
            }

        }
        catch (...)
        {
            return toString();
        }
        
    }
    QString IdentifierNode::toRaw(uint level)
    {
        QString str = "";
        str.append(_name);
        return str;
    }
    QString IdentifierNode::toString(uint level)
    {
        QString str = "";


        QString temp = _name;
        if (_name.startsWith("#"))
        {           
            temp.replace(0, 1, "_");           
        }
        if (_name.startsWith("$"))
        {
            str.replace(0, 1, "");
        }
        if (_prefix)
            ;
            ///*s*/tr.append("kdata.");
        else
        {
            temp.replace(0, 1, "");
        }

        str.append(temp);
        return str;
    }
}
