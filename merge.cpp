#include<iostream>
#include"rindex.h"

//give the array name and length_of_array
using namespace std;

void merge_recu(int *arr,int* reg,int start,int end){
    if(start>=end)
        return ;
    int len = end -start,mid = (len>>1)+start;
    int start1= start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 =end;
    merge_recu(arr,reg,start1,end1);        //divide the origin arr into two part until 
    merge_recu(arr,reg,start2,end2);
    int k =start;
    while(start1<=end1&&start2<=end2){
        if(arr[start1]>arr[start2])
            reg[k++] = arr[start2++];

        else reg[k++] = arr[start1++];
    }
    while(start1<=end1){
        reg[k++] = arr[start1++];
    }
    while(start2<=end2){
        reg[k++] = arr[start2++];
    }
    for(k =start;k<=end;k++){
        arr[k] = reg[k];
    }
}

void merge(int *a,int len){
    int reg[len];
    merge_recu(a,reg,0,len-1);
}

/*int main(){
    int arr[10];
    init(arr,sizeof(arr)/sizeof(int));
    merge(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}*/
