#include <bits/stdc++.h>
using namespace std;

 void merging(int arr[],int const left,int const mid,int const right){
     //create two arrays
     auto sizl=mid-left+1,sizr=right-mid;
     auto  *larr = new int[sizl];
     auto  *rarr = new int[sizr];
     for(auto i=0;i<sizl;i++)
        larr[i]=arr[left+i];

     for(auto i=0;i<sizr;i++)
        rarr[i]=arr[mid+1+i];

     auto indl=0,indr=0,indarr=left;

     while(indl<sizl && indr<sizr){
        if(larr[indl]<=rarr[indr]){
            arr[indarr]=larr[indl];
            indl++;
        }
        else{
            arr[indarr]=rarr[indr];
            indr++;
        }
        indarr++;
     }

     //inserting remaining element
     while(indl<sizl){
        arr[indarr]=larr[indl];
        indl++;
        indarr++;
     }

     while(indr<sizr){
        arr[indarr]=rarr[indr];
        indr++;
        indarr++;
     }

 }

 void mergesort(int arr[],int const left,int const right){
     if(left<right){
        auto mid=(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merging(arr,left,mid,right);
     }
     else return;
 }

int main(){

    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergesort(arr,0,n-1);
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

}
