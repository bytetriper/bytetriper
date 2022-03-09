#include<bits/stdc++.h>
using namespace std;
const int N=6e5+1;
int a[N],n,m;
bool vis[N];
int main()
{
    memset(vis,0,sizeof(vis));
    int m;
    scanf("%d%d",&n,&m);
    int j=0,dr=1;
    bool fg=1;
    for(int i=1;i<=n-1;i++)
    {
        for(int k=1;k<=m;k++)
        {
            if(j==n||j==1)
            {    
                if(!fg)
                    dr*=-1;
                else
                    fg=0;
            }
            j+=dr;
            if(vis[j])
            {   
                while(vis[j])
                    j+=dr;
                j-=dr;
            }
        }
        vis[j]=1;
        cout<<j<<endl;
    }
    return 0;
}