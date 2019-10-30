#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int a[1010][1010];
int b[1010][1010];
int main(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    b[1][1]=a[1][1];
    for(int i=2;i<=n;i++){
        b[i][1]=b[i-1][1]+a[i][1];
        for(int j=2;j<i;j++){
            b[i][j]=max(b[i-1][j-1],b[i-1][j])+a[i][j];
        }
        b[i][i]=b[i-1][i-1]+a[i][i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,b[n][i]);
    }
    printf("%d\n",ans);
    return 0;
}