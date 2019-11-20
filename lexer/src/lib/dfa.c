//
// Created by yazda on 6/13/2019.
//

#include <dfa.h>


state munch(state prev, char in_char)
{
    int out_trans = -1;
    switch (prev)
    {
        case START:
            if (is_letter(in_char)) out_trans = DEF;
            else if (in_char == '0') out_trans = ZERO;
            else if (is_digit(in_char)) out_trans = NUM;
            else if (is_whitespace(in_char)) out_trans = WHITESPACE; // TODO : WRONG
            else
            {
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
            break;
        case ZERO:
            if (is_letter_or_digit(in_char)) out_trans = INVALID;
            break;
        case DEF:
            if (is_letter_or_digit(in_char)) out_trans = DEF;

            // TODO : This could also mean end of DEF or something like that
            if (is_whitespace(in_char)) out_trans = START; // TODO : Is it correct?
            break;
        case NUM:
            if (is_digit(in_char)) out_trans = NUM;
            else out_trans = INVALID;
            break;
        case BECOMES:
            if (in_char == '=') out_trans = EQ;
            break;
        case BANG:
            if (in_char == '=') out_trans = NE;
            else if (is_sym(in_char)) out_trans = INVALID;
            break;
        case LT:
            if (in_char == '=') out_trans = LE;
            else if (is_sym(in_char)) out_trans = INVALID;
            break;
        case GT:
            if (in_char == '=') out_trans = GE;
            else if (is_sym(in_char)) out_trans = INVALID;
            break;
        case EQ:
            if (is_sym(in_char)) out_trans = INVALID;
            break;
        case NE:
            if (is_sym(in_char)) out_trans = INVALID;
            break;
        case LE:
            if (is_sym(in_char)) out_trans = INVALID;
            break;
        case GE:
            if (is_sym(in_char)) out_trans = INVALID;
            break;
        case COMMENT:
            if (in_char != '\n') out_trans = COMMENT;
            break;
        case WHITESPACE:
            if (is_whitespace(in_char)) out_trans = WHITESPACE;
            break;
        default:
            break;
    }

    return out_trans;
}

state
iterative_munch(LL_CHAR **chars)
{
    state head_state = START;
    LL_CHAR *head = *chars;
    while (head)
    {
        head_state = munch(head_state, head->val);
        head = head->next;
    }
    return -1;
}

stateful_token *
maximal_munch(const stateless_token *tk)
{
    return NULL;
}

