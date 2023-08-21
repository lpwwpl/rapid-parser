#ifndef Visitor_h__
#define Visitor_h__

#include "PreCompiled.h"

namespace Language {

	class AccSetNode;
	class ActUnitNode;
	class ArccNode;
	class ArcEndNode;
	class CaseNode;
	class ArcLNode;
	class IdentifierNode;
	class ArcLStartNode;
	class ArrayIndexNode;
	class AssignmentNode;
	class DeActUnitNode;
	class DeclareListNode;
	class DimNumsNode;
	class ElseIfNode;
	class ForNode;
	class FunctionCallNode;
	class VariableNode;
	class IfNode;
	class WhileNode;
	class StructDescNode;
	class RelToolNode;
	class SetNode;
	class SetNode;
	class StopNode;
	class SWitchCaseListNode;
	class Integer;
	class Boolean;
	class SWitchNode;
	class StructIndexNode;
	class TpWriteNode;
	class StatementListNode;
	class ModifierNode;
	class MoveJNode;
	class FunctionNode;
	class ModuleNode;
	class ReturnNode;
	class MoveLNode;
	class ReSetNode;
	class PulseDONode;
	class WaitUntilNode;
	class WaitDiNode;
	class WaitTimeNode;
	class StringLiteralNode;
	class ParameterNode;
	class MoveABSJNode;
	class OperatorNode;
	class OffsNode;
	class VelSetNode;
	class SetDoNode;
	class NumberLiteralNode;
	class ParamWithModifierNode;

	class RobotAbbExport Visitor
	{
	public:
		virtual void VisitAccset(AccSetNode* expr) = 0;
		virtual void VisitActUnit(ActUnitNode* expr) = 0;
		virtual void VisitArcc(ArccNode* expr) = 0;
		virtual void VisitArcend(ArcEndNode* expr) = 0;
		virtual void VisitCase(CaseNode* expr) = 0;
		virtual void VisitArcl(ArcLNode* expr) = 0;
		virtual void VisitIdentifier(IdentifierNode* expr) = 0;
		virtual void VisitArclStart(ArcLStartNode* expr) = 0;
		virtual void VisitArrayIndex(ArrayIndexNode* expr) = 0;
		virtual void VisitAssignment(AssignmentNode* expr) = 0;
		virtual void VisitDeActunit(DeActUnitNode* stmt) = 0;
		virtual void VisitDeclarelist(DeclareListNode* retstmt) = 0;
		virtual void VisitDimnum(DimNumsNode* fndecl) = 0;
		virtual void VisitElseIf(ElseIfNode* expr) = 0;
		virtual void VisitFor(ForNode* expr) = 0;
		virtual void VisitFuncCall(FunctionCallNode* expr) = 0;
		virtual void VisitVariable(VariableNode* expr) = 0;
		virtual void VisitIf(IfNode* expr) = 0;
		virtual void VisitWhileLoop(WhileNode* expr) = 0;
		virtual void VisitStructDeclaration(StructDescNode* expr) = 0;
		virtual void VisitRelTool(RelToolNode* expr) = 0;
		virtual void VisitSet(SetNode* expr) = 0;
		virtual void VisitSetDo(SetDoNode* expr) = 0;
		virtual void VisitStop(StopNode* expr) = 0;
		virtual void VisitSwitchCase(SWitchCaseListNode* expr) = 0;
		virtual void VisitInteger(Integer* expr) = 0;
		virtual void VisitBoolean(Boolean* expr) = 0;
		virtual void VisitSwitch(SWitchNode* expr) = 0;
		virtual void VisitStructindex(StructIndexNode* expr) = 0;
		virtual void VisitTpwrite(TpWriteNode* expr) = 0;
		virtual void VisitWaitDI(WaitDiNode* expr) = 0;
		virtual void VisitWaittime(WaitTimeNode* expr) = 0;
		virtual void VisitWaitutil(WaitUntilNode* expr) = 0;
		virtual void VisitPulseDO(PulseDONode* expr) = 0;
		virtual void VisitStatementList(StatementListNode* expr) = 0;
		virtual void VisitStringLiteral(StringLiteralNode* expr) = 0;
		virtual void VisitDouble(NumberLiteralNode* expr) = 0;
		virtual void VisitReturn(ReturnNode* expr) = 0;
		virtual void VisitParamNode(ParameterNode* expr) = 0;
		virtual void VisitOpera(OperatorNode* expr) = 0;
		virtual void VisitOffs(OffsNode* expr) = 0;
		virtual void VisitMoveJ(MoveJNode* expr) = 0;
		virtual void VisitMoveL(MoveLNode* expr) = 0;
		virtual void VisitMoveAbsJ(MoveABSJNode* expr) = 0;
		virtual void VisitModule(ModuleNode* expr) = 0;
		virtual void VisitReset(ReSetNode* expr) = 0;
		virtual void VisitModifier(ModifierNode* expr) = 0;
		virtual void VisitParamWithModifier(ParamWithModifierNode* expr)=0;
		virtual void VisitVelset(VelSetNode* expr) = 0;
		virtual void VisitFunc(FunctionNode* expr) = 0;
	};

}
#endif // Visitor_h