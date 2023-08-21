#ifndef VARIABLERECORD_H
#define VARIABLERECORD_H
#include "PreCompiled.h"

namespace Language
{


    enum RobotAbbExport enum_v_type
    {
        Not_found = 0,
        expression,
        variable,
        klass,
        function,
        integer,
        decimal,
        string,
        boolean,
        identifier,


        ROBTARGET,
        JOINTTARGET,
        WOBJDATA,
        ZONEDATA,
        SEAMDATA,
        TOOLDATA,
        SPEEDDATA,
        WELDDATA,
        MOVEL,
        MOVEJ,
    };

    typedef RobotAbbExport struct VR
    {
        QVariant value;
        //_type
        QString var_type;
        //variableType
        enum_v_type type;

    } VariableRecord;
}

#endif // VARIABLERECORD_H
