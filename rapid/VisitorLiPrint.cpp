
#include "VisitorLiPrint.h"
using namespace Language;

#include "symboltable.h"
#include "ast.h"

#define INTENT "    "


VisitorLiPrint::VisitorLiPrint()
{
    cur_cheo = NULL;
}

void VisitorLiPrint::VisitAccset(AccSetNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("AccSet");
    //str.append(_name);
    str.append("(");
    expr->_expression1->Accept(*this);
    str.append(",");
    expr->_expression2->Accept(*this);
    str.append(")");   
}

void VisitorLiPrint::VisitCase(CaseNode* expr)
{

}

void VisitorLiPrint::VisitActUnit(ActUnitNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("actunit");
    str.append("(");
    for (auto statement : *(expr->_arguments))
    {
        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitArcc(ArccNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("arcc");
    str.append("(");
    for (auto statement : *(expr->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitArcend(ArcEndNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("arcend");
    str.append("(");
    for (auto statement : *(expr->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitArcl(ArcLNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("ArcL");
    str.append("(");
    for (auto statement : *(expr->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitIdentifier(IdentifierNode* expr)
{
    VariableRecord vr=
    SymbolTable::Instance().GetVariableValue(expr->_name.toLower());

    ModuleNode* module = dynamic_cast<ModuleNode*>(cur_cheo);
    if (vr._scope == eModule && !module)
    {
        str.append("self.");
    }

    str.append(expr->_name);
}
void VisitorLiPrint::VisitArclStart(ArcLStartNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("arclStart");
    str.append("(");
    for (auto statement : *(expr->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitArrayIndex(ArrayIndexNode* expr)
{
    str += expr->m_ident->_name;
    ListNode<ASTNode>* tempDimRawList = dynamic_cast<ListNode<ASTNode>*>(expr->m_exprs);
    if (tempDimRawList)
    {

        str.append("[");
        int count = tempDimRawList->size();
        for (int i = 0; i < count; i++)
        {
            tempDimRawList->at(i)->Accept(*this);
            str.append(",");
        }
        if (str.endsWith(","))
        {
            str = str.mid(0, str.size() - 1);
        }
        str.append("]");
    }
}
void VisitorLiPrint::VisitAssignment(AssignmentNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    int curIndent = indent;
    indent = 0;
    expr->_src->Accept(*this);
    str.append("=");
    expr->_expression->Accept(*this);
    indent = curIndent;
}
void VisitorLiPrint::VisitDeActunit(DeActUnitNode* stmt)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("deactunit");
    str.append("(");
    for (auto statement : *(stmt->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitDeclarelist(DeclareListNode* retstmt)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    for (auto statement : *retstmt)
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
    }
}
void VisitorLiPrint::VisitDimnum(DimNumsNode* fndecl)
{
    str.append("[");
    int count = fndecl->tempDimRawList.size();
    for (int i = 0; i < count; i++)
    {
        fndecl->tempDimRawList[i]->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append("]");
}
void VisitorLiPrint::VisitElseIf(ElseIfNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }

    if (!expr->_expression)
    {
        str.append("else:");
        str.append("\n");
    }
    else if (expr->_expression)
    {
        str.append("elif ");
        expr->_expression->Accept(*this);
        str.append(":");
        str.append("\n");

    }
    indent++;
    expr->_body->Accept(*this);
    indent--;
}
void VisitorLiPrint::VisitFor(ForNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("for");
    str.append(" ");
    //AssignmentNode* assign = dynamic_cast<AssignmentNode*>(_assignment);
    expr->_assignment->Accept(*this);
    str.append(" ");
    str.append("in");
    str.append(" ");
    str.append("range");
    str.append("(");
    expr->_from_expression->Accept(*this);
    str.append(",");
    expr->_to_expression->Accept(*this);
    str.append(")");
    str.append(":");
    str.append("\n");
    indent = indent + 1;
    expr->_function_body->Accept(*this);
    indent = indent - 1;
}
void VisitorLiPrint::VisitFuncCall(FunctionCallNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.");
    QString func_name = *expr->_name;
    if (func_name.toLower() == "incr")
    {
        str.append("vc.");
    }
    str.append(expr->_name);
    str.append("(");
    int expr_count = expr->_expressionList->size();
    for (size_t i = 0; i < expr_count; i++)
    {
        ASTNode* arg = expr->_expressionList->at(i);
        ListNode<ASTNode>* list_arg = dynamic_cast<ListNode<ASTNode>*>(arg);
        if (list_arg)
        {
            int count = list_arg->size();
            for (int j = 0; j < count;j++) //auto item : *list_arg
            {
                auto item = list_arg->at(j);
                str.append("\"");
                item->Accept(*this);
                str.append("\"");

                if(j<count-1)
                    str.append(",");
            }
        }
        else
        {
            arg->Accept(*this);
            if (i < expr_count - 1)
                str.append(",");
        }

    }
    //if (str.endsWith(","))
    //{
    //    str = str.mid(0, str.size() - 1);
    //}
    str.append(")");
}
//int,double,string..
//var name
void VisitorLiPrint::VisitVariable(VariableNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
 
    IdentifierNode* type = dynamic_cast<IdentifierNode*>(expr->_e_type);

    QString typeName = type->getTypeName();
    
    //if(typeName == "")

    int curIndent = indent;
    indent = 0;
    if (expr->_src && expr->_expression)
    {
        expr->_src->Accept(*this);
        str.append("=");

        if (expr->_e_type->getType() == enum_v_type::identifier)
        {
            str.append(expr->getVariablenTypeName());
            str.append("(");
            expr->_expression->Accept(*this);
            str.append(")");
        }
        else
        {
            expr->_expression->Accept(*this);
        }
        str.append("\n");
    }
    else
    {
    }
    indent = curIndent;

}
void VisitorLiPrint::VisitIf(IfNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("if");
    str.append(" ");
    expr->_expression->Accept(*this);

    str.append(":");
    str.append("\n");
    if (!expr->_bodyTrue)
    {
        str.append("\n");
        for (int i = 0; i < indent+1; i++)
        {
            str.append(INTENT);
        }

        str.append("pass");
        str.append("\n");
    }
    else
    {
        indent++;
        expr->_bodyTrue->Accept(*this);
        indent--;
    }

    if (expr->_bodyFalse)
    {
        ListNode<ElseIfNode>* elseifs = dynamic_cast<ListNode<ElseIfNode>*>(expr->_bodyFalse);

        for (auto statement : *elseifs)
        {

            if (!statement)continue;
            ElseIfNode* elseif = dynamic_cast<ElseIfNode*>(statement);
            //statement->Execute();
            elseif->Accept(*this);
        }
        indent++;
        expr->_bodyFalse->Accept(*this);
        indent--;
    }
    str.append("\n");
}
void VisitorLiPrint::VisitWhileLoop(WhileNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("while");
    str.append(" ");
    expr->_expression->Accept(*this);
    str.append(" ");
    str.append(":");
    str.append("\n");

    indent = indent + 1;
    expr->_body->Accept(*this);
    indent = indent - 1;
}
void VisitorLiPrint::VisitStructDeclaration(StructDescNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(QString::fromLatin1(INTENT));
    }
    str += QString::fromLatin1("class");
    str += QString::fromLatin1(SPACE);
    str += expr->_name;
    str += QString::fromLatin1(":");
    str += INTENT;
    str += QString::fromLatin1("def __init__(self):");
    str += QString::fromLatin1("\n");
    indent = indent + 2;
    expr->_arguments->Accept(*this);
    indent = indent - 2;
    str += QString::fromLatin1("\n");
}
void VisitorLiPrint::VisitRelTool(RelToolNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("RelTool");
    //str.append(_name);
    str.append("(");
    expr->_expression->Accept(*this);
    str.append(")");
}
void VisitorLiPrint::VisitSet(SetNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("Set");
    //str.append(_name);
    str.append("(");
    str.append("\"");
    expr->_expression->Accept(*this);
    str.append("\"");
    str.append(")");
}
void VisitorLiPrint::VisitSetDo(SetDoNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("SetDo");
    str.append("(");
    str.append("\"");
    expr->_name->Accept(*this);
    str.append("\"");
    str.append(",");
    expr->_expression->Accept(*this);
    str.append(")");
}
void VisitorLiPrint::VisitStop(StopNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    //str.append("self.");
    str.append("stop");
    str.append("(");
    str.append(")");
}
void VisitorLiPrint::VisitSwitchCase(SWitchCaseListNode* expr)
{

}
void VisitorLiPrint::VisitInteger(Integer* expr)
{
    str.append(QString::number(expr->value));
}

void VisitorLiPrint::VisitBoolean(Boolean* expr)
{
    int boolValue = expr->boolVal;
    if (boolValue)
        str.append("True");
    else
        str.append("False");
}
//switch:switchcase:case
void VisitorLiPrint::VisitSwitch(SWitchNode* expr)
{
    QMap<int, ASTNode* > cases;
    ASTNode* key = expr->_expression;
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("numbers={");
    str.append("\n");
    SWitchCaseListNode* caseLists = dynamic_cast<SWitchCaseListNode*> (expr->_caseLists);

    QMap<int, CaseNode*> key_values;

    for (auto it = caseLists->begin(); it != caseLists->end(); it++)
    {
        for (int i = 0; i < indent + 1; i++)
        {
            str.append(INTENT);
        }
        CaseNode* caseNode = dynamic_cast<CaseNode*>(*it);
        int key = caseNode->_expression->Execute().toInt();
        str.append(QString::number(key));
        str.append(":");
        str.append("\n");
        caseNode->Accept(*this);

    }
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("}");
    str.append("\n");
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("method=numbers.get(");
    key->Accept(*this);
    str.append(")");
    str.append("\n");
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("method()");
}
void VisitorLiPrint::VisitStructindex(StructIndexNode* expr)
{
    expr->_left->Accept(*this);
    str.append(".");
    expr->_right->Accept(*this);
    //str.append(expr->_name);
}

void VisitorLiPrint::VisitTpwrite(TpWriteNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    //str.append("self.");
    str.append("TPWrite");
    str.append("(");
    expr->_expression->Accept(*this);
    str.append(")");
}
void VisitorLiPrint::VisitWaitDI(WaitDiNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("WaitDI(");
    str.append("\"");
    str.append(expr->_name);
    str.append("\"");
    str.append(",");
    expr->_expression->Accept(*this);
    str.append(")");
}
void VisitorLiPrint::VisitWaittime(WaitTimeNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("WaitTime");
    //str.append(_name);
    str.append("(");
    //expr->_expression->Accept(*this);
    ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(expr->_expression);
    if (nodes)
    {
        int count = nodes->size();
        for (int i = 0; i < count; i++)
        {
            auto node = nodes->at(i);
            ListNode<ASTNode>* p_nodes = dynamic_cast<ListNode<ASTNode>*>(node);
            if (p_nodes)
            {
                str.append("\"");
                int p_count = p_nodes->size();
                for (int j = 0; j < p_count; j++)
                {
                    auto p_node = p_nodes->at(j);
                    p_node->Accept(*this);
                    if (j == (p_count - 1))
                        ;
                    else
                        str.append(",");

                }
                str.append("\"");
            }
            else
            {
            
                node->Accept(*this);
         
            }
            
            if (i == (count - 1))
                ;
            else
                str.append(",");
        }
    }
    str.append(")");
}
void VisitorLiPrint::VisitWaitutil(WaitUntilNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("WaitUntil");
    //str.append(_name);
    str.append("(");


    OperatorNode* oper = dynamic_cast<OperatorNode*>(expr->_expression);
    if (oper)
    {
        switch (oper->_operator)
        {
        case L_token::EQ:
        {
            str.append("\"");
            oper->_op1->Accept(*this);
            str.append("\"");
            str += " ,";
            oper->_op2->Accept(*this);
        }
        break;
        default:
            break;
        }
    }
    //expr->_expression->Accept(*this);
    str.append(")");
}

void VisitorLiPrint::VisitPulseDO(PulseDONode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("PulseDo ");
    //str.append(_name);
    str.append("(");
    ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(expr->_expression);
    if (nodes)
    {
        int count = nodes->size();
        for (int i = 0; i < count; i++)
        {
            auto node = nodes->at(i);
            ListNode<ASTNode>* p_nodes = dynamic_cast<ListNode<ASTNode>*>(node);
            if (p_nodes)
            {
                str.append("\"");
                int p_count = p_nodes->size();
                for (int j = 0; j < p_count; j++)
                {
                    auto p_node = p_nodes->at(j);
                    int curIndent = indent;
                    indent = 0;
                    p_node->Accept(*this);
                    indent = curIndent;
                    if (j == (p_count - 1))
                        ;
                    else
                        str.append(",");

                }
                str.append("\"");
            }
            else
            {
                str.append("\"");
                node->Accept(*this);
                str.append("\"");
            }


            if (i == (count - 1))
                ;
            else
                str.append(",");
        }
    }
    else
    {
        expr->_expression->Accept(*this);
    }

    str.append(")");
}
void VisitorLiPrint::VisitStatementList(StatementListNode* expr)
{
    for (auto statement : *expr)
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);

        IfNode* ifNode = dynamic_cast<IfNode*>(statement);
        ForNode* forNode = dynamic_cast<ForNode*>(statement);
        if (!ifNode && !forNode)
            str.append("\n");
        //if (dynamic_cast<ReturnNode*>(statement))
        //    break;
    }
}
void VisitorLiPrint::VisitStringLiteral(StringLiteralNode* expr)
{
    str.append("\"");
    str.append(expr->_value);
    str.append("\"");
}

void VisitorLiPrint::VisitDouble(NumberLiteralNode* expr)
{
    str.append(QString::number(expr->_value));
}
void VisitorLiPrint::VisitReturn(ReturnNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("return");
    str.append(" ");
    if (expr->_expression)
        expr->_expression->Accept(*this);
}
void VisitorLiPrint::VisitParamNode(ParameterNode* expr)
{
    if (expr->_INOUT)
    {
        //str += "INOUT";
    }
    //IdentifierNode* s_type = (IdentifierNode*)(expr->_type);
    //str += s_type->getName();
    //str += " ";
    IdentifierNode* s_param = (IdentifierNode*)(expr->_param);
    VariableRecord vr =
        SymbolTable::Instance().GetVariableValue(expr->_name);
    if (vr._scope == eModule)
    {
        str.append("self.");
    }
    //str += "\"";
    str += s_param->getName();
    //str += "\"";
}

void VisitorLiPrint::VisitOpera(OperatorNode* expr)
{
    switch (expr->_operator)
    {
    case L_token::ASS:
    {
        expr->_op1->Accept(*this);
        str += " = ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::LC:
    {
        str += "(";
        expr->_op1->Accept(*this);
        str += ")";
    }
    case L_token::UMINUS:
    {
        str += "-";
        expr->_op1->Accept(*this);
    }
    break;
    case L_token::ADD:
    {
        expr->_op1->Accept(*this);
        str += " + ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::SUB:
    {
        expr->_op1->Accept(*this);
        str += " - ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::MUL:
    {
        expr->_op1->Accept(*this);
        str += " * ";
        expr->_op2->Accept(*this);
    }
    break;
    //case L_token::DIV: 
    //{
    //    QString temp = QString("%1 / %2").arg(_op1->toString()).arg(_op2->toString());
    //    str = temp;
    //}
    //    break;
    case L_token::LT:
    {
        expr->_op1->Accept(*this);
        str += " < ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::GT:
    {
        expr->_op1->Accept(*this);
        str += " > ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::GE:
    {
        expr->_op1->Accept(*this);
        str += " >= ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::LE:
    {
        expr->_op1->Accept(*this);
        str += " <= ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::NE:
    {
        expr->_op1->Accept(*this);
        str += " != ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::EQ:
    {
        expr->_op1->Accept(*this);
        str += " == ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::AND:
    {
        expr->_op1->Accept(*this);
        str += " and ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::OR:
    {
        expr->_op1->Accept(*this);
        str += " or ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::MOD:
    {
        expr->_op1->Accept(*this);
        str += " % ";
        expr->_op2->Accept(*this);
    }
    break;
    case L_token::NOT:
    {
        str += "not";
        expr->_op1->Accept(*this);
    }
        break;
    default: std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
        break;
        //exit(EXIT_FAILURE);
    }
}
void VisitorLiPrint::VisitOffs(OffsNode* expr)
{
    str.append("self.vc.");
    str.append("Offs");
    //str.append(_name);
    str.append("(");
    ListNode<ASTNode>* nodes = dynamic_cast<ListNode<ASTNode>*>(expr->_expression);
    if (nodes)
    {
        int count = nodes->size();
        for (int i = 0; i < count; i++)
        {
            auto node = nodes->at(i);
            node->Accept(*this);
            if (i == (count - 1))
                ;
            else
                str.append(",");
        }
    }
    str.append(")");
}
void VisitorLiPrint::VisitMoveJ(MoveJNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("MoveJ");
    str.append("(");
    int i = 0;
    for (auto statement : *(expr->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        if (i == 1 || i == 2)
        {
            str.append("self.vc.");
        }
        statement->Accept(*this);
        i++;
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitMoveL(MoveLNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("MoveL");
    str.append("(");
    int i = 0;
    for (auto statement : *(expr->_arguments))
    {
        if (!statement)continue;
        //statement->Execute();
        if (i == 1 || i == 2)
        {
            str.append("self.vc.");
        }
        statement->Accept(*this);
        i++;
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitMoveAbsJ(MoveABSJNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("MoveAbsj");
    str.append("(");
    for (auto statement : *(expr->_arguments))
    {

        if (!statement)continue;
        //statement->Execute();
        statement->Accept(*this);
        str.append(",");
    }
    if (str.endsWith(","))
    {
        str = str.mid(0, str.size() - 1);
    }
    str.append(")");
}
void VisitorLiPrint::VisitModule(ModuleNode* expr)
{
    str += "class ";
    str += expr->_name;
    str += "():";
    str += "\n";
    cur_cheo = expr;
    indent++;

    for (auto statement : *(expr->_body))
    {
        if (!statement)continue;
        //if(statement->getTypeName() == enum_v_type::function)
        //statement->Execute();
            statement->Accept(*this);
        //else
        //{

        //}
    }
    indent--;
}
void VisitorLiPrint::VisitReset(ReSetNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("Reset");
    //str.append(_name);
    str.append("(");
    str.append("\"");
    expr->_expression->Accept(*this);
    str.append("\"");
    str.append(")");
}
void VisitorLiPrint::VisitModifier(ModifierNode* expr)
{
    str.append("\"");
    expr->_left->Accept(*this);
    if (expr->_right)
    {
        expr->_right->Accept(*this);
    }
    str.append("\"");
}

void VisitorLiPrint::VisitFunc(FunctionNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(QString::fromLatin1(INTENT));
    }
    //str += QString::fromLatin1("@allow_goto");
    //str += QString::fromLatin1("\n");
    cur_cheo = expr;
    str += QString::fromLatin1("def");
    str += QString::fromLatin1(SPACE);
    str += expr->_name;
    str += QString::fromLatin1("(");
    str += "self";
    int count = expr->_arguments->size();
    if (count > 0)
        str += ",";
    for (int i = 0; i < count; i++)
    {
        ParameterNode* node = expr->_arguments->at(i);
        node->Accept(*this);
        if (i < (count - 1))
        {
            str += ",";
        }
    }
    expr->_arguments->Accept(*this);
    str += QString::fromLatin1(")");
    str += QString::fromLatin1(":");
    str += QString::fromLatin1("\n");
    //str += INTENT;
    //str += _arguments->toString();
    indent = indent + 1;
    expr->_body->Accept(*this);
    indent = indent - 1;
}

void VisitorLiPrint::VisitVelset(VelSetNode* expr)
{
    for (int i = 0; i < indent; i++)
    {
        str.append(INTENT);
    }
    str.append("self.vc.");
    str.append("VelSet");
    //str.append(_name);
    str.append("(");
    expr->_expression1->Accept(*this);
    str.append(",");
    expr->_expression2->Accept(*this);
    str.append(")");
}

void VisitorLiPrint::VisitParamWithModifier(ParamWithModifierNode* expr)
{
    
    expr->_var_expr->Accept(*this);
    str.append(",");
    int curIndent = indent;
    indent = 0;
    str.append("\"");
    for (auto stm : *expr->_dimRawType)
    {
        stm->Accept(*this);
    }
    str.append("\"");
    indent = curIndent;
}
    