#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
const int maxn=1e7+100;
ll n,m,p;
int is_prime[maxn];
ll prime[maxn];
ll a[maxn];
ll phi[maxn],sumphi[maxn];
ll mul(ll a,ll b,ll mod){
	a=(a%mod+mod)%mod;
	b=(b%mod+mod)%mod;
	ll res=0;
	while(b){
		if(b&1){
			res+=a;
			if(res>=mod)res-=mod;
		}
		b>>=1;a<<=1;
		if(a>=mod)a-=mod;
	}
	return res;
}
ll pow(ll a,ll b,ll mod)
{
	ll ans=1;
	while(b){
		if(b&1)ans=mul(ans,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return ans;
}
int tot;
void getphi()
{
	memset(is_prime,-1,sizeof(is_prime));
	is_prime[0]=is_prime[1]=0;
	tot=0;
	phi[1]=1;
	for(int i=2;i<maxn;i++){
		if(is_prime[i]){
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++){
			if(i*prime[j]>maxn)break;
			is_prime[i*prime[j]]=false;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	for(int i=1;i<maxn;i++)
		sumphi[i]=(sumphi[i-1]+phi[i])%mod;
}
int cnt=0;
int get_prime(ll x)
{
	cnt=0;
	for(int i=0;i<tot;i++){
		if(x==1)break;
		if(x%(ll)prime[i]==0){
			a[cnt++]=(ll)prime[i];
			x/=prime[i];
		}
	}
	return cnt;
}
ll get(int pos,ll n,ll m)
{
	if(n==1)return sumphi[m];
	if(m==1)return phi[n];
	if(m<1)return 0;
	return (phi[a[pos]]*get(pos-1,n/a[pos],m)%mod+get(pos,n,m/a[pos])%mod)%mod;
}
ll k;
ll solve(ll k,ll mod)
{
	if(mod==1)return 0; 
	ll p=solve(k,phi[mod])+phi[mod];
	return pow(k,p,mod);
}
int main()
{
	//freopen("input","r",stdin);
	getphi();
	while(~scanf("%lld%lld%lld",&n,&m,&p)){
		k=get_prime(n);
		k=get(k-1,n,m);
		ll ans=solve(k,p);
		printf("%lld\n",ans);
	}
}
