#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace  std;
const int maxn=11;
const int inf=0x3f3f3f3f;
int n,m;
int tot;
int head[maxn];
int a[maxn];
int ok[maxn][maxn];
int used[maxn],match[maxn];
struct edge{
    int to,next;
}edge[maxn*maxn];
void add_edge(int u,int v){
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int ans;
void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
bool dfs(int u){
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(!used[v]){
            used[v]=1;
            if(match[v]==-1||dfs(match[v])){
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungry(){
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        if(dfs(i))
            ans++;
    }
    return ans;
}
void solve()
{
    init();
    for(int i=1;i<=n;i++){//阴珠子
        for(int j=1;j<=n;j++){
            int pre=i-1;if(pre==0)pre=n;
            if(!ok[j][a[i]]&&!ok[j][a[pre]]){
                add_edge(j,a[i]);
            }
        }
    }
    ans=min(ans,n-hungry());
}
int main()
{
    //freopen("input","r",stdin);
    while(~scanf("%d%d",&n,&m)){
        memset(ok,0,sizeof(ok));
        for(int i=1;i<=n;i++)a[i]=i;
       for(int i=0;i<m;i++){
            int u,v;scanf("%d%d",&u,&v);
            ok[u][v]=1;
        }
        if(m==0&&n==0){
            printf("0\n");continue;
        }
        ans=inf;
        do{
            solve();
        }while(next_permutation(a+1,a+n));//阴珠子
        printf("%d\n",ans);
    }
}
