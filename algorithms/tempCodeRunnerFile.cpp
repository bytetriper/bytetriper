#include<bits/stdc++.h>//using open hash_table
using namespace std;
const int p=1e7+1;
const int N=1e4+1;
bool a[p];
int mmax=1501,n;
long long md[N];
char *s[N];
inline void init(int mx)
{
    for(int i=0;i<=mx;i++)
        md[i]=rand();
    return;
}
inline int hsh(char c[])
{
    long long x=0;
    for(int i=0;c[i]!='\0';i++)
        x=(x+(c[i]*md[i]*md[i])%p)%p;
    return x;
}
int main()
{    
    srand((unsigned)time(NULL));
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    init(mmax);
    int tmp,cnt=0;
    for(int i=1;i<=n;i++)
    {
        s[i]=new char[mmax];
        cin>>s[i];
        tmp=hsh(s[i]);
        if(!a[tmp])
            cnt++;
        a[tmp]=true;
    }
    printf("%d\n",cnt);
    return 0;
}