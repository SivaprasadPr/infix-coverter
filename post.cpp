#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
#define MAX 15
using namespace std;
int getPrecedence(char);
class stack
{
    char stk[MAX];
    int top;
    public:
    void push(char);
    int getHighest();
    char pop();
    int sp(){return top;}
    stack()
    {
        top=-1;
    } 
};

void stack :: push(char op)
{
    if(top == MAX-1){cout<<"\n The stack is full";
    getch();}
    else
    {
        top++;
        stk[top]=op;
    }
    
}
char stack :: pop()
{
    char op;
    if(top==-1)
    {
        cout<<"\n Underflow";
        getch();
    }
    else
    {
        op = stk[top];
        top--;
        return op;
    }
    
}
int stack :: getHighest()          //Returns the highest operator precedence in the stack
{   
    int val =0,i,j;
    if(top!=-1){
    
     for(i=top;i>-1;--i)
     {
         if((getPrecedence(stk[i])>val) && ((stk[i]!='(')&& (stk[i]!=')') ))
         {val=getPrecedence(stk[i]);}
         if((stk[i]!='('))
         break;
     }
     if(stk[i]=='(')
     {
         for(j=i+1;j<=top;++j)
         {
              if(getPrecedence(stk[j])>val)
              val=getPrecedence(stk[j]);
         }
     }
     
     return val;
     
}}
int getPrecedence(char op)    //Returns the precedence of the operator passed as parameter
{
         if(op == '-' || op == '+'){return 1;}
    else if(op == '/' || op == '*'){return 2;}
    else if(op == '^' || op == '$'){return 3;}
    else if(op == '('){return 4;}
    else if(op == ')'){return 5;}
   // else if(op == '='){return 6;}
    else{return 0;}
}
int main()
{
    char post[30],exp[30];
    stack s;
    char item;
    int len,choice,i,pre,highest=0;
    cout<<"\nRules\n-----\n* Please enter the expression only in arbitrary form."<<endl;
    cout<<"* Only enter infix notation otherwise your output will be error|wrong."<<endl;
    cout<<"* Uses the ordinary algorithm";
    cout<<"* I can only convert infix -> postfix.\n----------------------------------"<<endl;
    do
    {
        cout<<"Options available\n---------------------"<<endl;
        cout<<"1. Infix -> Postfix converter"<<endl;
        cout<<"2. Infix -> Prefix converter"<<endl;
        cout<<"3. Exit\n------------------"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"\nEnter the expression: ";
            cin>>exp;int k;
            cout<<"\n the expression: ";puts(exp);
            len = strlen(exp);
            //exp[len]='=';
            i=0;int j=0,highest= s.getHighest();
           // cout<<"\n Modified expression is : "<<exp<<endl;
            while (i<len)
            {
                pre = getPrecedence(exp[i]);
                switch(pre)
                {
                    case 0:post[j]=exp[i];j++;cout<<endl<<exp[i]<<endl;break;
                    case 1:if(highest>=1){
                           for(k=s.sp();k>-1;k--)
                           {
                               item =s.pop();cout<<endl<<item<<endl; post[j]=item;++j;
                               if(getPrecedence(item) == highest)
                               {
                                   break;
                               }

                           }
                           highest = 1;
                          
                           s.push(exp[i]);
                           }
                           else{s.push(exp[i]);}highest=s.getHighest();cout<<endl<<exp[i]<<endl;break;
                    case 2:if(highest>=2){
                           for(k=s.sp();k>-1;k--)
                           {
                               char ch=s.pop(); post[j]=ch;j++;
                               if(getPrecedence(ch) == highest)
                               {
                                   break;
                               }

                           }
                           highest =2; 
                          
                           s.push(exp[i]);
                           }
                           else{s.push(exp[i]);}highest=s.getHighest();cout<<endl<<exp[i]<<endl;break;
                    case 3:if(highest>=3){
                           for(k=s.sp();k>-1;k--)
                           {
                               char ch=s.pop(); post[j]=ch;j++;
                               if(getPrecedence(ch) == highest)
                               {
                                   break;
                               }

                           }
                           highest =3; 
                          
                           s.push(exp[i]);
                           }
                           else{s.push(exp[i]);}highest=s.getHighest();cout<<endl<<exp[i]<<endl;break;
                    case 4:s.push(exp[i]);highest=0;cout<<endl<<exp[i]<<endl;break;
                    case 5: cout<<endl<<exp[i]<<endl;
                           while(item !='(')
                            {
                                item = s.pop();
                                if(item=='(') {break;}
                                post[j]=item;
                                j++;
                            }highest = s.getHighest();cout<<endl<<exp[i]<<endl;break;
                    //case 6: item = '=';break;
                    default :  cout<<"Unknown symbol encountered !";exit(0);
                }
               
                ++i;
            }
            for (int k = s.sp();k>-1;--k)
            {
                post[j]=s.pop();j++;           //To pop all the remaining stack elements at the end of exp 
            }
            cout<<"The resultant postfix is,"<<endl;
            for(int k=0;k<j;++k)
            {cout<<post[k]<<" ";}
            cout<<endl;getch();
            
        }
        if(choice ==2)
        cout<<"Coming soon!"<<endl;
        
    } while (choice == 1 );
   
    return 0;
    
}