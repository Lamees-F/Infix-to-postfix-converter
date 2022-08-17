#include <iostream>

using namespace std;

struct Opearation{
char OP;
Opearation *next;
};

class StackOp{
private:
    Opearation *top;
public:
    StackOp(){
        top=NULL;
        }

    bool isEmpty(){
    return (top == NULL);
    }

    void push(char x)
    {
        Opearation *p=new Opearation;
        p->OP=x;
        p->next=top;
        top=p;
    }

    char pop()
    {   char e;
        if(isEmpty())
        {
            cout<<"Stack is empty!!\n";
            return 0;
        }
        else {
          Opearation *p=top;
          e = p->OP;
          top=top->next;
          delete p;
          return e;
        }
    }

    char peek()
    {
       if(isEmpty())
        {
            cout<<"Stack is empty!!\n";
            return 0;
        }
       else{
        return top->OP;
       }
    }
};

int precedence(char);

int main()
{
     StackOp L ;
     int i=0 ,j=0;
     char symbol,p;
     char in[50],post[50];

    cout << "Enter the expression :" << endl;
    gets(in);

        while(in[i]!='\0'){
            symbol=in[i];
           switch(symbol){
        case '(':
            L.push('(');break;
        case ')':
             p =L.pop();
             while(p !='('){
                post[j++]= p;
                p =L.pop();
                   }break;
        case '^':
        case '*':
        case '/':
        case '+':
        case '-':
            if(L.isEmpty())
                L.push(symbol);
            else{
                while(!L.isEmpty()&& ( precedence(L.peek())>= precedence(symbol) ) ){
                        if(symbol=='^'&&(L.peek()=='^'))
                            break;
                    p=L.pop();
                    post[j++]=p;
                }
                L.push(symbol);
            }
            break;
        default:
            if(islower(symbol)||isupper(symbol))
                post[j++]=toupper(symbol);
            }
            i++;
        }
        while(!L.isEmpty()){
            p=L.pop();
            post[j++]=p;
        }
        post[j]='\0';

        cout<<"The postfix expression is : ";
        for(int m=0;m<j;m++)
           cout<<post[m];
        cout<<endl;

    return 0;
}

int precedence(char x)
{
    switch(x)
    {
    case '^':
        return 4;
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;

    default:
        return 0;
    }
}
