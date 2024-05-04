#include<iostream>
#include<string.h>
#define max 50
using namespace std;
struct node
{
        char data;
        node *left;
        node *right;
};
class stack
{
        int top;
        node *data[max];
        public:
        stack()
        {
                top=-1;
        }
        void push(node*);
        node* pop();
        int isfull();
        int isempty();
        
};
void stack::push(node* ch)
{
        if(!isfull())
                data[++top]=ch;
}
node* stack::pop()
{
        if(!isempty())
                return(data[top--]);
}
int stack::isfull()
{
        if(top==max-1)
                return 1;
        else
                return 0;
}
int stack::isempty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}
//new class 
class tree
{
        char prefix[max];
        //node* top;
        
        public:
        node* top;
        tree()
        {
                top=NULL;
        }
        void Expression(char[]);
        void display(node*);
        void post(node*);
        void del(node*);
};
void tree::Expression(char prefix[])
{
        char c;
        node *t1,*t2;
        stack s1;
        int len;
        len=strlen(prefix);
        for(int i=len-1;i>=0;i--)
        {        top=new node;
                 top->left=NULL;
                 top->right=NULL;
                 if(isalpha(prefix[i]))
                 {
                        top->data=prefix[i];
                        s1.push(top);
                  }
                  else if(prefix[i]=='+'|| prefix[i]=='-'|| prefix[i]=='*'|| prefix[i]=='/')
                        {
                                
                                t1=s1.pop();
                                t2=s1.pop();
                                top->data=prefix[i];
                                top->left=t1;
                                top->right=t2;
                                s1.push(top);
                         }
                    }
                    top=s1.pop();
          
        //return top;
}
void tree::display(node *root)
{
        //cout<<"Display of tree";
        if(root!=NULL)
        {
        cout<<root->data;
        display(root->left);
        display(root->right);
        }
//cout<<endl;
}
void tree::post(node*top)
{
        stack s1,s2;
        node*t=top;
        s1.push(t);
        while(s1.isempty()!=1)
        {
                t=s1.pop();
                s2.push(t);
                if(t->left!=NULL)
                        s1.push(t->left);
                if(t->right!=NULL)
                        s1.push(t->right);
         }
                // node*t1;
                cout<<endl;
                cout<<"postorder traversal:";
                 while(s2.isempty()!=1)
                 {
                        top=s2.pop();
                        cout<<top->data<<" ";
                 }
}
void tree::del(node* t)
{
    if (t == NULL)
    {
        return;
    }
    else
    {
        del(t->left);
        del(t->right);
        delete t;
    }
}
                    
int main()
{       
        //string p;
        char p[max];
        node *s;
        tree t;
        cout<<"Enter prefix exp:";
        cin>>p;
        t.Expression(p);
        t.display(t.top);
        t.post(t.top);
        t.del(t.top);       
}





















