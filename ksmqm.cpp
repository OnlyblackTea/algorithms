#include<iostream>
using namespace std;
const int MO=10;
void ksm(int &a,int b){
    int ans=1,base=a%MO;
    while(b){
        if(b&1){
            ans=(ans*base)%MO;
        }
        base=(base*base)%MO;
        b>>=1;
    }
    a=ans;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        ksm(a,b);
        cout<<a<<endl;
    }
    return 0;
}