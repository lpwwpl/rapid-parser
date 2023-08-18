#ifndef ROBTARGETNODE_H
#define ROBTARGETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport RobTargetNode: public ASTNode
    {
    public:
        RobTargetNode(QString* name);
        QVariant Execute() override;
        void Accept(Visitor& v) override {}
        QString toRaw(uint level = 0) override;
    public:
        QString _name;
        float trans[3];
        float rot[4];
        float extra_conf[4];
        float extra_axis[6];
    };
}

#endif // ASSIGNMENTNODE_H
