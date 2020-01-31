//
// Created by yazda on 6/13/2019.
//

#include <dfa.h>
#include <debug.h>

state
iterative_munch(LL_CHAR *chars)
{
    state start_state = START;
    LL_CHAR *state_head = create_LL_char(start_state);
    state_head = munch(chars, state_head);

    // TODO : TEST
    slog("\n");
    LL_CHAR* curr_token = state_head;
    while (curr_token != NULL)
    {
        pretty_state(curr_token->val);
        curr_token = curr_token->next;
    }
    
    return state_head->val == INVALID;
}

stateful_token *
maximal_munch(const stateless_token *tk)
{
    return NULL;
}

void
pretty_state(state s)
{
    switch (s)
    {
        case START:
            slog("start\n");
            break;
        case ZERO:
            slog("zero\n");
            break;
        case DEF:
            slog("def\n");
            break;
        case NUM:
            slog("num\n");
            break;
        case BECOMES:
            slog("becomes\n");
            break;
        case BANG:
            slog("bang\n");
            break;
        case LT:
            slog("lt\n");
            break;
        case GT:
            slog("gt\n");
            break;
        case EQ:
            slog("eq\n");
            break;
        case NE:
            slog("ne\n");
            break;
        case LE:
            slog("le\n");
            break;
        case GE:
            slog("ge\n");
            break;
        case COMMENT:
            slog("comment\n");
            break;
        case WHITESPACE:
            slog("wspace\n");
            break;
        case STAR:
            slog("star\n");
            break;
        case RBRACK:
            slog("rbrack\n");
            break;
        case LBRACK:
            slog("lbrack\n");
            break;
        case PLUS:
            slog("plus\n");
            break;
        case MINUS:
            slog("minus\n");
            break;
        case SEMI:
            slog("statement\n");
            break;
        default:
            slog("default\n");
            break;
    }
}

