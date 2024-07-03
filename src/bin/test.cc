#include<iostream>
#include<cstdio>
#define int long long
#define N 200005
using namespace std;
const int m=998244353;
int n,q,b[N],a[N*4],add[N*4],mul[N*4];
void build(int x,int l,int r){
	mul[x]=1;add[x]=0;
	if(l==r){
		a[x]=b[l]%m;return;
	}
	int mid=(l+r)>>1;
	build(x*2,l,mid);build(x*2+1,mid+1,r);
	a[x]=(a[x*2]+a[x*2+1])%m;
}
void pushdown(int x,int l,int r,int mid){
	a[x*2]=(a[x*2]*mul[x]+(mid-l+1)*add[x])%m,a[x*2+1]=(a[x*2+1]*mul[x]+(r-mid)*add[x])%m;
	mul[x*2]*=mul[x],mul[x*2+1]*=mul[x];
	add[x*2]=(add[x*2]*mul[x]+add[x])%m,add[x*2+1]=(add[x*2+1]*mul[x]+add[x])%m;
	mul[x]=1;add[x]=0;mul[x*2]%=m,mul[x*2+1]%=m;
}
void update(int x,int l,int r,int ql,int qr,int k,int op){
	if(ql<=l&&r<=qr){
		if(op==1)a[x]=a[x]*k%m,add[x]=add[x]*k%m,mul[x]=mul[x]*k%m;
		else a[x]=(a[x]+(r-l+1)*k)%m,add[x]=(add[x]+k)%m;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(x,l,r,mid);
	if(ql<=mid)update(x*2,l,mid,ql,qr,k,op);
	if(qr>mid)update(x*2+1,mid+1,r,ql,qr,k,op);
	a[x]=(a[x*2]+a[x*2+1])%m;
}
int query(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return a[x];
	int mid=(l+r)>>1,sum=0;
	pushdown(x,l,r,mid);
	if(ql<=mid)sum=(sum+query(x*2,l,mid,ql,qr))%m;
	if(qr>mid)sum=(sum+query(x*2+1,mid+1,r,ql,qr))%m;
	return sum;
}
int qpow(int x,int y){
	int ans=1;x%=m;
	while(y){
		if(y&1)ans=ans*x%m;
		x=x*x%m;
		y>>=1;
	}
	return ans;
}
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;++i)scanf("%lld",&b[i]);
	build(1,1,n);
	while(q--){
		int x,l,r;
		scanf("%lld%lld%lld",&l,&r,&x);
		update(1,1,n,l,r,((r-l)*qpow(r-l+1,m-2))%m,1);
		update(1,1,n,l,r,x*qpow(r-l+1,m-2),0);
	}
	for(int i=1;i<=n;++i)printf("%lld ",query(1,1,n,i,i));
	return 0;
}
