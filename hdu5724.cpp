#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=(1<<22);
int sg[maxn];
int h[30];
void getsg()
{
    for(int i=1;i<(1<<20);i++){
        memset(h,-1,sizeof(h));
        int last=-1;
        for(int j=0;j<20;j++){
            if(!((i>>j)&1))last=j;
            else{
                if(last!=-1){
                    h[sg[i^(1<<j)^(1<<last)]]=1;
                }
            }
        }
        int j=0;
        while(h[j]!=-1)j++;
        sg[i]=j;
    }
}
int main()
{
    //freopen("input","r",stdin);
    int t;scanf("%d",&t);
    getsg();
    while(t--)
    {
        int ans=0;
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            int m;scanf("%d",&m);
            int a=0;
            for(int j=0;j<m;j++){
                int k;scanf("%d",&k);
                a^=(1<<(20-k));
            }
            ans^=sg[a];
        }
        if(ans==0)printf("NO\n");
        else printf("YES\n");
    }
}
