
#include "VisitorTypeCheck.h"
using namespace Language;

#include "ast.h"

void VisitorTypeCheck::VisitAccset(AccSetNode* expr)
{

}
void VisitorTypeCheck::VisitCase(CaseNode* expr)
{

}
void VisitorTypeCheck::VisitActUnit(ActUnitNode* expr)
{}
void VisitorTypeCheck::VisitArcc(ArccNode* expr)
{}
void VisitorTypeCheck::VisitArcend(ArcEndNode* expr)
{}
void VisitorTypeCheck::VisitArcl(ArcLNode* expr)
{}
void VisitorTypeCheck::VisitIdentifier(IdentifierNode* expr)
{}
void VisitorTypeCheck::VisitArclStart(ArcLStartNode* expr)
{}
void VisitorTypeCheck::VisitArrayIndex(ArrayIndexNode* expr)
{
	//ListNode<ASTNode>* tempDimRawList = dynamic_cast<ListNode<ASTNode>*>(expr->m_exprs);
	//if (tempDimRawList)
	//{
	//	int count = tempDimRawList->size();
	//	for (int i = 0; i < count; i++)
	//	{
	//		tempDimRawList->at(i)->Accept(*this);
	//	}
	//}
}
void VisitorTypeCheck::VisitAssignment(AssignmentNode* expr)
{



}
void VisitorTypeCheck::VisitDeActunit(DeActUnitNode* stmt)
{}
void VisitorTypeCheck::VisitDeclarelist(DeclareListNode* retstmt)
{}
void VisitorTypeCheck::VisitDimnum(DimNumsNode* fndecl)
{}
void VisitorTypeCheck::VisitElseIf(ElseIfNode* expr)
{}
void VisitorTypeCheck::VisitFor(ForNode* expr)
{}
void VisitorTypeCheck::VisitFuncCall(FunctionCallNode* expr)
{}
void VisitorTypeCheck::VisitVariable(VariableNode* expr)
{
	//if (TypeNames.count(expr->_name.toStdString()) == 0) 
	//{
	//	ASTNode::printError(expr->_location, "Unknown type for decalration of " + expr->_name.toStdString());
	//	++syntaxErrors;
	//}

}
void VisitorTypeCheck::VisitIf(IfNode* expr)
{}
void VisitorTypeCheck::VisitWhileLoop(WhileNode* expr)
{

}
void VisitorTypeCheck::VisitStructDeclaration(StructDescNode* expr)
{
	//TypeNames.emplace(expr->_name);
	//if (_structTypes.count(expr->_name) != 0)
	//{
	//}

	//_structTypes[expr->_name] = expr;
	//if (TypeNames.count(expr->_name.toStdString()) == 0)
	//{
	//	TypeNames.emplace(expr->_name);
	//}
	//expr->_arguments->Accept(*this);
}
void VisitorTypeCheck::VisitRelTool(RelToolNode* expr)
{}
void VisitorTypeCheck::VisitSet(SetNode* expr)
{}
void VisitorTypeCheck::VisitSetDo(SetDoNode* expr)
{}
void VisitorTypeCheck::VisitStop(StopNode* expr)
{}
void VisitorTypeCheck::VisitSwitchCase(SWitchCaseListNode* expr)
{}
void VisitorTypeCheck::VisitInteger(Integer* expr)
{}
void VisitorTypeCheck::VisitBoolean(Boolean* expr)
{}
void VisitorTypeCheck::VisitSwitch(SWitchNode* expr)
{}
void VisitorTypeCheck::VisitStructindex(StructIndexNode* expr)
{}
void VisitorTypeCheck::VisitTpwrite(TpWriteNode* expr)
{}
void VisitorTypeCheck::VisitWaitDI(WaitDiNode* expr)
{}
void VisitorTypeCheck::VisitWaittime(WaitTimeNode* expr)
{}
void VisitorTypeCheck::VisitWaitutil(WaitUntilNode* expr)
{}

void VisitorTypeCheck::VisitPulseDO(PulseDONode* expr)
{}
void VisitorTypeCheck::VisitStatementList(StatementListNode* expr)
{
	for (auto stmt : *expr) {
		stmt->Accept(*this);
	}
}
void VisitorTypeCheck::VisitStringLiteral(StringLiteralNode* expr)
{

}

void VisitorTypeCheck::VisitReturn(ReturnNode* expr)
{
	ReturnStatementLocations.push_back(expr->_location);
}
void VisitorTypeCheck::VisitParamNode(ParameterNode* expr)
{

}
void VisitorTypeCheck::VisitOpera(OperatorNode* expr)
{

}
void VisitorTypeCheck::VisitOffs(OffsNode* expr)
{

}
void VisitorTypeCheck::VisitMoveJ(MoveJNode* expr)
{

}
void VisitorTypeCheck::VisitMoveL(MoveLNode* expr)
{

}
void VisitorTypeCheck::VisitMoveAbsJ(MoveABSJNode* expr)
{

}
void VisitorTypeCheck::VisitModule(ModuleNode* expr)
{

}
void VisitorTypeCheck::VisitReset(ReSetNode* expr)
{

}
void VisitorTypeCheck::VisitModifier(ModifierNode* expr)
{

}

void VisitorTypeCheck::VisitFunc(FunctionNode* expr)
{
	ReturnStatementLocations.clear();
	StatementListNode* body = expr->_body;

	for (auto stmt : *body) {
		stmt->Accept(*this);
	}
	auto retType = expr->getRetType();
	if (ReturnStatementLocations.size() > 1 && retType->_name == "var")
	{
		QString errMsg = QString("Too many return statement in function '%1()' for return type deduction.\nThe possible statements are:").arg( expr->_name);
		ASTNode::printError(expr->_location, errMsg.toStdString());
		std::stringstream s;
		for (auto loc : ReturnStatementLocations) {
			s << "    " << loc.end.filename << ":" << loc.begin.line << ":" << loc.begin.column << " return ...\n";
		}
		ASTNode::printError(s.str());
		syntaxErrors++;
	}
}

void VisitorTypeCheck::VisitVelset(VelSetNode*)
{

}
void VisitorTypeCheck::VisitDouble(NumberLiteralNode* expr)
{

}


void VisitorTypeCheck::VisitParamWithModifier(ParamWithModifierNode* expr)
{

}