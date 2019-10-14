#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,btree[500010],a[500010];
int lowbit(int x){return x&(-x);}
void add(int x,int k){
    for(int i=x;i<n;i+=lowbit(i)){
        
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
}