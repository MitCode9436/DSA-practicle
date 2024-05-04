#include<iostream>
#define max 10
using namespace std;
class phone 
{
        int count;
        long int ph[max];
        public:
        phone()
        {
                count=1;
                for (int i=0;i<max;i++)
                {
                        ph[i]=0;
                }
        }
        int Hashfun(long int);
        void insert();
        void display();
};
int phone::Hashfun(long int num)
{
        return(num%10);
}
void phone::insert()
{
        int ind;
        long int num;
        
         if(count==10)
          {
                cout<<"\nOverflow"<<endl;
          }
          else
          {
          cout<<"Enter tel.no:";
          cin>>num;
          ind=Hashfun(num);
        while(count<11 && ind<max)
          {
                if(ph[ind]==0)
                {
                        ph[ind]=num;
                        count++;
                        break;
                 }
        
        else
         {
                if(ind==max-1)
                        ind=0;
                else
                        ind++;
          }
          }
          }
          
}
void phone::display()
{
        for(int i=0;i<max;i++)
        {
                cout<<i<<"--"<<ph[i]<<endl;
        }
}
int main()
{
        phone p; 
        char ch;
        int ch1;
        do{
                cout<<"Enter choice:"<<endl;
                cout<<"1.Insert"<<"\n2.Display"<<endl;
                cin>>ch1;
                switch(ch1)
                {
                        case 1:
                                p.insert();
                                break;
                        case 2:
                                p.display();
                                break;
                        default:
                                cout<<"WRONG CHOICE";
                 }
            
            cout<<"Do you want to continue(y/n):";
            cin>>ch;
            }
            while(ch=='y'||ch=='Y');
            return 0;
}
            
                                
                
                        

