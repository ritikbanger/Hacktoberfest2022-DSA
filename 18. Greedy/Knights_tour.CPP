#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &v1, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v1[i][j] << "  ";
        }
        cout << endl;
    }
    cout<<endl;
}

void knight(vector<vector<int>> &v1, int row, int col, int n, int s)
{
    if (s > n * n)
    {
        display(v1, n);
        exit(0);
    }
    if (row > n-1 || col >n-1 || row < 0 || col < 0)
    {
        return;
    }
    if (v1[row][col] != 0)
    {

        return;
    }
    v1[row][col] = s;
    knight(v1, row + 2, col + 1, n, s + 1);
    knight(v1, row + 1, col + 2, n, s + 1);
    knight(v1, row - 1, col + 2, n, s + 1);
    knight(v1, row - 2, col + 1, n, s + 1);
    knight(v1, row - 2, col - 1, n, s + 1);
    knight(v1, row - 1, col - 2, n, s + 1);
    knight(v1, row + 1, col - 2, n, s + 1);
    knight(v1, row + 2, col - 1, n, s + 1);
    v1[row][col] = 0;
}

int main()
{
    int n;
    cout<<"Enter the size of chess board :";
    cin >> n;
    int row, col;
    cout<<"Enter the start point of knight :"<<endl;
    cout<<"Row = ";
    cin >> row;
    cout<<"Col = ";
    cin>>col;
    vector<vector<int>> v1(n, vector<int>(n, 0));
    knight(v1, row, col, n, 1);
}
