#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport AssignmentNode: public ASTNode
    {
    public:
        //AssignmentNode(QString * name, ASTNode * expression, ASTNode* dim=NULL);
        //AssignmentNode(QString* name, ASTNode*, ASTNode* expression, ASTNode* dim);
        AssignmentNode(ASTNode* ,  ASTNode* expression);
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
        //QString VarStr();
        QString getName() { return _name; }
        //dimListType* getDimListType()
        //{
        //    DimNumsNode* dimNode = dynamic_cast<DimNumsNode*>(_dim);
        //    dimListType* dimList = NULL;
        //    if (dimNode)
        //        dimList = &(dimNode->tempDimList);
        //    return dimList;
        //}

    public:
            QString _name;
            ASTNode * _expression;
            ASTNode* _src;
    };
}

#endif // ASSIGNMENTNODE_H
