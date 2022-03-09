#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
char a[N];
int nxt[N];
inline void prekmp()
{
    int l=strlen(a)-1;
    nxt[0]=-1;
    nxt[1]=0;
    int i=1,k=0;
    while(i<=l)
    {
        if(k==-1||a[i]==a[k])
            nxt[++i]=++k;
        else
            k=nxt[k];
    }
    return;
}
int ans[N],cnt=0;
int main()
{
    scanf("%s",&a);
    prekmp();
    for(int k=nxt[strlen(a)];k;k=nxt[k])
        ans[++cnt]=k;
    for(int i=cnt;i;i--)
        printf("%d\n",ans[i]);
    printf("%d",strlen(a));
    return 0;
}   