#include "modifiernode.h"
#include "symboltable.h"
#include "errors.h"

extern int lineNumber;
extern int eState;
namespace Language
{
    //ModifierNode::ModifierNode(int e_scope, int e_type, QString* name):_e_scope(e_scope),_e_type(e_type),_name(name), _expression(NULL)
    //{

    //}
    //ModifierNode::ModifierNode(int e_scope, int e_type, QString* name, ASTNode* dim_num_stm) : _e_scope(e_scope), _e_type(e_type), _name(name), _expression(NULL)
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
    ModifierNode::ModifierNode(ASTNode* left, ASTNode* right) :ASTNode(), _left(left), _right(right)
    {

        

    }
    ModifierNode::ModifierNode(ASTNode* left) :ASTNode(), _left(left),_right(NULL)
    {



    }

    QVariant ModifierNode::Execute()
    {


        return ASTNode::Execute();
    }
    QString ModifierNode::toRaw(uint level)
    {
        QString str = "";
        //for (int i = 0; i < level; i++)
        //{
        //    str.append(INTENT);
        //}
        //
        str.append(_left->toRaw());
        if (_right)
        {
            str.append("\\");
            str.append(_right->toRaw());
        }
       
        return str;
    }

    QString ModifierNode::toString(uint level)
    {
        QString str = "";
        str.append(_left->toRaw());
        if (_right)
        {
            str.append(_right->toRaw());
        }
        return str;
    }
}
