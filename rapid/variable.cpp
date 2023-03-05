#include "variable.h"
#include "symboltable.h"
#include "errors.h"

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
    VariableNode::VariableNode(int e_scope, int e_type, ASTNode* expression) : _e_scope(e_scope), _e_type(e_type), _expression(expression)
    {

      
    }
    VariableNode::VariableNode(int e_scope, int e_type, ASTNode* expression, ASTNode* dim) : _e_scope(e_scope), _e_type(e_type), _expression(expression),_dim_num_stm(dim)
    {


    }

    QVariant VariableNode::Execute()
    {


        return ASTNode::Execute();
    }

    QString VariableNode::toString(uint level)
    {
        QString str = "";
        for (int i = 0; i < level; i++)
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
        str.append("\n");
        return str;
    }
}
