#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node {
	int data;
	struct node *next;
}*array[20],*last;
void dfs(int visited[],int s){
    visited[s]=1;
    cout<<s;
    node* temp=array[s];
    while(temp!=NULL){
        if(visited[temp->data]==0){
            dfs(visited,temp->data);
        }
        else{
            temp=temp->next;
        }
    }
}
void dfsnon(int visited[],int s){
    visited[s]=1;
    stack<int>sta;
    sta.push(s);
    cout<<"by nonrecurrsive dfs ";
    while(!sta.empty()){
        int d;
        d=sta.top();
        cout<<d;
        node* temp=array[d];
        while(temp!=NULL){
            if(visited[temp->data]==0){
                sta.push(temp->data);
                visited[temp->data]=1;
            }
            else{
                temp=temp->next;
            }
        }
    }
}
void bfs(int n){
    int visited[n+1]={0};
    int s;
    cout<<"\nenter the starting vortex for bfs ";
    cin>>s;
    queue<int>q;
    q.push(s);
    cout<<"\nbfstraversal= ";
    while(!q.empty()){
        int y=q.front();
        q.pop();
        cout<<y;
        node* temp=array[y];
        visited[y]=1;
        int count=0;
        while(temp!=NULL){
            count++;
            if(visited[temp->data]==0){
                q.push(temp->data);
                visited[temp->data]=1;
            }
            else{
                temp=temp->next;
            }
        }
        if(count==1){
            cout<<"\nthere is no adjecent node to "<<y;
        }
    }
}
void makeadj(){
    for(int i=0;i<20;i++){
        array[i]=NULL;
    }
    int n;
    cout<<"how many nodes you want to enter ";
    cin>>n;
    for(int i=1;i<=n;i++){
        node* nn=new node;
        cout<<"enter the data for node ";
        cin>>nn->data;
        nn->next=NULL;
        array[i]=last=nn;
        cout<<"\nhow many adj node to "<<nn->data<<" = ";
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            node* nn=new node;
	    cout<<"enter the data for adj node ";
            cin>>nn->data;
            nn->next=NULL; 
            last->next=nn;
            last=nn;
        }
    }
    cout<<"adj lsit ";
    for(int i=1;i<=n;i++){
        node* temp=array[i];
        cout<<"adjlist = ";
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<"\n";
    }
    bfs(n);
    int visited2[n+1]={0};
    int s;
    cout<<"\nenter the starting node for dfs ";
    cin>>s;
    cout<<"\nby DFS ";
    dfs(visited2,s);
    int visited3[n+1]={0};
    int r;
    cout<<"\nenter the starting node non recurrsive ";
    cin>>r;
    cout<<"\nby DFS ";
    dfs(visited3,r);
}
int main(){
    makeadj();
    return 0;
}
