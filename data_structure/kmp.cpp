#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int nxt[N];
char a[N],b[N];
int n;
inline void prekmp(char a[])//0-based
{
    nxt[0]=-1;
    nxt[1]=0;
    int i=1,k=0;
    int l=strlen(a)-1;
    while(i<=l)
    {
        if(a[i]==a[k]||k==-1)
            nxt[++i]=++k;
        else
            k=nxt[k];
    }
}
inline void kpair(char a[],char b[])//a is the pre-handled
{
    bool fg=0;
    int i=0,j=0;
    int l2=strlen(b)-1,l1=strlen(a)-1;
    while(i<=l1&&j<=l2)
    {
        if(i==-1||a[i]==b[j])
        {
            i++;j++;
        }
        else
            i=nxt[i];
        if(i==l1+1)
        {
            printf("%d\n",j-l1);
            i=nxt[i];
        }
    }
}
int main()
{
    cin>>b;
    cin>>a;
    prekmp(a);
    kpair(a,b);    
    for(int i=1;i<=strlen(a);i++)
        printf("%d ",nxt[i]);
    return 0;
}