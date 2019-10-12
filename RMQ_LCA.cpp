#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

#define NUM1 500050
#define NUM2 500050
using namespace std;

//------------------------------------------------
int fa[NUM1];
void reset(){for(int i=0;i<=NUM1;i++){fa[i]=i;}}
int getfa(int x){return fa[x]==x?x:getfa(fa[x]);}
void merge(int x,int y){fa[getfa(x)]=getfa(y);}
//------------------------------------------------

/*--------------------------------------------
struct Edge{
    int u,v,next,w;
}e[NUM2];
int h[NUM1];
int sum=1;
bool vi[NUM1];
void adde(int x,int y){
    e[sum].u=x;
    e[sum].v=y;
    e[sum].next=h[x];
    h[x]=sum++;
}
--------------------------------------------

//-------------------------------------
int fa[NUM1];
void build(int cur){
    int tmp=h[cur];
    while(tmp!=-1){
        if(fa[cur]!=e[tmp].v){
            fa[e[tmp].v]=cur;
            build(e[tmp].v);
        }
        tmp=e[tmp].next;
    }
}
//-------------------------------------*/

vector<int> G[NUM1];
int fa[NUM1];
void build(int cur){
    for(vector<int>::iterator tmp=G[cur].begin();tmp!=G[cur].end();tmp++){
        if(fa[cur]!=*tmp){
            fa[*tmp]=cur;
            build(*tmp);
        }
    }
}



int main(){
    //memset(h,-1,sizeof(h));
    memset(fa,0,sizeof(fa));
    int n,m,s;
    scanf("%d",&n);
    int x,y;
    /*for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        adde(x,y);adde(y,x);
    }*/

    fa[s]=-1;
    build(s);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
    }
}