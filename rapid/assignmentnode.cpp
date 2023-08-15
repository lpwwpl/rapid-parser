#include "assignmentnode.h"
#include "symboltable.h"
#include "errors.h"
#include "listnode.h"
#include "arrayindex.h"
#include "structindexnode.h"
extern int lineNumber;
extern int eState;
namespace Language
{
 /*   AssignmentNode::AssignmentNode(QString* name, ASTNode* expression_bits, ASTNode* expression, ASTNode* dim ):_expression_bits(expression_bits),
        _expression(expression),_dim(dim),_name(*name),_src(NULL)
    {

    }*/

    AssignmentNode::AssignmentNode(ASTNode* src, ASTNode* expression) :_src(src),_expression(expression), _name("")        
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
        QString typeExpected = SymbolTable::Instance().VariableType(_name);
        QString typeActual = _expression->Type();
        if (typeExpected == "")
        {
            //if (!_realVar.startsWith("."))
            { 
                ///////////GlobalRecord::Instance().AssignVariable(_name, _expression->Execute(), dimList);
            ////////////    SymbolTable::Instance().AssignVariable(_realVar, typeActual,_expression->Execute());
            }
            return;
        }
        if (typeActual != typeExpected)
        {
            //std::cerr << TYPE_CONFLICT << SymbolTable::Instance().TypeName(typeActual).toStdString() << " to " << SymbolTable::Instance().TypeName(typeExpected).toStdString() << " (line: " << lineNumber << ")" << std::endl;
            //exit(EXIT_FAILURE);
        }

    }

    QString AssignmentNode::toRaw(uint level)
    {
        QString str;    
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
        str.append(_src->toRaw());
        str.append(":=");
        str.append(_expression->toRaw());
        //BuildInNode* buildIn = dynamic_cast<BuildInNode*>(_expression);
        //if (buildIn)
        //{
        //    str.append(buildIn->toString());
        //    return str;
        //}

        //ListNode<ASTNode*>* lists_ = dynamic_cast<ListNode<ASTNode*>*>(_expression);
        //if (lists_)
        //    str.append(_expression->toRaw());
        //else
        //    str.append(_expression->toRaw());
        return str;
    }
    QVariant AssignmentNode::Execute()
    {     
        //DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        //dimListType* dimList = NULL;
        //if (dimNode)
        //    dimList = &(dimNode->tempDimList);

        SymbolTable::Instance().GetActivationRecord()->AssignVariable(_name, _expression->Execute());

        return ASTNode::Execute();
    }
    //QString AssignmentNode::VarStr()
    //{
    //    QString str = "";

    //    QString temp = _name;

    ///*    if (!_name.startsWith("."))
    //    {
    //        str.append("kdata.");           
    //    }
    //    else
    //    {
    //        temp.replace(0, 1, "");
    //    }
    //    if (_name.startsWith("#"))
    //    {
    //        temp.replace(0, 1, "_");
    //    }
    //    if (_name.startsWith("$"))
    //    {
    //        temp.replace(0, 1, "");
    //    }*/
    //    str.append(temp);

    //    DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
    //    dimRawType* dimRawList = NULL;
    //    if (dimNode)
    //        dimRawList = &(dimNode->tempDimRawList);
    //    int ndim;
    //    if (dimRawList != NULL)
    //    {
    //        ndim = dimRawList->size();
    //        str.append("[");
    //    }
    //    else
    //        ndim = 0;

    //    for (int i = 0; i < ndim; i++)
    //    {
    //        QString dimVar = dimRawList->at(i)->toString();
    //        str.append(dimVar);
    //        if (i < (ndim - 1))
    //            str.append(",");
    //    }
    //    if (ndim > 0)
    //        str.append("]");
    //    return str;
    //}
    QString AssignmentNode::toString(uint level )
    {
        QString str = "";
        for (int i = 0; i < level; i++)
        {
            str.append("    ");
        }
         
        str.append(_src->toString());
        str.append("=");      
        str.append(_expression->toString());
        return str;
    }
}
