#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn=1111111;
int t1[maxn],t2[maxn],c[maxn];
int sa[maxn],rank1[maxn],height[maxn];
bool cmp(int *r,int a,int b,int l)
{
	return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int str[],int sa[] ,int rank1[] ,int height[],int n,int m)
{
	n++;
	int *x=t1,*y=t2,p;
	for(int i=0;i<m;i++)c[i]=0;
	for(int i=0;i<n;i++)c[x[i]=str[i]]++;
	for(int i=1;i<m;i++)c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
	for(int j=1;j<=n;j<<=1){
		p=0;
		for(int i=n-j;i<n;i++)y[p++]=i;
		for(int i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(int i=0;i<m;i++)c[i]=0;
		for(int i=0;i<n;i++)c[x[y[i]]]++;
		for(int i=1;i<m;i++)c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for(int i=1;i<n;i++){
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
		if(p>=n)break;
		m=p;
	}
	int k=0;
	n--;
	for(int i=0;i<=n;i++)rank1[sa[i]]=i;
	for(int i=0;i<n;i++){
		if(k)k--;
		int j=sa[rank1[i]-1];
		while(str[i+k]==str[j+k])k++;
		height[rank1[i]]=k;
	}
}
char s[10];
char str[maxn];
int r[maxn];
int a[maxn];
int main()
{
	int t;scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		scanf("%s",s);
		scanf("%s",str);
		int n=strlen(str);
		for(int i=0;i<n;i++)r[i]=str[i];
		r[n]=0;
		da(r,sa,rank1,height,n,128);
		int cnt=n;
		for(int i=n-1;i>=0;i--){
			if(str[i]==s[0])cnt=i;
			a[i]=cnt;
		}
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=n-max(a[sa[i]],sa[i]+height[i]);
		}
		printf("Case #%d: %lld\n",cas,sum);
	}
}
