#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

class flight {
    int n;
    int a[10][10];
    string name[10];
public:
    void getdata();
    void display();
    bool isConnected();
    void DFS(int v, bool visited[]);
};

void flight::getdata() {
    char ch;
    cout << "Enter no. of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter name of city " << i + 1 << ": ";
        cin >> name[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Is there a path between " << name[i] << " and " << name[j] << "? (y/n): ";
            cin >> ch;
            if (ch == 'y') {
                cout << "Enter distance between cities: ";
                cin >> a[i][j];
            } else {
                a[i][j] = 0;
            }
        }
    }
}

void flight::display() {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << name[i] << endl;
        for (int j = 0; j < n; j++) {
            cout << "Distance from " << name[i] << " to " << name[j] << " is " << a[i][j] << endl;
        }
    }
}

bool flight::isConnected() {
    bool visited[n];
    memset(visited, false, sizeof(visited));
    DFS(0, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return false; // If any city is not reachable, the graph is not connected
    }

    return true; // If all cities are reachable, the graph is connected
}

void flight::DFS(int v, bool visited[]) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (a[v][i] && !visited[i]) {
            DFS(i, visited);
        }
    }
}

int main() {
    flight f;
    f.getdata();
    f.display();
    
    if (f.isConnected()) {
        cout << "\nThe graph is connected." << endl;
    } else {
        cout << "\nThe graph is not connected." << endl;
    }

    return 0;
}
