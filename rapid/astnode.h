#ifndef ASTNODE_H
#define ASTNODE_H

#include <QVariant>
#include "IAction.h"

#include "PreCompiled.h"
#include <boost/signals2.hpp>
#include "parser.tab.hpp"
typedef Language::Parser::token token;
#define SPACE " "
#define INTENT "    "

enum enum_v_type
{
    NUM = 1,
    eBOOL = 2,
    eSTRING = 3,
    ROBTARGET = 4,
    JOINTTARGET = 5,
    WOBJDATA = 6,
    ZONEDATA = 7,
    SPEEDDATA = 8,
    TOOLDATA = 9,
    SEAMDATA = 10,
    WELDDATA = 11,
    MOVEL,
    MOVEJ,
    ARCL,
    ARCLSTART,
    ARCEND,
    ARCC,
    ACTUNIT,
    CASE,
    DEACTUNIT,
    ELSEIF,
    FOR,
    FUNC,
    FUNC_CALL,
    GOTO,
    IDENTIFIER,
    LABEL,
    IF,
    MOVEABSJ,
    RETURN,
    SPEED,
    SWITCH,
    SWITCH_CASE_LIST,
    WHILE,
    PARAM,
    ARRAYDATA,
    CONC,
     TOOL_P,
     PLEN,
     MAXTIME,
     INPOS,
     TIMEFLAG,
     WOBJ_P,
     SEAM_NAME,
     ZONE_P,
     VEL_P,
     TCP_P,
     NOEOFFS,
     ID_P,
};

namespace Language
{
    //class ASTNode;
    //template <class T >
    //class ListNode : public ASTNode, public std::vector<T*>
    //{
    //public:
    //    ListNode() {}
    //    ListNode(T* node) { this->push_back(node); }
    //};
    class RobotAbbExport ASTNode : public  IAction
    {
    public:
        ASTNode(QString  type= QString::fromLatin1(""));
        virtual ~ASTNode();
        virtual QVariant Execute();
        virtual void compute() {}
        QString Type();
        virtual QString toString(uint level=0);
        //toPython
        virtual QString toRaw(uint level = 0);
    
        void SetPrefix(bool value) { _prefix = value; }
        //virtual QString toRaw(uint level = 0);


        boost::signals2::signal<void()> signalRunInst;
        boost::signals2::signal<void(ASTNode*)> signalParseInst;
    public:
        bool _prefix;
        QString _type;

    };
}

#endif // ASTNODE_H
