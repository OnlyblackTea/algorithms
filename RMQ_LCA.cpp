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
    memset(fa,0,sizeof(fa));
    int n,m,s;
    scanf("%d",&n);
    int x,y;
    fa[s]=-1;
    build(s);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
    }
}