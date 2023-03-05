#ifndef ROBTARGETNODE_H
#define ROBTARGETNODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobTargetNode: public ASTNode
    {
    public:
        RobTargetNode(QString* name);
        QVariant Execute() override;
        QString toString(uint level = 0) override;

    private:
        QString _name;
        float trans[3];
        float rot[4];
        float extra_conf[4];
        float extra_axis[6];
    };
}

#endif // ASSIGNMENTNODE_H
