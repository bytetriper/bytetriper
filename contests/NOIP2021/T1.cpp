#include<bits/stdc++.h>
using namespace std;
int *nxt;
const int mody=1e5;
const int N=2e5+3;
int a[N];
inline int read()
{
    int w=1,x=0;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
            w=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+(ch-'0');
        ch=getchar();
    }
    return w*x;
}
bool jud(int x)
{
    while(x)
    {
        if(x%10==7)
            return true;
        x/=10;
    }
    return false;
}
int main()
{
    int t,maxx=0;
    t=read();
    for(int i=1;i<=t;i++)
    {
        a[i]=read();
        maxx=max(a[i],maxx);
    }
    nxt=new int [maxx+mody+1];
    memset(nxt,0,sizeof(nxt));
    int lst=0;
    for(int i=1;i<=maxx+mody;i++)
    {
        if(nxt[i]==-1)
            continue;
        if(jud(i))
        {
            for(int j=1;j*i<=maxx+mody;j++)
                nxt[j*i]=-1;
            continue;
        }
        nxt[lst]=i;
        lst=i;
    }
    for(int i=1;i<=t;i++)
        printf("%d\n",nxt[a[i]]);
    return 0;
}