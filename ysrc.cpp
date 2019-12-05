#include<iostream>
#include<cstring>
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
struct Point{
    int x,y;
    Point(int x,int y):x(x),y(y){};
};
struct Seg{
    int _L,_R;
    Seg():_L(0x3f3f3f3f),_R(0){};
};
queue<Point> SeQ;
Seg Li[505];
int a[505][505];
int v[505][505];
int dp[505];
int main(){
    ifstream _in;
    _in.open("F:\\homeworks\\git\\algorithms\\testdata.in");
    memset(a,0x7f,sizeof(a));
    memset(dp,0x7f,sizeof(dp));
    memset(v,-1,sizeof(v));
    int m,n;
    _in>>m>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            _in>>a[i][j];
        }
    }
    for(int i=402;i<=m;i++){
        SeQ.push(Point(1,i));
        while(!SeQ.empty()){
            v[SeQ.front().x][SeQ.front().y]=i;
            if(SeQ.front().x==n){
                Li[i]._L=min(Li[i]._L,SeQ.front().y);
                Li[i]._R=max(Li[i]._R,SeQ.front().y);
            }
            if(v[SeQ.front().x+1][SeQ.front().y]!=i&&a[SeQ.front().x][SeQ.front().y]>a[SeQ.front().x+1][SeQ.front().y]){
                SeQ.push(Point(SeQ.front().x+1,SeQ.front().y));
            }
            if(v[SeQ.front().x-1][SeQ.front().y]!=i&&a[SeQ.front().x][SeQ.front().y]>a[SeQ.front().x-1][SeQ.front().y]){
                SeQ.push(Point(SeQ.front().x-1,SeQ.front().y));
            }
            if(v[SeQ.front().x][SeQ.front().y+1]!=i&&a[SeQ.front().x][SeQ.front().y]>a[SeQ.front().x][SeQ.front().y+1]){
                SeQ.push(Point(SeQ.front().x,SeQ.front().y+1));
            }
            if(v[SeQ.front().x][SeQ.front().y-1]!=i&&a[SeQ.front().x][SeQ.front().y]>a[SeQ.front().x][SeQ.front().y-1]){
                SeQ.push(Point(SeQ.front().x,SeQ.front().y-1));
            }
            //cout<<v[SeQ.front().x][SeQ.front().y]<<" ";
            SeQ.pop();
        }
        _sleep(10);cout<<i<<endl;
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(v[n][i]==-1) cnt++;
    }
    if(cnt==0){
        dp[1]=1;
        dp[0]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=Li[i]._R;j++){
                dp[j]=min(dp[j],dp[Li[i]._L-1]+1);
            }
        }
        printf("1\n%d",dp[m]);
    }
    else{
        printf("0\n%d",cnt);
    }
    return 0;
}