#include<iostream>
using namespace std;
int a[10000];
int dp[10000];
int main(){
    int n,ans=0;;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dp[i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i]<=a[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    return 0;
}