#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,btree[500010],a[500010];
int lowbit(int x){return x&(-x);}
void add(int x,int k){ for(int i=x;i<n;i+=lowbit(i)) {btree[i]+=k;} }
int getsum(int x){ int ans=0; for(int i=x;i;i-=lowbit(i))ans+=btree[i]; return ans; }

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){ scanf("%d",&a[i]); add(i,a[i]); }
    int x,y,order;
    for(int i=1;i<=m;i++){ scanf("%d%d%d",&order,&x,&y); if (order==1) { add(x,y);a[x]+=y; } else if (order==2) { printf("%d\n",getsum(y)-getsum(x-1)); } }
    return 0;
}