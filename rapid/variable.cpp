#include "variable.h"
#include "symboltable.h"
#include "errors.h"
#include "arrayindex.h"
extern int lineNumber;
extern int eState;
namespace Language
{
    //VariableNode::VariableNode(int e_scope, int e_type, QString* name):_e_scope(e_scope),_e_type(e_type),_name(name), _expression(NULL)
    //{

    //}
    //VariableNode::VariableNode(int e_scope, int e_type, QString* name, ASTNode* dim_num_stm) : _e_scope(e_scope), _e_type(e_type), _name(name), _expression(NULL)
    //    , _dim_num_stm(dim_num_stm)
    //{

    //    DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(dim_num_stm);
    //    dimListType* dimList = NULL;
    //    if (dimNode)
    //        dimList = &(dimNode->tempDimList);
    //    _realVar = SymbolTable::Instance().CalcRealVarName(*name, dimList);
    //    int typeExpected = SymbolTable::Instance().VariableType(_realVar);

    //    if (typeExpected == -1)
    //    {
    //        if (!_realVar.startsWith("."))
    //        {
    //            ///////////GlobalRecord::Instance().AssignVariable(_name, _expression->Execute(), dimList);
    //            //SymbolTable::Instance().AssignVariable(_name, typeActual,_expression->Execute(), dimList);
    //        }
    //        return;
    //    }

    //    //if (typeActual != typeExpected)
    //    //{
    //    //    //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
    //    //    //exit(EXIT_FAILURE);
    //    //}
    //}
    VariableNode::VariableNode(int e_scope, ASTNode* e_type, ASTNode* src,ASTNode* expression) :ASTNode(), _e_scope(e_scope), _e_type(e_type),_src(src), _expression(expression)
    {

        StructIndexNode* structIndex = dynamic_cast<StructIndexNode*>(_src);
        ArrayIndexNode* array = dynamic_cast<ArrayIndexNode*>(_src);
        IdentifierNode* iden = dynamic_cast<IdentifierNode*>(_src);
        //AssignmentNode* ass = dynamic_cast<AssignmentNode*>(_src);
        if (array)
        {
            _name = array->m_ident->_name;
            //*_name = array->_name;
        }
        else if (structIndex)
        {
            _name = structIndex->_name;
        }
        else if (iden)
        {
            _name = iden->_name;
        }
        QString typeActual = _e_type->Type();
        QString typeExpected = SymbolTable::Instance().VariableType(_name);

        if (typeExpected == "")
        {

            SymbolTable::Instance().DefineVariable(&_name, typeActual);
            //GlobalRecord::Instance().AssignVariable(*_name, dimNode->Execute(), dimList);
               //SymbolTable::Instance().AssignVariable(_name, typeActual,_expression->Execute(), dimList);

            return;
        }

        if (typeActual != typeExpected)
        {
            //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            //exit(EXIT_FAILURE);
        }
    }
    VariableNode::VariableNode(int e_scope, ASTNode* e_type, ASTNode* expression) :ASTNode(), _e_scope(e_scope), _e_type(e_type), _src(expression), _expression(nullptr)
    {       
        StructIndexNode* structIndex = dynamic_cast<StructIndexNode*>(_src);
        ArrayIndexNode* array = dynamic_cast<ArrayIndexNode*>(_src);
        IdentifierNode* iden = dynamic_cast<IdentifierNode*>(_src);
        //AssignmentNode* ass = dynamic_cast<AssignmentNode*>(_src);
        if (array)
        {
            _name = array->m_ident->_name;
            //*_name = array->_name;
        }
        else if (structIndex)
        {
            _name = structIndex->_name;
        }
        else if (iden)
        {
            _name = iden->_name;
        }
        QString typeActual = _e_type->Type();
        QString typeExpected = SymbolTable::Instance().VariableType(_name);

        if (typeExpected == "")
        {
            
            SymbolTable::Instance().DefineVariable(&_name, typeActual);
            //GlobalRecord::Instance().AssignVariable(*_name, dimNode->Execute(), dimList);
               //SymbolTable::Instance().AssignVariable(_name, typeActual,_expression->Execute(), dimList);

            return;
        }

        if (typeActual != typeExpected)
        {
            //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            //exit(EXIT_FAILURE);
        }
    }
    

    QVariant VariableNode::Execute()
    {


        return ASTNode::Execute();
    }
    QString VariableNode::toRaw(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        //AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_expression);
        switch (_e_scope)
        {
        case  PERS:
        {
            str.append("PERS");
        }
        break;
        case   TASK_PERS:
        {
            str.append("TASK PERS");
        }
        break;

        case   eCONST:
        {
            str.append("CONST");
        }
        break;
        case    VAR:
        {
            str.append("VAR");
        }
        break;
        default:
            break;
        }
        str.append(" ");

        StringLiteralNode* type = dynamic_cast<StringLiteralNode*>(_e_type);
        str.append(type->_value);
       
        str.append(" ");
        if (_src)
        {
            str.append(_src->toRaw());
            if (_expression)
            {
                str.append(":=");
                str.append(_expression->toRaw());
            }
        }
        else
        {
            if (_expression)
            {
                str.append(_expression->toRaw());
            }
        }
        str.append(";");
        str.append("\n");
        return str;
    }

    QString VariableNode::toString(uint level)
    {
        QString str = "";
 /*       for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_expression);
        if (assign)
            str.append(assign->toString());
        else
        {

           * _name = _expression->toString();

            str.append(*_name);

            DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim_num_stm);
            dimRawType* dimRawList = NULL;
            if (dimNode)
                dimRawList = &(dimNode->tempDimRawList);
            int ndim;
            if (dimRawList != NULL)
            {
                ndim = dimRawList->size();
                str.append("[");
            }
            else
                ndim = 0;

            for (int i = 0; i < ndim; i++)
            {
                QString dimVar = dimRawList->at(i)->toString();
                str.append(dimVar);
                if (i < (ndim - 1))
                    str.append(",");
            }
            if (ndim > 0)
                str.append("]");
        }
        str.append("\n");*/
        return str;
    }
}
