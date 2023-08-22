#include <iostream>
#include "operatornode.h"
#include "errors.h"



namespace Language
{
    OperatorNode::OperatorNode(L_token::yytokentype type, ASTNode * op1, ASTNode * op2)
        : _op1(op1),
        _op2(op2),
        _operator(type)
    {
        if (nullptr == op2)
            return;
        //L_token::TextType
        if ((_op1->getTypeName() == "string") || (_op2->getTypeName() == "string"))
        {
           if (_operator == L_token::ADD)
            {
                 _type = enum_v_type::string;
            }
           else if ((_operator != L_token::EQ) && (_operator != L_token::NE))
            {
                //std::cout << NO_STRINGS_PLEASE << "(line: " << lineNumber << ")" << std::endl;
                //exit(EXIT_FAILURE);
            }
        }
    }


  
    QVariant OperatorNode::Execute()
    {
        switch(_operator)
        {
            case L_token::ASS: return _op1->Execute() = _op2->Execute(); break;
            case L_token::NOT: return !(_op1->Execute().toBool()); break;
            case L_token::LC:return _op1->Execute().toDouble(); break;
            case L_token::UMINUS: return -_op1->Execute().toDouble(); break;
            case L_token::ADD: 
            {
                //if ((_op1->Type() == L_token::TextType) || (_op1->Type() == L_token::TextType))
                //    return QString("%1%2").arg(_op1->Execute().toString()).arg(_op2->Execute().toString());
                return _op1->Execute().toDouble() + _op2->Execute().toDouble(); 
            } 
            break;
            case L_token::SUB: return _op1->Execute().toDouble() - _op2->Execute().toDouble(); break;
            case L_token::MUL: return _op1->Execute().toDouble() * _op2->Execute().toDouble(); break;
            //case L_token::DIV: return _op1->Execute().toDouble() / _op2->Execute().toDouble(); break;
            case L_token::LT: 
            {
             
                {
                    return _op1->Execute().toDouble() < _op2->Execute().toDouble();
                }
                break;
            }
            case L_token::GT: return _op1->Execute().toDouble() > _op2->Execute().toDouble();break;
            case L_token::GE: return _op1->Execute().toDouble() >= _op2->Execute().toDouble();break;
            case L_token::LE: return _op1->Execute().toDouble() <= _op2->Execute().toDouble();break;
            case L_token::NE: return _op1->Execute() != _op2->Execute();break;
            case L_token::EQ: return _op1->Execute() == _op2->Execute(); break;
            case L_token::AND:  return _op1->Execute().toBool() && _op2->Execute().toBool();break;
            case L_token::OR:  return _op1->Execute().toBool()|| _op2->Execute().toBool(); break;
            case L_token::MOD: return _op1->Execute().toInt(); break;
            default: 
                std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
                exit(EXIT_FAILURE);
        }

        return QVariant();
    }


    QString OperatorNode::toRaw(uint level)
    {
        QString str = "";
        switch (_operator)
        {
        case L_token::ASS:
        {
            QString temp = QString("%1 := %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
            break;
        case L_token::NOT:
        {
            QString temp = QString("NOT %1").arg(_op1->toRaw());
            str = temp;
        }
            break;
        case L_token::LC:
        {
            QString temp = QString("(%1)").arg(_op1->toRaw());
            str = temp;
        }
        break;
        case L_token::UMINUS:
        {
            QString temp = QString("%1%2").arg("-").arg(_op1->toRaw());
            str = temp;
        }
        break;
        case L_token::ADD:
        {
            QString temp = QString("%1 + %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::SUB:
        {
            QString temp = QString("%1 - %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::MUL:
        {
            QString temp = QString("%1 * %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        //case L_token::DIV: 
        //{
        //    QString temp = QString("%1 / %2").arg(_op1->toRaw()).arg(_op2->toRaw());
        //    str = temp;
        //}
        //    break;
        case L_token::LT:
        {

            {
                QString temp = QString("%1 < %2").arg(_op1->toRaw()).arg(_op2->toRaw());
                str = temp;
            }

        }
        break;
        case L_token::GT:
        {
            QString temp = QString("%1 > %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::GE:
        {
            QString temp = QString("%1 >= %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::LE:
        {
            QString temp = QString("%1 <= %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::NE:
        {
            QString temp = QString("%1 != %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::EQ:
        {
            QString temp = QString("%1 = %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::AND:
        {
            QString temp = QString("%1 and %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::OR:
        {
            QString temp = QString("%1 or %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case L_token::MOD:
        {
            QString temp = QString("%1 % %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        default: std::cerr << "Damn ! Looks like we forgot to implement something..." << std::endl;
            exit(EXIT_FAILURE);
        }
        return str;
    } 
}

