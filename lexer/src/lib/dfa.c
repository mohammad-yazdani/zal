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
            slog("(");
            chlog(in_char);
            slog(") ");
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
                out_trans = START;
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
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit (invalid)\n");
                out_trans = INVALID;
            }
            else // TODO : CHANGE to recursive
            {
                slog("zeroend\n");
                out_trans = START;
            }
            break;
        case DEF:
            slog("def -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_letter_or_digit(in_char))
            {
                slog("letter or digit\n");
                out_trans = DEF;
            }
            else if (is_whitespace(in_char))
            {
                slog("enddef\n");
                out_trans = START; // TODO : Is it correct?
            }
            else
            {
                slog("RECURSIVE:\n");
                out_trans = munch(START, in_char);
            }
            break;
        case NUM:
            slog("num -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case NE:
            slog("ne -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case LE:
            slog("le -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case GE:
            slog("ge -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case COMMENT:
            slog("comment -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char != '\n')
            {
                slog("comment\n");
                out_trans = COMMENT;
            }
            break;
        case WHITESPACE:
            slog("wspace -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            out_trans = START;
            break;
        case LBRACK:
            slog("lbrack -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            out_trans = START;
            break;
        case PLUS:
            slog("plus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("plusend\n");
            out_trans = START;
            break;
        case MINUS:
            slog("minus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("minudend\n");
            out_trans = START;
            break;
        case SEMI:
            slog("statement\n");
            slog("(");
            chlog(in_char);
            slog(") ");

            out_trans = START;
        default:
            slog("default1 ");
            slog("(");
            chlog(in_char);
            slog(") ");

            ilog(prev);
            slog("\n");
            break;
    }

    return out_trans;
}

state
iterative_munch(LL_CHAR *chars)
{
    state head_state = START;
    LL_CHAR *head = chars;
    LL_CHAR *head_token = create_LL_char(head_state);
    LL_CHAR *curr_token = head_token;

    while (head)
    {
        state old_state = head_state;
        head_state = munch(head_state, head->val);
        if (head_state == START)
        {
            curr_token = LL_push(curr_token, old_state);
        }
        head = head->next;
    }

    // TODO : TEST
    slog("\n");
    curr_token = head_token;
    while (curr_token != NULL)
    {
        pretty_state(curr_token->val);
        curr_token = curr_token->next;
    }
    
    return head_state == INVALID;
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
proto_munch(LL_CHAR *buff_head, LL_CHAR *state_head)
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
            return proto_munch(buff_head->next, state_head);
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
                return proto_munch(buff_head->next, state_head);
            }
            else if (is_whitespace(in_char))
            {
                slog("enddef\n");
                out_trans = START; // TODO : Is it correct?
            }
            else
            {
                slog("RECURSIVE:\n");
                out_trans = munch(START, in_char);
            }
            break;
        case NUM:
            slog("num -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case NE:
            slog("ne -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case LE:
            slog("le -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case GE:
            slog("ge -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (is_sym(in_char))
            {
                slog("sym (invalid)\n");
                out_trans = INVALID;
            }
            break;
        case COMMENT:
            slog("comment -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            if (in_char != '\n')
            {
                slog("comment\n");
                out_trans = COMMENT;
            }
            break;
        case WHITESPACE:
            slog("wspace -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

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
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            out_trans = START;
            break;
        case LBRACK:
            slog("lbrack -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("ctd\n");
            out_trans = START;
            break;
        case PLUS:
            slog("plus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("plusend\n");
            out_trans = START;
            break;
        case MINUS:
            slog("minus -> ");
            slog("(");
            chlog(in_char);
            slog(") ");

            slog("minudend\n");
            out_trans = START;
            break;
        case SEMI:
            slog("statement\n");
            slog("(");
            chlog(in_char);
            slog(") ");

            out_trans = START;
        default:
            slog("default1 ");
            slog("(");
            chlog(in_char);
            slog(") ");

            ilog(prev);
            slog("\n");
            break;
    }
}

