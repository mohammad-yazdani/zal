//
// Created by yazda on 6/13/2019.
//

#include <dfa.h>
#include <debug.h>

LLNODE *
iterative_munch(LLNODE *chars)
{
    TOKEN *starttk = create_token(NULL, START);
    LLNODE *state_head = create_LLNODE(starttk);
    STREAM *buffer = create_stream(chars);
    LLNODE *start = state_head;

    do
    {
        state_head = munch(buffer, state_head);
    } while (next(buffer)); 

    return start;
}

const char*
pretty_state(state s)
{
    switch (s)
    {
        case START:
            return "START";
        case UNDEFINED:
            return "UNDEFINED";
        case INVALID:
            return "INVALID";
        case SPACE:
            return "SPACE";
        case TAB:
            return "TAB";
        case NEWLINE:
            return "NEWLINE";
        case COMMENT:
            return "COMMENT";
        case WHITESPACE:
            return "WHITESPACE";
        case DEF:
            return "DEF";
        case NUM:
            return "NUM";
        case LPAREN:
            return "LPAREN";
        case RPAREN:
            return "RPAREN";
        case LBRACE:
            return "LBRACE";
        case RBRACE:
            return "RBRACE";
        case RETURN:
            return "RETURN";
        case IF:
            return "IF";
        case ELSE:
            return "ELSE";
        case WHILE:
            return "WHILE";
        case PRINTLN:
            return "PRINTLN";
        case MAIN:
            return "MAIN";
        case BECOMES:
            return "BECOMES";
        case INT:
            return "INT";
        case EQ:
            return "EQ";
        case NE:
            return "NE";
        case LT:
            return "LT";
        case GT:
            return "GT";
        case LE:
            return "LE";
            break;
        case GE:
            return "GE";
        case PLUS:
            return "PLUS";
        case MINUS:
            return "MINUS";
        case STAR:
            return "STAR";
        case SLASH:
            return "SLASH";
        case PCT:
            return "PCT";
        case COMMA:
            return "COMMA";
        case SEMI:
            return "SEMI";
        case NEW:
            return "NEW";
        case DELETE:
            return "DELETE";
        case LBRACK:
            return "LBRACK";
        case RBRACK:
            return "RBRACK";
        case AMP:
            return "AMP";
        case NULLL:
            return "NULLL";
        case ZERO:
            return "ZERO";
        case BANG:
            return "BANG";
        default:
            return "default";
    }
}

LLNODE *
marktk(LLNODE *state_head, state newstate, LLNODE *endchar)
{
    TOKEN *newtk = create_token(endchar, newstate);
    LLNODE *newchain = LL_push(state_head, newtk);
    return newchain;
}

LLNODE *
endtk(LLNODE *state_head)
{
    TOKEN *newtk = create_token(NULL, START);
    LLNODE *newchain = LL_push(state_head, newtk);
    return newchain;
}

