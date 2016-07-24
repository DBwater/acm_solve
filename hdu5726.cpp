#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=111111;
ll a[maxn];
ll dp[maxn][65];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
void rmq(int n)
{
    for(int i=1;i<=n;i++)dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            dp[i][j]=gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int l,int r)
{
    int k=log(double(r-l+1))/log(2.0);
    return gcd(dp[l][k],dp[r-(1<<k)+1][k]);
}
map<int,ll>mg;
int main()
{
    //freopen("input","r",stdin);
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        mg.clear();
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        rmq(n);
        for(int i=1;i<=n;i++){
            int L=i,R;
            int temp=a[i];
            while(L<=n){
                int l=i,r=n;
                while(l<=r){
                    int mid=(l+r)>>1;
                    if(query(i,mid)>=temp){
                        R=mid;
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                mg[temp]+=R-L+1;
                L=R+1;
                temp=(query(i,L));
            }
        }
        int m;scanf("%d",&m);
        printf("Case #%d:\n",cas);
        while(m--){
            int l,r;scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            printf("%d %lld\n",query(l,r),mg[query(l,r)]);
        }
    }
}
