#include<iostream>
#include<cstdio>
using namespace std;
const int mod=1e9+7;
const int maxn=20;
typedef long long ll;
ll F[maxn][maxn],G[maxn][maxn];//连通，非连通个数
ll H[maxn][maxn];//图的总数
ll C[maxn][maxn];
ll fact[maxn*maxn];
int main()
{
    int n=11,m=11;
    fact[0]=1;
    for(int i=1;i<=n*n;i++)fact[i]=fact[i-1]*3%mod;//3的次方
    C[0][0]=1;
    for(int i=1;i<n;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    G[0][0]=1;
    for(int i=1;i<=10;i++){
            for(int j=0;j<=10;++j){
                for(int k1=1;k1<=i;k1++){
                    for(int k2=0;k2<=j;k2++){
                        G[i][j]+=C[i-1][k1-1]*C[j][k2]%mod*F[k1][k2]%mod*fact[(i-k1)*(j-k2)]%mod;
                    }
                }
                    F[i][j]=((fact[i*j]-G[i][j]%mod)+mod)%mod;
            }
        }
    while(~scanf("%d%d",&n,&m)){
        printf("%lld\n",F[n][m]);
    }
}
