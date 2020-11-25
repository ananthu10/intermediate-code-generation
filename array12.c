#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20
#define Blank ' '
#define Tab '\t'
#define MAX 100


typedef struct node

{ char data;
char result[size];
char ope;
char opr1[1000];
char opr2[size];
int flag;
struct node *left;

struct node *right;

}btree;

btree *stack[size];

int top1;
btree *root;
char exp[80];
btree *create(char exp[80]);
void postorder(btree *root);


long int pop ();
char expression[MAX], syntaxtree[MAX];
long int stack1[MAX];
int top;
int white_space(char);
int prec(char);
void main()
{
long int value;

/*
char choice='y';

while(choice == 'y')
{
*/

top = 0;
printf("Enter Expression : ");
fflush(stdin);
gets(expression);
expression_to_syntaxtree();


top1=-1;
root=create(syntaxtree);
printf("\n");
postorder(root);



/*
printf("\n Want to continue(y/n) : ");
scanf("%c",&choice);
}
*/


}

expression_to_syntaxtree()
{
int i,p=0,type,precedence,len;
char next ;
stack[top]='#';
len=strlen(expression);
expression[len]='#';
for(i=0; expression[i]!='#';i++)
{
if( !white_space(expression[i]))
{
switch(expression[i])
{
case '(':
push(expression[i]);
break;

case ')':
while((next = pop()) != '(')
syntaxtree[p++] = next;
break;
case '+':
case '-':
case '*':
case '/':
case '%':
case '=':
case '^':
precedence = prec(expression[i]);
while(stack[top]!='#' && precedence<= prec(stack[top]))
syntaxtree[p++] = pop();
push(expression[i]);
break;
default:
syntaxtree[p++] = expression[i];
}
}
}
while(stack[top]!='#')
syntaxtree[p++] = pop();
syntaxtree[p] = '\0' ;
}

prec(char symbol )
{
switch(symbol)
{
case '(':
return 0;
case '+':
case '-':
return 1;
case '*':
case '/':
case '%':
return 2;
case '^':
return 3;
case '=':
return -1;
}
}

push(long int symbol)
{
if(top > MAX)
{
printf("Stack overflow\n");
exit(1);
}
else
{
top=top+1;
stack[top] = symbol;
}
}

long int pop()
{
if (top == -1 )
{
printf("Stack underflow \n");
exit(2);
}
else
return (stack[top--]);
}

white_space(char symbol)
{
if( symbol == Blank || symbol == Tab || symbol == '\0')
return 1;
else
return 0;
}

btree *create(char exp[])

{

btree *temp;

int pos;

char ch;


void push1(btree*);

btree *pop1();

pos=0;

ch=exp[pos];

while(ch!='\0')

{


temp=((btree*)malloc(sizeof(btree)));

temp->left=temp->right=NULL;

temp->data=ch;
temp->flag=0;

if(isalpha(ch))

push1(temp);

else if(ch=='+' ||ch=='-' || ch=='*' || ch=='/' || ch=='=')

{ temp->right=pop1();

temp->left=pop1();

push1(temp);

}
 else

printf("\n Invalid char Expression\n");

pos++;

ch=exp[pos];

}

 temp=pop1();

return(temp);

}

void push1(btree *Node)

{

if(top1+1

>=size)

printf("Error:Stack is full\n");

top1++;

stack[top1]=Node;

}

btree* pop1()

{

btree *Node;

if(top1==-1)

printf("\nerror: stack is empty..\n");

Node =stack[top1];

top1--;
return(Node);

}

int z=49;
void postorder(btree *root)

{

btree *temp;

temp=root;

if(temp!=NULL)

{
postorder(temp->left);

postorder(temp->right);

if((temp->data == '+' ) || temp->data =='-' || temp->data =='*' || temp->data =='/' || temp->data =='=')
    {
 temp->result[0]='T';


 temp->result[1]=(char)z;



 z=z+1;
 temp->flag=1;
 temp->ope=temp->data;

 if( ((temp->left)->data=='+' ) ||(temp->left)->data=='-' || (temp->left)->data=='*' || (temp->left)->data=='/' || (temp->left)->data=='='  && ((temp->left)->flag == 1) )
 {

     temp->opr1[0]=(temp->left)->result[0];
     temp->opr1[1]=(temp->left)->result[1];
 }

 else
 {
      temp->opr1[0]=(temp->left)->data;
 }


 if( ((temp->right)->data=='+' ) ||(temp->right)->data=='-' || (temp->right)->data=='*' || (temp->right)->data=='/' || (temp->right)->data=='='  && ((temp->right)->flag == 1) )
 {
     temp->opr2[0]=(temp->right)->result[0];
     temp->opr2[1]=(temp->right)->result[1];
 }

 else
 {
      temp->opr2[0]=(temp->right)->data;
 }


if(temp->data=='=')
  printf("%s %c %s \n",temp->opr1, temp->ope,temp->opr2);
else
 printf("%s = %s %c %s \n",temp->result, temp->opr1, temp->ope,temp->opr2);

}

}}

