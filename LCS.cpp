#include<iostream>
using namespace std;
char A[100];
char B[100];
int dp[100][100];
int main(){
    int n,m;//n,m<100
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%c",&A[i]);
        dp[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        scanf("%c",&B[i]);
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i]==B[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}