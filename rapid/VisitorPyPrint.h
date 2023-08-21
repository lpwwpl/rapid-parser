#ifndef VisitorPyPrint_h__
#define VisitorPyPrint_h__
#include "PreCompiled.h"
#include "Visitor.h"
#include <QString>
namespace Language {

	class RobotAbbExport VisitorPyPrint : public Visitor
	{
	public:
		int indent{ 0 };
		QString str = QString::fromLatin1("");
	public:
		//VisitorPyPrint(Context* context)
		//{
		//	m_context = context;
		//}
		void VisitAccset(AccSetNode* expr);
		void VisitActUnit(ActUnitNode* expr);
		void VisitCase(CaseNode* expr);
		void VisitArcc(ArccNode* expr);
		void VisitArcend(ArcEndNode* expr);
		void VisitArcl(ArcLNode* expr);
		void VisitIdentifier(IdentifierNode* expr);
		void VisitArclStart(ArcLStartNode* expr);
		void VisitArrayIndex(ArrayIndexNode* expr);
		void VisitAssignment(AssignmentNode* expr);
		void VisitDeActunit(DeActUnitNode* stmt);
		void VisitDeclarelist(DeclareListNode* retstmt);
		void VisitDimnum(DimNumsNode* fndecl);
		void VisitElseIf(ElseIfNode* expr);
		void VisitFor(ForNode* expr);
		void VisitFuncCall(FunctionCallNode* expr);
		void VisitVariable(VariableNode* expr);
		void VisitIf(IfNode* expr);
		void VisitWhileLoop(WhileNode* expr);
		void VisitStructDeclaration(StructDescNode* expr);
		void VisitRelTool(RelToolNode* expr);
		void VisitSet(SetNode* expr);
		void VisitSetDo(SetDoNode* expr);
		void VisitStop(StopNode* expr);
		void VisitSwitchCase(SWitchCaseListNode* expr);
		void VisitInteger(Integer* expr);
		void VisitBoolean(Boolean* expr);
		void VisitSwitch(SWitchNode* expr);
		void VisitStructindex(StructIndexNode* expr);
		void VisitTpwrite(TpWriteNode* expr);
		void VisitWaitDI(WaitDiNode* expr);
		void VisitWaittime(WaitTimeNode* expr);
		void VisitWaitutil(WaitUntilNode* expr);
		void VisitPulseDO(PulseDONode* expr);
		void VisitStatementList(StatementListNode* expr);
		void VisitStringLiteral(StringLiteralNode* expr);
		void VisitDouble(NumberLiteralNode* expr);

		void VisitReturn(ReturnNode* expr);
		void VisitParamNode(ParameterNode* expr);
		void VisitOpera(OperatorNode* expr);
		void VisitOffs(OffsNode* expr);
		void VisitMoveJ(MoveJNode* expr);
		void VisitMoveL(MoveLNode* expr);
		void VisitMoveAbsJ(MoveABSJNode* expr);
		void VisitModule(ModuleNode* expr);
		void VisitReset(ReSetNode* expr);
		void VisitModifier(ModifierNode* expr);
		void VisitFunc(FunctionNode* expr);

		void VisitParamWithModifier(ParamWithModifierNode* expr);
		void VisitVelset(VelSetNode*);
	};

}
#endif // Visitor_h