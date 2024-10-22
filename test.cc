#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,m;
    int a[256][256];
    int b[256][256];
    int i,j,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
            b[j][n-i+1]=a[i][j];
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}