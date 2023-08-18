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
    class RobotAbbExport ToolDataNode: public ASTNode
    {
    public:
        ToolDataNode(QString* name);
        QString toRaw(uint level = 0) override;
        QVariant Execute() override;
        void Accept(Visitor& v) override {}
    public:
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
