#include "parameternode.h"

#include "symboltable.h"


namespace Language
{

    ParameterNode::ParameterNode(ASTNode* inout, IdentifierNode* type, IdentifierNode* param, ASTNode* initializer):
        _INOUT(inout),
        _type(type),
        _param(param),
        _initializer(initializer)
    {
        //ModuleNode* module = dynamic_cast<ModuleNode*>(ast_scope);
        //if (module)
        //{
        //    isGlobal = true;
        //}
        //else
        //    isGlobal = false;

        if (nullptr == initializer)
        {

            if ("NUM" == type->getVariablenTypeName())
                _initializer = new NumberLiteralNode(0);
            if ("STRING" == type->getVariablenTypeName())
                _initializer = new StringLiteralNode(new QString());
        }
        //VariableRecord vr = SymbolTable::Instance().GetVariableValue(param->_name);
        //if(vr.var_type=="")
        SymbolTable::Instance().DefineVariable(&param->_name.toLower(), type->getType(),type->getVariablenTypeName());
    }

    ParameterNode::ParameterNode(IdentifierNode* type, IdentifierNode* param, ASTNode * initializer)
            : _INOUT(nullptr),_type(type),
                _param(param),
            _initializer(initializer)
    {
        if (nullptr == initializer)
        {

            if ("NUM" == type->getTypeName())
                _initializer = new NumberLiteralNode(0);
            if ("STRING" == type->getTypeName())
                _initializer = new StringLiteralNode(new QString());
        }
        SymbolTable::Instance().DefineVariable(&param->_name.toLower(), type->getType(), type->getVariablenTypeName());
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
        return _param->_name;
    }

    QString ParameterNode::toRaw(uint level)
    {
        QString ret;
        if (_INOUT)
        {
            ret += "INOUT";
        }
        ret += " ";

        //IdentifierNode* s_type = (IdentifierNode*)(expr->_type);
        //str += s_type->getTypeName();
        //str += " ";
        //IdentifierNode* s_param = (IdentifierNode*)(expr->_param);
        //str += s_param->getTypeName();

        IdentifierNode* s_type = (IdentifierNode*)(_type);
        ret += s_type->getName();
        ret += " ";
        IdentifierNode* s_param = (IdentifierNode*)(_param);
        ret += s_param->getName();
        return ret;
    }

}

