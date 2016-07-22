#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1111111;
typedef long long ll;
int head[maxn];
int par[maxn];
int tot;
struct edge{
    int to,next, w;
}edge[maxn*2];
void add_edge(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void init1()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void init2(){for(int i=0;i<maxn;i++)par[i]=i;}
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
bool same(int u,int v){return find(u)==find(v);}
void unite(int u,int v){u=find(u);v=find(v);if(v!=u)par[u]=v;}
typedef struct data{
    int u,v,w;
}data;
data node[maxn];
bool comp(data x,data y)
{
    return x.w<y.w;
}
int d[maxn];
int sum[maxn];
void dfs(int u,int pre)
{
    sum[u]=1;
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=pre){
        dfs(v,u);
        sum[u]+=sum[v];
        }
    }
}
ll ans1;
double ans;
int num;
int n,m;
void dfs2(int u,int pre)
{
    for(int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=pre){
        ans+=(double)((ll)sum[v]*(n-sum[v])*edge[i].w)/(ll(n)*(n-1)/2);
        dfs2(v,u);
        }
    }
    
}
int main()
{
   // freopen("input","r",stdin);
    int t;scanf("%d",&t);
    while(t--){
        init1();init2();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int u,v,w;scanf("%d%d%d",&node[i].u,&node[i].v,&node[i].w);
        }
        sort(node,node+m,comp);
        ans1=0,ans=0;
        num=0;    
        for(int i=0;i<m;i++){
            if(!same(node[i].u,node[i].v)){
                unite(node[i].u,node[i].v);
                ans1+=node[i].w;
                d[num++]=i;
            }
        }
        for(int i=0;i<num;i++){
            add_edge(node[d[i]].u,node[d[i]].v,node[d[i]].w);
            add_edge(node[d[i]].v,node[d[i]].u,node[d[i]].w);
        }
        dfs(node[d[0]].u,-1);
        dfs2(node[d[0]].u,-1);
        printf("%lld %.2f\n",ans1,ans);
    }
}
