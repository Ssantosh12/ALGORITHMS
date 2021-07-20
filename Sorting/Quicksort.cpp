#include <bits/stdc++.h>
using namespace std;

int part(int arr[],int low,int high){
    int pivot=arr[high];
    int j,i=low-1;
    for(j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(int arr[],int low ,int high){
    if(low<high){
        int pind= part(arr,low,high);
        quicksort(arr,low,pind-1);
        quicksort(arr,pind+1,high);
    }
    return;
}

int main(){

    int n,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    quicksort(arr,0,n-1);
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
