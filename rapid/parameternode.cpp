#include "parameternode.h"

#include "symboltable.h"

namespace Language
{
    ParameterNode::ParameterNode(ASTNode* inout,ASTNode* type, QString* name, ASTNode* initializer):
        _INOUT(inout),
        _type(type),
        _name(*name),
        _initializer(initializer)
    {
        StringLiteralNode* s_type = (StringLiteralNode*)(_type);
        if (nullptr == initializer)
        {

            if ("NUM" == s_type->_value)
                _initializer = new NumberLiteralNode(0);
            if ("STRING" == s_type->_value)
                _initializer = new StringLiteralNode(new QString());
        }
        SymbolTable::Instance().DefineVariable(&_name, s_type->_value);
    }

    ParameterNode::ParameterNode(ASTNode* type, QString * name, ASTNode * initializer)
            : _INOUT(nullptr),_type(type),
                _name(*name),
            _initializer(initializer)
    {
        StringLiteralNode* s_type = (StringLiteralNode*)(_type);
        if (nullptr == initializer)
        {

            if ("NUM" == s_type->_value)
                _initializer = new NumberLiteralNode(0);
            if ("STRING" == s_type->_value)
                _initializer = new StringLiteralNode(new QString());
        }
        SymbolTable::Instance().DefineVariable(&_name, s_type->_value);
    }

    QVariant ParameterNode::Execute()
    {
        SymbolTable::Instance().GetActivationRecord()->DeclareVariable(_name);
        if (nullptr != _initializer)
            SymbolTable::Instance().GetActivationRecord()->AssignVariable(_name, _initializer->Execute());
        return ASTNode::Execute();
    }

    QString ParameterNode::Name()
    {
        return _name;
    }

    QString ParameterNode::toString(uint level)
    {
        QString ret;
        if (_INOUT)
        {
            ret += "INOUT";
        }
        ret += " ";
        StringLiteralNode* s_type = (StringLiteralNode*)(_type);
        ret += s_type->_value;
        ret += " ";
        ret += _name;
        return ret;
    }
    QString ParameterNode::toRaw(uint level)
    {
        QString ret;
        if (_INOUT)
        {
            ret += "INOUT";
        }
        ret += " ";
        StringLiteralNode* s_type = (StringLiteralNode*)(_type);
        ret += s_type->_value;
        ret += " ";
        ret += _name;
        return ret;
    }

}

