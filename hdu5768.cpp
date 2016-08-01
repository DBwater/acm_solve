#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=11111;
typedef long long ll;
ll n,l,r,ans;
int used[maxn];
ll m[maxn],a[maxn];
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){x=1;y=0;return a;}
	ll d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
ll mul(ll a,ll b,ll mod){
	a=(a%mod+mod)%mod;
	b=(b%mod+mod)%mod;
	ll res=0;
	while(b){
		if(b&1){
			res+=a;
			if(res>=mod)res-=mod;
		}
		b>>=1;
		a<<=1;
		if(a>=mod)a-=mod;
	}
	return res;
}
ll china(ll l,ll r){
	ll M=1,d,y,x=0;
	for(int i=0;i<=n;i++)if(used[i])M*=m[i];
	for(int i=0;i<=n;i++)if(used[i]){
		ll w=M/m[i];
		exgcd(m[i],w,d,y);
		x=(x+mul(mul(y,w,M),a[i],M));
	}
 	x=(x+M)%M;
	return (r+M-x)/M-(l-1+M-x)/M;
}
void dfs(int pos,ll id)
{
	if(id&1)
		ans-=china(l,r);
	else
		ans+=china(l,r);
	for(int i=pos+1;i<n;i++){
		used[i]=1;
		dfs(i,id+1);
		used[i]=0;
	}
}
int main()
{
	//freopen("input","r",stdin);
	int t;scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%lld%lld%lld",&n,&l,&r);
		memset(used,0,sizeof(used));
		for(int i=0;i<n;i++)scanf("%lld%lld",&m[i],&a[i]);
		m[n]=7;a[n]=0;used[n]=1;
		ans=0;
		dfs(-1,0);
		printf("Case #%d: %lld\n",cas,ans);
	}
}
