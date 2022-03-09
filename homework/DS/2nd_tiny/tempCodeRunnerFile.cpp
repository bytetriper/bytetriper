#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int nxt[N];
char s[N];
inline void prekmp(char a[],int l)
{
    nxt[1]=0;
    nxt[0]=-1;
    int i=1,k=0;
    while(i<=l)
    {
        if(k==-1||a[k]==a[i])
            nxt[++i]=++k;
        else   
            k=nxt[k];
    }
}
inline int judge(char a[],int l)
{
    prekmp(a,l);
    for(int i=l;i>(l+1)/2;i--)
    {
        if(nxt[i+1]!=nxt[i]+1)  
            return l+1;
    }
    return l+1-nxt[l+1];
}  
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",&s);
    printf("%d\n",judge(s,n-1));
    return 0;
}