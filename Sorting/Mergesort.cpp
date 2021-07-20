#include <bits/stdc++.h>
using namespace std;

 void merging(int arr[],int left,int mid,int right){
     //create two temporary arrays that will contain the left subarray and right subarray
     int  i,sizl=mid-left+1,sizr=right-mid;
     int larr[sizl];
     int rarr[sizr];
     
    //copy elements from the main array
     for(i=0;i<sizl;i++)
        larr[i]=arr[left+i];

     for(i=0;i<sizr;i++)
        rarr[i]=arr[mid+1+i];

     int indl=0,indr=0,indarr=left;

    //merge the two sorted subarrays in the main array using the standard merging procedure of merging two sorted subarrays
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

     //inserting remaining elements ,if any
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

 void mergesort(int arr[],int left,int right){
     if(left<right){
        int mid=(left+right)/2;
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
