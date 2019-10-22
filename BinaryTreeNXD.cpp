#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
inline void read(int &n){
    register char c='*';
    for(n=0;!isdigit(c);c=getchar());
    for(;isdigit(c);n=n*10+c-'0',c=getchar());
}

struct A{
    int id,v;
}a[500010];
bool cmp(A a, A b){
    if(a.v==b.v){return a.id>b.id;}
    else{return a.v>b.v;}
}
int C[500010],n;

int lowbit(int x){return x&(-x);}
void add(int x,int k){for(int i=x;i<=n;i+=lowbit(i)){C[i]+=k;}}
int getsum(int x){int ans=0;for(int i=x;i>0;i-=lowbit(i)){ans+=C[i];}return ans;}

int main(){
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        ans+=getsum(a[i].id);
        add(a[i].id,1);
    }
    printf("%lld\n",ans);
    return 0;
}