//
// Created by yazda on 6/13/2019.
//

#include <dfa.h>
#include <debug.h>


state munch(state prev, char in_char)
{
    int out_trans = -1;
    switch (prev)
    {
        case START:
            slog("start -> ");
            if (is_letter(in_char)) 
            {
                slog("letter\n");
                out_trans = DEF;
            }
            else if (in_char == '0')
            {
                slog("zero\n");
                out_trans = ZERO;
            }
            else if (is_digit(in_char))
            {
                slog("digit\n");
                out_trans = NUM;
            }
            else if (is_whitespace(in_char))
            {
                slog("wspace\n");
                out_trans = WHITESPACE; // TODO : WRONG
            }
            else
            {
                switch (in_char)
                {
                    case '-':
                        out_trans = START;
                        slog("-\n");
                        break;
                    case '+':
                        out_trans = PLUS;
                        slog("+\n");
                        break;
                    case '}':
                        out_trans = RBRACE;
                        slog("}\n");
                        break;
                    case '{':
                        out_trans = LBRACE;
                        slog("{\n");
                        break;
                    case ']':
                        out_trans = RBRACK;
                        slog("]\n");
                        break;
                    case '[':
                        out_trans = LBRACK;
                        slog("[\n");
                        break;
                    case ')':
                        out_trans = RPAREN;
                        slog(")\n");
                        break;
                    case '(':
                        out_trans = LPAREN;
                        slog("(\n");
                        break;
                    case '=':
                        out_trans = BECOMES;
                        slog("=\n");
                        break;
                    case '!':
                        out_trans = BANG;
                        slog("!\n");
                        break;
                    case '<':
                        out_trans = LT;
                        slog("<\n");
                        break;
                    case '>':
                        out_trans = GT;
                        slog(">\n");
                        break;
                    case '*':
                        out_trans = STAR;
                        slog("*\n");
                        break;
                    case '%':
                        out_trans = PCT;
                        slog("%\n");
                        break;
                    case '&':
                        out_trans = AMP;
                        slog("&\n");
                        break;
                    case ',':
                        out_trans = COMMA;
                        slog(",\n");
                        break;
                    case ';':
                        out_trans = SEMI;
                        slog(";\n");
                        break;
                    case '/':
                        out_trans = COMMENT;
                        slog("/\n");
                        break;
                    default:
                        slog("default0\n");
                        break;
                }
            }
            break;
        case ZERO:
            slog("zero -> ");
            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit (invalid)\n");
                out_trans = INVALID;
            }
            else
            {
                slog("zeroend\n");
                out_trans = START;
            }
            break;
        case DEF:
            slog("def -> ");
            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit\n");
                out_trans = DEF;
            }
            else// if (is_whitespace(in_char))
            {
                slog("enddef\n");
                out_trans = START; // TODO : Is it correct?
            }
            break;
        case NUM:
            slog("num -> ");
            if (is_digit(in_char))
            {
                slog("digit\n");
                out_trans = NUM;
            }
            else if (is_letter(in_char))
            {
                slog("invalid\n");
                out_trans = INVALID;
            }
            else
            {
                slog("numend\n");
                out_trans = START;
            }
            break;
        case BECOMES:
            slog("becomes -> ");
            if (in_char == '=')
            {
                slog("=\n");
                out_trans = EQ;
            }
            else
            {
                slog("becend\n");
                out_trans = START;
            }
            break;
        case BANG:
            slog("bang -> ");
            if (in_char == '=')
            {
                slog("=\n");
                out_trans = NE;
            }
            else if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case LT:
            slog("lt -> ");
            if (in_char == '=')
            {
                slog("=\n");
                out_trans = LE;
            }
            else if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case GT:
            slog("gt -> ");
            if (in_char == '=')
            {
                slog("=\n");
                out_trans = GE;
            }
            else if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case EQ:
            slog("eq -> ");
            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case NE:
            slog("ne -> ");
            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case LE:
            slog("le -> ");
            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case GE:
            slog("ge -> ");
            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case COMMENT:
            slog("comment -> ");
            if (in_char != '\n')
            {
                slog("comment\n");
                out_trans = COMMENT;
            }
            break;
        case WHITESPACE:
            slog("wspace -> ");
            if (is_whitespace(in_char))
            {
                slog("wspace\n");
                out_trans = WHITESPACE;
            }
            else
            {
                slog("endspace\n");
                out_trans = START;
            }
            break;
        // TODO : case STAR
        case STAR:
            slog("star -> ");
            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            else if (is_whitespace(in_char))
            {
                slog("wspace\n");
                out_trans = STAR;
            }
            else
            {
                slog("endstar");
                out_trans = START;
            }
            break;
        case RBRACK:
            slog("rbrack -> ");
            slog("ctd\n");
            out_trans = START;
            break;
        case LBRACK:
            slog("lbrack -> ");
            slog("ctd\n");
            out_trans = START;
            break;
        case PLUS:
            slog("plus -> ");
            slog("plusend\n");
            out_trans = START;
            break;
        case MINUS:
            slog("minus -> ");
            slog("minudend\n");
            out_trans = START;
            break;
        case SEMI:
            slog("statement\n");
            out_trans = START;
        default:
            slog("default1 ");
            ilog(prev);
            slog("\n");
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
    
    return head_state == INVALID;
}

stateful_token *
maximal_munch(const stateless_token *tk)
{
    return NULL;
}

