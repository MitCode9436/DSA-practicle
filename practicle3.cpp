#include<iostream>
using namespace std;
struct node
{
       node *child[50];
       string label;
       int count;
};
class Book
{
        node *root;
        public:
        Book()
        {
                root=NULL;
        }
        void create();
        void display();
        
};
void Book::create()
{
        root=new node;
        cout<<"Enter Name of book:";
        cin>>root->label;
        cout<<"Enter How many Unit in the book:";
        cin>>root->count;
        for(int i=0;i<root->count;i++)
        {
                root->child[i]=new node;
                cout<<"Enter Name of Unit:";
                cin>>root->child[i]->label;
                cout<<"Enter no of Chapter:";
                cin>>root->child[i]->count;
                for(int j=0;j<root->child[i]->count;j++)
                {
                        root->child[i]->child[j]=new node;
                        cout<<"Enter Name of Chapter:";
                        cin>>root->child[i]->child[j]->label;
                        cout<<"Enter no. of Section:";
                        cin>>root->child[i]->child[j]->count;
                        for(int k=0;k<root->child[i]->child[j]->count;k++)
                        {
                                root->child[i]->child[j]->child[k]=new node;
                                cout<<"Enter name of section:";
                                cin>>root->child[i]->child[j]->child[k]->label;
                        }
                  }
           }
}
void Book::display()
{
        if(root==NULL)
        {
                cout<<"Book is empty we can Say that the book has no chapters "<<endl;
        }
        else
        {
                cout<<"Display of tree:"<<endl;
                cout<<"Name of Book:"<<root->label<<endl;
                //cout<<" Name of unit:";
                for(int i=0;i<root->count;i++)
                {
                        cout<<" Name of unit:";
                        
                        cout<<i+1<<")"<<root->child[i]->label;
                        cout<<endl;
                        cout<<"         Name of Chapter:"<<endl;
                        for(int j=0;j<root->child[i]->count;j++)
                        {
                                
                                cout<<"                 "<<j+1<<")"<<root->child[i]->child[j]->label;
                                cout<<endl;
                                cout<<"                 Name of section:"<<endl;
                                for(int k=0;k<root->child[i]->child[j]->count;k++)
                                {
                                        cout<<"                 "<<k+1<<")"<<root->child[i]->child[j]->child[k]->label;
                                        cout<<endl;
                                }
                          }
                  }
          }
}
int main()
{
        int n;
        Book b;
        b.create();
        b.display();
        cout<<"Enter '1' if create a book,else Enter '2' ;";
        cin>>n;
        switch(n)
        {       case 1:
                {
                        b.create();
                        break;
                }
                case 2:
                {
                        b.display();
                        
                        break;
                }
                default:
                {
                        cout<<"Enter Correct No.:";
                        break;
                }
       }
}
        
                
 
