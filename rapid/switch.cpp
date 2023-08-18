#include "switch.h"
#include "switch_case_list.h"
#include "casenode.h"

namespace Language
{
    SWitchNode::SWitchNode(ASTNode * expression, ASTNode * caseLists, ASTNode * defaultCase)
        : _caseLists(caseLists),
          _defaultCase(defaultCase),
          _expression(expression)
    {
    }

    QVariant SWitchNode::Execute()
    {
        int var = _expression->Execute().toInt();
        SWitchCaseListNode* caseLists = dynamic_cast<SWitchCaseListNode*> (_caseLists);

        if (!caseLists) return ASTNode::Execute();
        QMap<int, CaseNode*> key_values;
        for (auto it = caseLists->begin(); it != caseLists->end(); it++)
        {
            CaseNode* caseNode = dynamic_cast<CaseNode*>(*it);
            int key = caseNode->_expression->Execute().toInt();
            if (var == key)
            {
                return caseNode->Execute();
            }           
            //key_values.insert(key, caseNode);
        }

       
        /*
        QMap<int, CaseNode*>::iterator it;
        for (it=key_values.begin();it!=key_values.end();it++)
        {
          
        }*/
        //caseLists
    
        return ASTNode::Execute();
    }
    QString SWitchNode::toRaw(uint level)
    {
        QString str = "";
        return str;
    }
}
