#include<string.h>
#include<stdio.h>
const int maxn=111111;
const int mod=1e9+7;
int hao[maxn],used[maxn];
char s[maxn],c[maxn];
int n,m;
int dp[maxn];
void gethao()
{
    int j=0;
    hao[1]=0;
    for(int i=2;i<=m;i++){
        while(j>0&&c[j+1]!=c[i])j=hao[i];
        if(c[j+1]==c[i])j++;
        hao[i]=j;
    }
}
void kmp(){
    int j=0;
    for(int i=1;i<=n;i++){
        while(j>0&&s[i]!=c[j+1])j=hao[j];
        if(s[i]==c[j+1])j++;
        if(j==strlen(c+1)){
            used[i]=1;
            j=hao[j];
        }
    }
}
int main()
{
    //freopen("input","r",stdin);
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){    
        memset(dp,0,sizeof(dp));
        memset(used,0,sizeof(used));
        memset(hao,0,sizeof(hao));
        scanf("%s%s",s+1,c+1);
        n=strlen(s+1);
        m=strlen(c+1);
        gethao();
        kmp();
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(!used[i]){
                dp[i]=dp[i-1];
            }
            else{
                dp[i]=((long long )dp[i-1]+dp[i-m])%mod;
            }
        }
        printf("Case #%d: %d\n",cas,dp[n]);
    }
}
