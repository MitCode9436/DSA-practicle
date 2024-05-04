#include <iostream>
using namespace std;
class graph
{
        int n;
        int k;
        int a[10][10];
        int v[10];
        int g[10];

public:
        graph()
        {
                k = 0;
        }

        void getdata();
        void display();
        void DFS(int);
};
void graph::getdata()
{
        char ch;
        cout << "Enter how many node in graph:";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
                cout << "Node no.:" << i << endl;
                for (int j = 0; j < n; j++)
                {
                        cout << "Enter '1' if edge is present from  " << i << " to " << j << " else Enter '0' :";
                        cin >> a[i][j];
                }
        }
        for (int i = 0; i < n; i++)
        {
                v[i] = 0;
        }
}
void graph::DFS(int m)
{
        // cout<<m;
        v[m] = 1;
        g[k] = m;
        k++;
        for (int j = 0; j < n; j++)
        {
                if (a[m][j] == 1 && v[j] != 1)
                {
                        DFS(j);
                }
        }
}
void graph::display()
{
        DFS(0);

        for (int i = 0; i < n; i++)
        {
                cout << g[i] << "--";
        }
}

int main()
{
        graph g;
        g.getdata();
        g.display();
        return 0;
}
