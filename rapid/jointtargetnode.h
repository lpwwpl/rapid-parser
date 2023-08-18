#ifndef JOINTTARGETNODE_H
#define JOINTTARGETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport JointTargetNode: public ASTNode
    {
    public:
        JointTargetNode(QString* name);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override {}
    public:
        QString _name;
        float joints[6];
        float extra_joints[6];
    };
}

#endif // ASSIGNMENTNODE_H
