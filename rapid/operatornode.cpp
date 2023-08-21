#include <iostream>
#include "operatornode.h"
#include "errors.h"



namespace Language
{
    OperatorNode::OperatorNode(token::yytokentype type, ASTNode * op1, ASTNode * op2)
        : _op1(op1),
        _op2(op2),
        _operator(type)
    {
        if (nullptr == op2)
            return;
        //token::TextType
        if ((_op1->getTypeName() == "string") || (_op2->getTypeName() == "string"))
        {
           if (_operator == token::ADD)
            {
                 _type = enum_v_type::string;
            }
           else if ((_operator != token::EQ) && (_operator != token::NE))
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
            case token::ASS: return _op1->Execute() = _op2->Execute(); break;
            case token::NOT: return !(_op1->Execute().toBool()); break;
            case token::LC:return _op1->Execute().toDouble(); break;
            case token::UMINUS: return -_op1->Execute().toDouble(); break;
            case token::ADD: 
            {
                //if ((_op1->Type() == token::TextType) || (_op1->Type() == token::TextType))
                //    return QString("%1%2").arg(_op1->Execute().toString()).arg(_op2->Execute().toString());
                return _op1->Execute().toDouble() + _op2->Execute().toDouble(); 
            } 
            break;
            case token::SUB: return _op1->Execute().toDouble() - _op2->Execute().toDouble(); break;
            case token::MUL: return _op1->Execute().toDouble() * _op2->Execute().toDouble(); break;
            //case token::DIV: return _op1->Execute().toDouble() / _op2->Execute().toDouble(); break;
            case token::LT: 
            {
             
                {
                    return _op1->Execute().toDouble() < _op2->Execute().toDouble();
                }
                break;
            }
            case token::GT: return _op1->Execute().toDouble() > _op2->Execute().toDouble();break;
            case token::GE: return _op1->Execute().toDouble() >= _op2->Execute().toDouble();break;
            case token::LE: return _op1->Execute().toDouble() <= _op2->Execute().toDouble();break;
            case token::NE: return _op1->Execute() != _op2->Execute();break;
            case token::EQ: return _op1->Execute() == _op2->Execute(); break;
            case token::AND:  return _op1->Execute().toBool() && _op2->Execute().toBool();break;
            case token::OR:  return _op1->Execute().toBool()|| _op2->Execute().toBool(); break;
            case token::MOD: return _op1->Execute().toInt(); break;
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
        case token::ASS:
        {
            QString temp = QString("%1 := %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
            break;
        case token::NOT:
        {
            QString temp = QString("NOT %1").arg(_op1->toRaw());
            str = temp;
        }
            break;
        case token::LC:
        {
            QString temp = QString("(%1)").arg(_op1->toRaw());
            str = temp;
        }
        break;
        case token::UMINUS:
        {
            QString temp = QString("%1%2").arg("-").arg(_op1->toRaw());
            str = temp;
        }
        break;
        case token::ADD:
        {
            QString temp = QString("%1 + %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::SUB:
        {
            QString temp = QString("%1 - %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::MUL:
        {
            QString temp = QString("%1 * %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        //case token::DIV: 
        //{
        //    QString temp = QString("%1 / %2").arg(_op1->toRaw()).arg(_op2->toRaw());
        //    str = temp;
        //}
        //    break;
        case token::LT:
        {

            {
                QString temp = QString("%1 < %2").arg(_op1->toRaw()).arg(_op2->toRaw());
                str = temp;
            }

        }
        break;
        case token::GT:
        {
            QString temp = QString("%1 > %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::GE:
        {
            QString temp = QString("%1 >= %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::LE:
        {
            QString temp = QString("%1 <= %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::NE:
        {
            QString temp = QString("%1 != %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::EQ:
        {
            QString temp = QString("%1 = %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::AND:
        {
            QString temp = QString("%1 and %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::OR:
        {
            QString temp = QString("%1 or %2").arg(_op1->toRaw()).arg(_op2->toRaw());
            str = temp;
        }
        break;
        case token::MOD:
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

