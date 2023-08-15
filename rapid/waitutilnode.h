#ifndef WAITUNTILNODE_H
#define WAITUNTILNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class WaitUntilNode: public ASTNode
    {
    public:
        WaitUntilNode(ASTNode* expression =NULL);
        
        QVariant Execute() override;
        QString toString(uint level = 0) override;
        QString toRaw(uint level = 0) override;
    private:
            //QString _name;
            ASTNode* _expression;
    };
}

#endif // ASSIGNMENTNODE_H
