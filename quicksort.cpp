#include<iostream>

using namespace std;

void partition(int *a,int left,int right){
    if(right - left <=1)
        return ;

    int pivot = a[right];
    int i=0,j=0,temp=0;
    for(;j<right;j++){
        if(a[j]<=pivot){
            temp = a[j];
            a[j]=a[i];
            a[i] = temp;
            i++;
        }
    }
    temp = a[i];
    a[i] = pivot;
    a[right] = temp;


    partition(a,left,i-1);
    partition(a,i,right);
    
}



int main(){
    int a[10] = {1,2,55,7,86,4,354,5,43,78};
    partition(a,0,9);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}
