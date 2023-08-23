#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include "astnode.h"
#include "listnode.h"
namespace Language
{
    class RobotAbbExport IdentifierNode : public ASTNode
    {
    public:
        IdentifierNode(QString * name);
        QVariant Execute() override;
        QString toRaw(uint level = 0);
        enum_v_type getType() override 
        { 
            QString lower = _name.toLower();

            if (lower == "num")
            {
                return enum_v_type::decimal;
            }
            else if (lower == "bool")
            {
                return enum_v_type::boolean;
            }
    
            return enum_v_type::identifier; 
        }
        QString getVariablenTypeName() const override { return _name; }
        virtual void Accept(Visitor& v) { v.VisitIdentifier(this); }
        QString getName() override { return _name; }
    public:
        QString _name;
        Language::location location;
        //bool isType = false;
    };
}

#endif // IDENTIFIERNODE_H
