//
// Created by yazda on 6/13/2019.
//

#include <dfa.h>
#include <debug.h>

state
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
    
    slog("\n");
    LLNODE *curr = start;
    while (curr != NULL)
    {
        TOKEN *currtk = (TOKEN *)(curr->data);
        if (currtk->meta != START) pretty_state(currtk->meta);
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

