//Exercise 4-4. Add the commands to print the top elements of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
/*
 * Author: Yepuri Siddu
 * Created: 17 April, 2024
 * Modified: 17 April, 2024
 * */
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
void swap(void);
void duplicate(void);
void top(void);
void clear(void);
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double stack[MAXVAL]; /* value stack */
/* reverse Polish calculator */
int main()
{
        int type;
        double op2;
        char s[MAXOP];
        while ((type = getop(s)) != EOF) {
                switch (type) {
                        case NUMBER:
                                push(atof(s));
                                break;
                        case '+':
                                push(pop() + pop());
                                break;
                        case '*':
                                push(pop() * pop());
                                break;
                        case '-':
                                op2 = pop();
                                push(pop() - op2);
                                break;
                        case '/': op2 = pop();
                                if (op2 != 0.0)
                                        push(pop() / op2);
                                else
                                        printf("error: zero divisor\n");
                                break;
                        case '%': op2 = pop();
                                if (op2 != 0.0)
                                        push((int)pop() % (int)op2);
                                else
                                        printf("error: zero divisor\n");
                                break;
                        case 's':swap();
                                 break;
                        case 'd':duplicate();
                                 break;
                        case 't': top();
                                  break;
                        case 'c': clear();
                                  break;
                        case '\n':
                                printf("\t%.8g\n", pop());
                                break;
                        default:
                                printf("error: unknown command %s\n", s);
                                break;
                }
        }
        return 0;
}
void swap(void)
{
        double tmp1=pop();
        double tmp2=pop();
        push(tmp1);
        push(tmp2);
}

void duplicate(void)
{
        double tmp1=pop();
        push(tmp1);
        push(tmp1);
}
void top(void)
{
        printf("Top:%f\n",stack[sp-1]);
}
void clear(void)
{
        while(sp>0)
        {
                stack[--sp]=0.0;
        }
}

/* push: push f onto value stack */
void push(double f)
{
        if (sp < MAXVAL)
                stack[sp++] = f;
        else
                printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
        if (sp > 0)
                return stack[--sp];
        else {
                printf("error: stack empty\n");
                return 0.0;
        }
}

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
        int i, c;
        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';
        if (!isdigit(c) && c != '.')
                return c; /* not a number */
        i = 0;
        if (isdigit(c)) /* collect integer part */
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.') /* collect fraction part */
                        while (isdigit(s[++i] = c = getch()))
                                ;
        s[i] = '\0';
        if (c != EOF)
                ungetch(c);
        return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}
