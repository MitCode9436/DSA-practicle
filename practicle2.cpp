#include<iostream>
using namespace std;
class flight
{
        int n;
        int a[10][10];
        string name[10];
        public:
                void getdata();
                void display();
};
void flight::getdata()
{
        char ch;
        cout<<"Enter no. of city:";
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
        cout<<"Enter name of city:";
        cin>>name[i];
        }
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<"Wheather path is exit between:"<<"  "<<name[i]<<" "<<"to"<<"  " <<"   "<<name[j]<<endl;
                        cout<<"Enter 'y' if exit or Enter 'n' if not exit:";
                        cin>>ch;
                        cout<<endl;
                        if(ch=='y')
                        {
                                cout<<"Enter distance between cities:";
                                cin>>a[i][j];

                        }
                        else
                        {       
                                a[i][j]=0;
                        }
                 }
         }

        
}
void flight::display()
{
        cout<<endl;
        for(int i=0;i<n;i++)
        {
                cout<<name[i]<<endl;
                for (int j=0;j<n;j++)
                {
                        cout<<"Distance from"<<"  "<<name[i]<<"  "<< "to"<<" "<<name[j]<<"is"<<a[i][j]<<endl;
                }
                
         }
}
                        
       
int main()
{
        flight f;
        f.getdata();
        f.display();
}                    
