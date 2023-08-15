#ifndef ACCESSNODE_H
#define ACCESSNODE_H

#include "astnode.h"
#include "identifiernode.h"
namespace Language
{
    //typedef std::vector<int> dimListType;
    //typedef std::vector<ASTNode*> dimRawType;
    class ArrayIndexNode: public ASTNode
    {
    public:
        ArrayIndexNode(IdentifierNode* name, ASTNode* elem  );
        
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    public:
        IdentifierNode* m_ident;
        ASTNode* m_exprs;

        QString _name;
        //dimListType tempDimList;
        //dimRawType tempDimRawList;
    };
}

#endif // ASSIGNMENTNODE_H
