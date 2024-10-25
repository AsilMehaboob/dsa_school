#include<stdio.h>
#define max 100

char stack[max];
int top=-1;

int isempty()
{
    return top==-1;
}

int isfull()
{
    return top==max-1;
}

char peek()
{
    return stack[top];
}

char pop()
{
    if(isempty())
    {
        printf("Underflow");
    }
    else
    {
        char ch=stack[top];
        top--;
        return ch;
    }
}

void push(char oper)
{
    if(isfull())
    {
        printf("Full");
    }
    else
    {
        top++;
        stack[top]=oper;
    }
}

int checkoper(char ch)
{
    return ch>='a'&&ch<='z';
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}

int convert(char *expression)
{
    int i,j=0;
    char output[max];

    for(int i=0;expression[i]!='\0';i++)
    {
        char ch=expression[i];

        if(checkoper(ch))
            output[j++]=ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')')
        {
            while(!isempty()&&peek()!='(')
            {
                output[j++]=pop();
            }
            pop();
        }
        else
        {
            while (!isempty()&&precedence(peek())>=precedence(ch))      

            {
                output[j++]=pop();
            }
            push(ch);
            

        }

        
        
    }
    while (!isempty())
        {
            output[j++]=pop();
        }

        output[j]='\0';
        printf("%s",output);
}

void main()
{
    char expression[max];
    printf("enter");
    scanf("%s",expression);
    convert(expression);
}