#ifndef TOOLDATANODE_H
#define TOOLDATANODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{

    struct gravity
    {
        float mass;
        float gravity[3];
    };
    class ToolDataNode: public ASTNode
    {
    public:
        ToolDataNode(QString* name);
        QVariant Execute() override;
        QString toString(uint level = 0) override;

    private:
        QString _name;
        bool bTool;
        float trans[3];
        float rot[4];
        float mass;
        float gravity_trans[3];
        float gravity_rot[4];
        float ixyz[3];


    };
}

#endif // ASSIGNMENTNODE_H