LL_CHAR *
munch(LL_CHAR *buff_head, LL_CHAR *state_head)
{
    if (buff_head == NULL || state_head == NULL) return NULL;

    char in_char = buff_head->val;
    state prev = state_head->val;
    switch (prev)
    {
        case START:
            slog("start -> ");
            slog("(");
            chlog(in_char);
            slog(") ");
            if (is_letter(in_char)) 
            {
                slog("letter\n");
                state_head = LL_push(state_head, DEF);
            }
            else if (in_char == '0')
            {
                slog("zero\n");
                state_head = LL_push(state_head, ZERO);
            }
            else if (is_digit(in_char))
            {
                slog("digit\n");
                state_head = LL_push(state_head, NUM);
            }
            else if (is_whitespace(in_char))
            {
                slog("wspace\n");
            }
            else
            {
                switch (in_char)
                {
                    case '-':
                        state_head = LL_push(state_head, MINUS);
                        slog("-\n");
                        break;
                    case '+':
                        state_head = LL_push(state_head, PLUS);
                        slog("+\n");
                        break;
                    case '}':
                        state_head = LL_push(state_head, RBRACE);
                        slog("}\n");
                        break;
                    case '{':
                        state_head = LL_push(state_head, LBRACE);
                        slog("{\n");
                        break;
                    case ']':
                        state_head = LL_push(state_head, RBRACK);
                        slog("]\n");
                        break;
                    case '[':
                        state_head = LL_push(state_head, LBRACK);
                        slog("[\n");
                        break;
                    case ')':
                        state_head = LL_push(state_head, RPAREN);
                        slog(")\n");
                        break;
                    case '(':
                        state_head = LL_push(state_head, LPAREN);
                        slog("(\n");
                        break;
                    case '=':
                        state_head = LL_push(state_head, BECOMES);
                        slog("=\n");
                        break;
                    case '!':
                        state_head = LL_push(state_head, BANG);
                        slog("!\n");
                        break;
                    case '<':
                        state_head = LL_push(state_head, LE);
                        slog("<\n");
                        break;
                    case '>':
                        state_head = LL_push(state_head, GE);
                        slog(">\n");
                        break;
                    case '*':
                        state_head = LL_push(state_head, STAR);
                        slog("*\n");
                        break;
                    case '%':
                        state_head = LL_push(state_head, PCT);
                        slog("%\n");
                        break;
                    case '&':
                        state_head = LL_push(state_head, AMP);
                        slog("&\n");
                        break;
                    case ',':
                        state_head = LL_push(state_head, COMMA);
                        slog(",\n");
                        break;
                    case ';':
                        state_head = LL_push(state_head, SEMI);
                        slog(";\n");
                        break;
                    case '/':
                        state_head = LL_push(state_head, COMMENT); // TODO : DIVIDE???
                        slog("/\n");
                        break;
                    default:
                        slog("default0\n");
                        break;
                }
            }
            return munch(buff_head->next, state_head);
        case ZERO:
            slog("zero -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit (invalid)\n");
                return NULL;
            }
            else // TODO : CHANGE to recursive
            {
                slog("zeroend\n");
                return LL_push(state_head, ZERO);
            }
        case DEF:
            slog("def -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit\n");
                return munch(buff_head->next, state_head);
            }
            else if (is_whitespace(in_char))
            {
                slog("enddef\n");
                return LL_push(state_head, START);
            }
            else
            {
                slog("RECURSIVE:\n");
                return munch(LL_push(state_head, START), buff_head);
            }
        case NUM:
            slog("num -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_digit(in_char))
            {
                slog("digit\n");
                return munch(buff_head->next, state_head);
            }
            else if (is_letter(in_char))
            {
                slog("invalid\n");
                return NULL;
            }
            else
            {
                slog("numend\n");
                return LL_push(state_head, START);
            }
        case BECOMES:
            slog("becomes -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buff_head, LL_push(state_head, EQ));
            }
            else
            {
                slog("becend\n");
                return LL_push(state_head, START);
            }
        case BANG:
            slog("bang -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buff_head, LL_push(state_head, NE));
            }
            return LL_push(state_head, START);
        case LT:
            slog("lt -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buff_head, LL_push(state_head, LE));
            }
            return LL_push(state_head, START);
        case GT:
            slog("gt -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buff_head, LL_push(state_head, GE));
            }
            return LL_push(state_head, START);
        case EQ:
            slog("eq -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                return NULL;
            }
            return LL_push(state_head, START);
        case NE:
            slog("ne -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                return NULL;
            }
            return LL_push(state_head, START);
        case LE:
            slog("le -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                return NULL;
            }
            return LL_push(state_head, START);
        case GE:
            slog("ge -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                return NULL;
            }
            return LL_push(state_head, START);
        case COMMENT:
            slog("comment -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char != '\n')
            {
                slog("comment\n");
                return NULL;
            }
            return LL_push(state_head, START);
        case WHITESPACE:
            slog("wspace -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_whitespace(in_char))
            {
                slog("wspace\n");
                return munch(buff_head->next, state_head);
            }
            return LL_push(state_head, START);
        // TODO : case STAR
        case STAR:
            slog("star -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                return NULL;
            }
            return LL_push(state_head, START);
        case RBRACK:
            slog("rbrack -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            return LL_push(state_head, START);
        case LBRACK:
            slog("lbrack -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            return LL_push(state_head, START);
        case PLUS:
            slog("plus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("plusend\n");
            return LL_push(state_head, START);
        case MINUS:
            slog("minus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("minudend\n");
            return LL_push(state_head, START);
        case SEMI:
            slog("statement\n");
            slog("(");
            chlog(in_char);
            slog(") ");

            return LL_push(state_head, START);
        default:
            slog("default1 ");
            slog("(");
            chlog(in_char);
            slog(") ");

            ilog(prev);
            slog("\n");
            return NULL;
    }
}

