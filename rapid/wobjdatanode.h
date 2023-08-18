#ifndef WOBJDATANODE_H
#define WOBJDATANODE_H

#include "astnode.h"
#include "dimnumnode.h"
namespace Language
{
    class RobotAbbExport WobjDataNode: public ASTNode
    {
    public:
        WobjDataNode(QString* name);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { /*v.VisitWobj(this);*/ }
    public:
        QString _name;
        bool wobj_install_style;
        bool wobj_style;
        QString workunit_name;
        float user_orig_pos[3];
        float user_orig_orient[4];
        float wobj_orig_pos[3];
        float wobj_orig_orient[4];
    };
}

#endif // ASSIGNMENTNODE_H
