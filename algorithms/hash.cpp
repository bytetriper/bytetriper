#include<bits/stdc++.h>//using open hash_table
using namespace std;
const int p=1<<30;
const int N=1e4+1;
int mmax=1501,n;
long long md[N];
char *s[N];
inline void init(int mx)
{
    for(int i=0;i<=mx;i++)
        md[i]=rand()%9999;
    return;
}
inline int hsh(char c[])
{
    long long x=0;
    int l=strlen(c)-1;
    for(int i=0;i<l;i++)
        x=(x+(c[i]*c[i]*md[i]*c[l-1-i])%p)%p;
    return x;
}
int f[N];
int main()
{    
    srand((unsigned)time(NULL));
    scanf("%d",&n);
    init(mmax);
    int cnt=0;
    bool fg;
    for(int i=1;i<=n;i++)
    {
        fg=0;
        s[i]=new char[mmax];
        cin>>s[i];
        f[i]=hsh(s[i]);
        for(int j=1;j<i;j++)
            if(f[i]==f[j])
            {
                fg=1;
                break;
            }
        if(!fg)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}