LLNODE *
munch(STREAM *buffer, LLNODE *state_head)
{
    if (buffer == NULL || state_head == NULL) return NULL;

    char in_char = *(char *)(buffer->cursor->data);
    state prev = ((TOKEN *)(state_head->data))->meta;
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
                state_head = marktk(state_head, DEF, buffer->cursor);
            }
            else if (in_char == '0')
            {
                slog("zero\n");
                state_head = marktk(state_head, ZERO, buffer->cursor);
            }
            else if (is_digit(in_char))
            {
                slog("digit\n");
                state_head = marktk(state_head, NUM, buffer->cursor);
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
                        state_head = marktk(state_head, RBRACE, buffer->cursor);
                        state_head = endtk(state_head);
                        slog("}\n");
                        break;
                    case '{':
                        state_head = marktk(state_head, LBRACE, buffer->cursor);
                        state_head = endtk(state_head);
                        slog("{\n");
                        break;
                    case ']':
                        state_head = marktk(state_head, RBRACK, buffer->cursor);
                        state_head = endtk(state_head);
                        slog("]\n");
                        break;
                    case '[':
                        state_head = marktk(state_head, LBRACK, buffer->cursor);
                        state_head = endtk(state_head);
                        slog("[\n");
                        break;
                    case ')':
                        state_head = marktk(state_head, RPAREN, buffer->cursor);
                        state_head = endtk(state_head);
                        slog(")\n");
                        break;
                    case '(':
                        state_head = marktk(state_head, LPAREN, buffer->cursor);
                        state_head = endtk(state_head);
                        slog("(\n");
                        break;
                    case ',':
                        state_head = marktk(state_head, COMMA, buffer->cursor);
                        state_head = endtk(state_head);
                        slog(",\n");
                        break;
                    case ';':
                        state_head = marktk(state_head, SEMI, buffer->cursor);
                        state_head = endtk(state_head);
                        slog(";\n");
                        break;
                    case '-':
                        state_head = marktk(state_head, MINUS, buffer->cursor);
                        slog("-\n");
                        break;
                    case '+':
                        state_head = marktk(state_head, PLUS, buffer->cursor);
                        slog("+\n");
                        break;
                    case '=':
                        state_head = marktk(state_head, BECOMES, buffer->cursor);
                        slog("=\n");
                        break;
                    case '!':
                        state_head = marktk(state_head, BANG, buffer->cursor);
                        slog("!\n");
                        break;
                    case '<':
                        state_head = marktk(state_head, LE, buffer->cursor);
                        slog("<\n");
                        break;
                    case '>':
                        state_head = marktk(state_head, GE, buffer->cursor);
                        slog(">\n");
                        break;
                    case '*':
                        state_head = marktk(state_head, STAR, buffer->cursor);
                        slog("*\n");
                        break;
                    case '%':
                        state_head = marktk(state_head, PCT, buffer->cursor);
                        slog("%\n");
                        break;
                    case '&':
                        state_head = marktk(state_head, AMP, buffer->cursor);
                        slog("&\n");
                        break; 
                    case '/':
                        state_head = marktk(state_head, COMMENT, buffer->cursor); // TODO : DIVIDE???
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
            chlog(*(char *)(buffer->cursor->data));
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
                return munch(buffer, endtk(state_head));
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
                return endtk(state_head);
            }
            else
            {
                slog("RECURSIVE:\n");
                return munch(buffer, endtk(state_head));
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
                return munch(buffer, endtk(state_head));
            }
        case BECOMES:
            slog("becomes -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buffer, marktk(state_head, EQ, buffer->cursor));
            }
            else
            {
                slog("becend\n");
                return munch(buffer, endtk(state_head));
            }
        case BANG:
            slog("bang -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buffer, marktk(state_head, NE, buffer->cursor));
            }
            return endtk(state_head);
        case LT:
            slog("lt -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buffer, marktk(state_head, LE, buffer->cursor));
            }
            return endtk(state_head);
        case GT:
            slog("gt -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char == '=')
            {
                slog("=\n");
                return munch(buffer, marktk(state_head, GE, buffer->cursor));
            }
            return endtk(state_head);
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
            return endtk(state_head);
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
            return endtk(state_head);
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
            return endtk(state_head);
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
            return endtk(state_head);
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
            return endtk(state_head);
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
            return endtk(state_head);
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
            return endtk(state_head);
        case RBRACK:
            slog("rbrack -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            return endtk(state_head);
        case LBRACK:
            slog("lbrack -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            return endtk(state_head);
        case PLUS:
            slog("plus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("plusend\n");
            return munch(buffer, endtk(state_head));
        case MINUS:
            slog("minus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("minudend\n");
            return endtk(state_head);
        case SEMI:
            slog("statement\n");
            slog("(");
            chlog(in_char);
            slog(") ");

            return endtk(state_head);
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


void
slog_wrapper(const char *msg)
{
    slog((char *)msg);
}

