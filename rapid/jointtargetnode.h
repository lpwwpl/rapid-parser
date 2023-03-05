#ifndef JOINTTARGETNODE_H
#define JOINTTARGETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class JointTargetNode: public ASTNode
    {
    public:
        JointTargetNode(QString* name);
        QVariant Execute() override;
        QString toString(uint level = 0) override;

    private:
        QString _name;
        float joints[6];
        float extra_joints[6];
    };
}

#endif // ASSIGNMENTNODE_H
