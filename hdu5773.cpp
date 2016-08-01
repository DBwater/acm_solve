#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1111111;
int a[maxn],b[maxn],num;
int dp[maxn];
int main()
{
	//freopen("input","r",stdin);
	int t;scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		int num=0;
		memset(dp,inf,sizeof(dp));
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]==0)num++;
			else b[i]=a[i]-num;
		}
		for(int i=0;i<n;i++){
			if(a[i]){
				int j=lower_bound(dp,dp+n,b[i])-dp;
				dp[j]=b[i];
			}
		}
		int ans=lower_bound(dp,dp+n,inf)-dp;
		printf("Case #%d: %d\n",cas,ans+num);
	}
}
