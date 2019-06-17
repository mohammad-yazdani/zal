//
// Created by yazda on 6/13/2019.
//

#include <dfa.h>
#include <str/str_helper.h>

enum
CX_ACCEPTING transition(enum CX_ACCEPTING state, char in_char)
{
    int out_trans = INVALID;
    switch (state)
    {
        case START:
            if (is_letter(in_char)) out_trans = ID;
            else if (in_char == '0') out_trans = ZERO;
            else if (is_digit(in_char)) out_trans = NUM;
            else if (is_whitespace(in_char)) out_trans = WHITESPACE; // TODO : WRONG
            else {
                switch (in_char)
                {
                    case '-':
                        out_trans = START;
                        break;
                    case '+':
                        out_trans = PLUS;
                        break;
                    case '}':
                        out_trans = RBRACE;
                        break;
                    case '{':
                        out_trans = LBRACE;
                        break;
                    case ']':
                        out_trans = RBRACK;
                        break;
                    case '[':
                        out_trans = LBRACK;
                        break;
                    case ')':
                        out_trans = RPAREN;
                        break;
                    case '(':
                        out_trans = LPAREN;
                        break;
                    case '=':
                        out_trans = BECOMES;
                        break;
                    case '!':
                        out_trans = BANG;
                        break;
                    case '<':
                        out_trans = LT;
                        break;
                    case '>':
                        out_trans = GT;
                        break;
                    case '*':
                        out_trans = STAR;
                        break;
                    case '%':
                        out_trans = PCT;
                        break;
                    case '&':
                        out_trans = AMP;
                        break;
                    case ',':
                        out_trans = COMMA;
                        break;
                    case ';':
                        out_trans = SEMI;
                        break;
                    case '/':
                        out_trans = COMMENT;
                        break;
                    default:break;
                }
            }
        case ZERO:
            if (is_letter_or_digit(in_char)) out_trans = INVALID;
            break;
        case ID:
            if (is_letter_or_digit(in_char)) out_trans = ID;
            break;
        case NUM:
            if (is_digit(in_char)) out_trans = NUM;
            else out_trans = INVALID;
            break;
        case BECOMES:
        case BANG:
        case LT:
        case GT:
        case EQ:
        case NE:
        case LE:
        case GE:
        case COMMENT:
        case WHITESPACE:
        default:
            break;
    }

    return out_trans;
}