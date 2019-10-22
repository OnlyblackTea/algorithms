#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[500001];
int t[500001];

void merge(int l,int r,int m,int *a,int *t,long long &ans){
    int i=l;
    int j=m+1;
    int k=l;
    while(i<=m&&j<=r){
        if(a[i]>a[j]){
            t[k++]=a[j++];
            ans+=m-i+1;
        }
        else{
            t[k++]=a[i++];
        }
    }
    while(i<=m) t[k++]=a[i++];
    while(j<=r) t[k++]=a[j++];
    for(i=l;i<=r;i++){
        a[i]=t[i];
    }
}
void merge_sort(int l,int r,int *a,int *t,long long &ans){
    if(l<r){
        int mid=(l+r)>>1;
        merge_sort(l,mid,a,t,ans);
        merge_sort(mid+1,r,a,t,ans);
        merge(l,r,mid,a,t,ans);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int ans=0;
    merge_sort(1,n,a,t,ans);
    printf("%lld\n",ans);
    return 0;
}