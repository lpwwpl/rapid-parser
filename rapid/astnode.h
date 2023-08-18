#ifndef ASTNODE_H
#define ASTNODE_H

#include <QVariant>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "PreCompiled.h"
#include <boost/signals2.hpp>
#include "Visitor.h"
#include "parser.tab.hpp"
#include "variablerecord.h"

typedef Language::Parser::token token;
#define SPACE " "
#define INTENT "    "


namespace Language
{

 
    struct SAstNodeType
    {
        char command[64];
        enum_v_type eType;
    };

    //class ASTNode;
    //template <class T >
    //class ListNode : public ASTNode, public std::vector<T*>
    //{
    //public:
    //    ListNode() {}
    //    ListNode(T* node) { this->push_back(node); }
    //};
    class RobotAbbExport ASTNode 
    {
    public:
        ASTNode();
        virtual ~ASTNode();
        virtual QVariant Execute();
        virtual void compute() {}
        //name
        virtual QString getName() { return ""; }

        //type: int,string,fun return type, var type
        virtual enum_v_type getType() { return _type; }
        //type's string: int,string,fun return type, var type
        virtual QString getVariablenTypeName() const { return ""; }

        //type's string: int,string,fun return type, var type
        virtual QString getTypeName() 
        { 
            QString ret = "";

            switch (_type)
            {
            case enum_v_type::variable:
                ret = getVariablenTypeName();
                break;
            case enum_v_type::integer:
                ret = "int";
                break;
            case enum_v_type::decimal:
                ret = "double";
                break;
            case enum_v_type::string:
                ret = "string";
                break;
            case enum_v_type::boolean:
                ret = "boolean";
                break;
            case enum_v_type::function:
                ret = getVariablenTypeName();
                break;
            case enum_v_type::identifier:
                ret = getVariablenTypeName();
                break;
            default:break;
            }
            return ret;
        } 

        void SetPrefix(bool value) { _prefix = value; }
        virtual void Accept(Visitor& v) {}
        virtual QString toRaw(uint level = 0) { return ""; }

        static void printError(Language::location location, std::string msg)
        {
            std::cerr
                << location.end.filename
                << ": line "
                << location.begin.line << " column "
                << location.begin.column << "-"
                << location.end.column << ":"
                << msg << std::endl;
        }

        /*! Prints an error message where no source location is available.
         * \param[in] msg      The message to print.
         */
        static void printError(std::string msg)
        {
            std::cerr << msg << std::endl;
        }

    public:
        bool _prefix;
        boost::signals2::signal<void()> signalRunInst;
        boost::signals2::signal<void(ASTNode*)> signalParseInst;
        enum_v_type _type = { enum_v_type::Not_found };
    };


    class RobotAbbExport Integer : public ASTNode
    {
    public:
        explicit Integer(long long value) : value(value) {}
        virtual ~Integer() = default;
        QString toRaw(uint level = 0) override { return QString::number(value); }
        enum_v_type getType() override { return enum_v_type::integer; }
        void Accept(Visitor& v) override { v.VisitInteger(this); }

    public:
        long long value{ 0 };
    };

    class RobotAbbExport Boolean : public ASTNode
    {
    public:
        explicit Boolean(int const value) : boolVal(value) {}
        virtual ~Boolean() = default;
        QString toRaw(uint level = 0) override 
        { 
            if (boolVal)
                return "TRUE";
            else
                return "FALSE";
        }
        enum_v_type getType() override { return enum_v_type::boolean; }
        void Accept(Visitor& v) override { v.VisitBoolean(this); }

    public:
        int         boolVal{ 0 };
    };




    class RobotAbbExport ParamWithModifierNode : public ASTNode {
    public:
        //QString realName;
        ParamWithModifierNode(ASTNode* expression, ListNode<ASTNode>* dim);
        QVariant Execute() override;
        QString toRaw(uint level = 0) override;
        void Accept(Visitor& v) override { v.VisitParamWithModifier(this); }
    public:
        ListNode<ASTNode>* _dimRawType;
        ASTNode* _var_expr;
    };
}

#endif // ASTNODE_H
