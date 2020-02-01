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
    STREAM *buffer = create_stream(chars);
    LL_CHAR *start = state_head;

    do
    {
        state_head = munch(buffer, state_head);
    } while (next(buffer));
    
    slog("\n");
    LL_CHAR *curr = start;
    while (curr != NULL)
    {
        if (curr->val != START) pretty_state(curr->val);
        curr = curr->next;
    }

    // return curr->val == INVALID; // TODO : FIX!!!
    return 0;
}

void
pretty_state(state s)
{
    switch (s)
    {
        case START:
            slog("START\n");
            break;
        case UNDEFINED:
            slog("UNDEFINED\n");
            break;
        case INVALID:
            slog("INVALID\n");
            break;
        case SPACE:
            slog("SPACE\n");
            break;
        case TAB:
            slog("TAB\n");
            break;
        case NEWLINE:
            slog("NEWLINE\n");
            break;
        case COMMENT:
            slog("COMMENT\n");
            break;
        case WHITESPACE:
            slog("WHITESPACE\n");
            break;
        case DEF:
            slog("DEF\n");
            break;
        case NUM:
            slog("NUM\n");
            break;
        case LPAREN:
            slog("LPAREN\n");
            break;
        case RPAREN:
            slog("RPAREN\n");
            break;
        case LBRACE:
            slog("LBRACE\n");
            break;
        case RBRACE:
            slog("RBRACE\n");
            break;
        case RETURN:
            slog("RETURN\n");
            break;
        case IF:
            slog("IF\n");
            break;
        case ELSE:
            slog("ELSE\n");
            break;
        case WHILE:
            slog("WHILE\n");
            break;
        case PRINTLN:
            slog("PRINTLN\n");
            break;
        case MAIN:
            slog("MAIN\n");
            break;
        case BECOMES:
            slog("BECOMES\n");
            break;
        case INT:
            slog("INT\n");
            break;
        case EQ:
            slog("EQ\n");
            break;
        case NE:
            slog("NE\n");
            break;
        case LT:
            slog("LT\n");
            break;
        case GT:
            slog("GT\n");
            break;
        case LE:
            slog("LE\n");
            break;
        case GE:
            slog("GE\n");
            break;
        case PLUS:
            slog("PLUS\n");
            break;
        case MINUS:
            slog("MINUS\n");
            break;
        case STAR:
            slog("STAR\n");
            break;
        case SLASH:
            slog("SLASH\n");
            break;
        case PCT:
            slog("PCT\n");
            break;
        case COMMA:
            slog("COMMA\n");
            break;
        case SEMI:
            slog("SEMI\n");
            break;
        case NEW:
            slog("NEW\n");
            break;
        case DELETE:
            slog("DELETE\n");
            break;
        case LBRACK:
            slog("LBRACK\n");
            break;
        case RBRACK:
            slog("RBRACK\n");
            break;
        case AMP:
            slog("AMP\n");
            break;
        case NULLL:
            slog("NULLL\n");
            break;
        case ZERO:
            slog("ZERO\n");
            break;
        case BANG:
            slog("BANG\n");
            break;
        default:
            slog("default\n");
            break;
    }
}

LL_CHAR *
munch(STREAM *buffer, LL_CHAR *state_head)
{
    if (buffer == NULL || state_head == NULL) return NULL;

    char in_char = buffer->cursor->val;
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
                    case '}':
                        state_head = LL_push(state_head, RBRACE);
                        state_head = LL_push(state_head, START);
                        slog("}\n");
                        break;
                    case '{':
                        state_head = LL_push(state_head, LBRACE);
                        state_head = LL_push(state_head, START);
                        slog("{\n");
                        break;
                    case ']':
                        state_head = LL_push(state_head, RBRACK);
                        state_head = LL_push(state_head, START);
                        slog("]\n");
                        break;
                    case '[':
                        state_head = LL_push(state_head, LBRACK);
                        state_head = LL_push(state_head, START);
                        slog("[\n");
                        break;
                    case ')':
                        state_head = LL_push(state_head, RPAREN);
                        state_head = LL_push(state_head, START);
                        slog(")\n");
                        break;
                    case '(':
                        state_head = LL_push(state_head, LPAREN);
                        state_head = LL_push(state_head, START);
                        slog("(\n");
                        break;
                    case ',':
                        state_head = LL_push(state_head, COMMA);
                        state_head = LL_push(state_head, START);
                        slog(",\n");
                        break;
                    case ';':
                        state_head = LL_push(state_head, SEMI);
                        state_head = LL_push(state_head, START);
                        slog(";\n");
                        break;
                    case '-':
                        state_head = LL_push(state_head, MINUS);
                        slog("-\n");
                        break;
                    case '+':
                        state_head = LL_push(state_head, PLUS);
                        slog("+\n");
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
                    case '/':
                        state_head = LL_push(state_head, COMMENT); // TODO : DIVIDE???
                        /*
                        if next is / then go to comment state, otherwise its a divide if
                        next is letter or digit
                        */
                        slog("/\n");
                        break;
                    default:
                        slog("default0\n");
                        break;
                }
            }
            if (!next(buffer))
            {
                return NULL;
            }
            chlog(buffer->cursor->val);
            slog("\n");
            return munch(buffer, state_head);
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
                slog("RECURSIVE:\n");
                return munch(buffer, LL_push(state_head, START));
            }
        case DEF:
            slog("def -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit\n");
                next(buffer);
                return munch(buffer, state_head);
            }
            else if (is_whitespace(in_char))
            {
                slog("enddef\n");
                return LL_push(state_head, START);
            }
            else
            {
                slog("RECURSIVE:\n");
                return munch(buffer, LL_push(state_head, START));
            }
        case NUM:
            slog("num -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_digit(in_char))
            {
                slog("digit\n");
                next(buffer);
                return munch(buffer, state_head);
            }
            else if (is_letter(in_char))
            {
                slog("invalid\n");
                return NULL;
            }
            else
            {
                slog("numend\n");
                return munch(buffer, LL_push(state_head, START));
            }
        case BECOMES:
            slog("becomes -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buffer, LL_push(state_head, EQ));
            }
            else
            {
                slog("becend\n");
                return munch(buffer, LL_push(state_head, START));
            }
        case BANG:
            slog("bang -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buffer, LL_push(state_head, NE));
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
                return munch(buffer, LL_push(state_head, LE));
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
                return munch(buffer, LL_push(state_head, GE));
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

            /*if (is_whitespace(in_char))
            {
                slog("wspace\n");
                next(buffer);
                return munch(buffer, state_head);
            }*/
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
            return munch(buffer, LL_push(state_head, START));
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

