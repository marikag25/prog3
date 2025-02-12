#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> odg;


bool check(vector<int> &v, int n)
{
   for (int i=0; i<n*n; i++) {
        if (v[i] == 0)
        {
            continue; 
        }
        int row_i=i/n, col_i=i%n;

        for (int j=i+1; j<n*n; j++) {
            if (v[j] == 0)
            {
                continue;
            }
            int row_j=j/n, col_j=j%n;
            if (row_i == row_j)
            {
                return false;
            }
            if (col_i==col_j)
            {
                return false;
            }
            if (abs(row_i-row_j) == abs(col_i-col_j))
            {
                return false;
            }
            if(row_i+col_i==row_j+col_j)
            {
                return false;
            }
        }
    }
    return true;
}
void generate(vector<int> &v, int n, int i, vector<int> &queen)
{
    if(i==n)
    {
        if(check(v,n))
        odg.push_back(v);
        return;
    }
    int q = queen[i];
    for(int j=0; j<n*n; j++)
    {
        if(v[j]==0)
        {
            v[j] = q;
            generate(v,n,i+1,queen);
            v[j] = 0;
        }
    }
}
int main()
{
    int n = 0;
    cin>>n;
    vector <int> queen(n);
    int j=1;
    for(int i=0; i<n; i++)
    queen[i] = j++;
    vector<int> v(n*n,0);
    generate(v,n,0,queen);
    cout<<odg.size()<<endl;
    for(auto v:odg)
    {
        for(int i=0; i<n*n; i++)
        {
            cout << v[i] << ' ';
            if(i%n==n-1)
            cout << '\n';
        }
       
        cout << '\n';
    }
    return 0;
}