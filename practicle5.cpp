#include<iostream>
# define max 10
using namespace std;
struct node
{
        int data;
        node *next;
        
};
class Graph
{       public:
        node *list[10];
        int n;
        int a[max];
        int rear,front;
        
               Graph()
               {        rear=front=-1;
                        cout<<"Enter How many node in the graph:";
                        cin>>n;
                       for(int i=0;i<n;i++)
                        {
                                list[i]=new node;
                                list[i]->next=NULL;
                        }
                }
                void getdata();
                void display();
                int deletion();
                void insert(int);
                int isfull();
                int isempty();
                int BSF();
                
};
void Graph::getdata()
{       int m; 
        for (int i=0;i<n;i++)
        {        node* last;  
                        
                        
                cout<<"Enter name of vertex  "<<i+1<<":";
                cin>>list[i]->data;
                cout<<"How many Adj. nodes to:"<<list[i]->data<<":";
                cin>>m;
                for(int j=0;j<m;j++)
                {
                        node *nn;
                        nn=new node;
                        nn->next=NULL;
                        //last->next=NULL;
                        cout<<"Enter the name of adj.node to:"<<list[i]->data<<":";
                        cin>>nn->data;
                        if(list[i]->next==NULL)
                        {
                                list[i]->next=last=nn;
                        }
                        else
                        {
                                last->next=nn;
                                last=nn;
                         }
                 }
          }
}
void Graph::display()
{
        for(int i=0;i<n;i++)
        {
                node *temp;
                temp=list[i];
                cout<<list[i]->data<<":";
                while(temp!=NULL)
                {
                        cout<<temp->data<<"--> ";
                        
                        temp=temp->next;
                 }
                 cout<<endl;
        }
}
int Graph::isfull()
{
        if(rear==max-1)
        {
                return 1;
         }
         else
         {
                return 0;
          }
}
int Graph::isempty()
{
        if(rear==-1)
        {
                return 1;
        }
         else
         {
                return 0;
         }
}
void Graph::insert(int n)
{
        if(isfull())
        {
                cout<<"Queue is full";
        }
        else
        {
                if(rear==-1)
                {
                        rear=front=0;       
                }
                else
                {
                        a[rear]=n;
                        rear++;
                }
}
}
int Graph::deletion()
{
        int n;
        if(!isempty())
        {
               n=a[front];
               front++;
        }
        return n;
} 
int Graph::BSF()
{
        int ready=0,wait=1,process=2;
        int status[10];
        int start;
        node *temp;
        for(int i=0;i<n;i++)
        {
                status[i]=ready;
         }
         cout<<"Enter root node:";
         cin>>start;
         insert(start);
         status[start]=wait;
         while(!isempty())
         {
                int del=deletion();
                status[del]=process;
                cout<<del<<" ";
                temp=list[del];
                while(temp!=NULL)
                {
                        int n=temp->data;
                        if(status[n]==ready)
                        {
                                insert(n);
                                status[n]=wait;
                        }
                        temp=temp->next;
                 }
            }
}
int main()
{
        Graph g;
        g.getdata();
        g.display();
        g.BSF();
}              
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
                       
                                
