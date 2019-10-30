#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int g[200010];
queue<int> q;
int v[200010];
int main(){
    int n,ans=0,sum=0,cnt=0,max=0;
    memset(v,-1,sizeof(v));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&g[i]);
    }
    for(int i=1;i<=n;i++){
        if(v[i]==-1){
            v[i]=++cnt;
            
        }
    }
    sprintf()
}