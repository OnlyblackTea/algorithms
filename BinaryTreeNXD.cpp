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

int C[],n;
int lowbit(int x){return x&(-x);}
void add(int x,int k){
    for(int i=x;i<=n;i+=lowbit(i)){
        C[i]+=k;
    }
}
int getsum(int x){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=C[i];
    }
    return ans;
}
int main(){

}