#include<iostream>
#include "rindex.h"

using namespace std;

void insert(int* oa,int len){
    int temp = 0,i = 1,j=0;
    for(;i<len;++i){
        temp = oa[i];
        for(j=i;j>0&&oa[j-1]>temp;--j){
            oa[j] = oa[j-1];
        }
        oa[j] = temp;
    }

}

int main(){
    auto insertlam = [](int *oa,int len){
    int temp = 0,i = 1,j=0;
    for(;i<len;++i){
        temp = oa[i];
        for(j=i;j>0&&oa[j-1]>temp;--j){
            oa[j] = oa[j-1];
        }
        oa[j] = temp;
    }
    };

    srand((unsigned)time(NULL));
    int arr[10] ;
    init(arr,10);
    cout<<endl;
    insertlam(arr,10);
/*    [=](){
        int temp = 0,i = 1,j=0;
        for(;i<10;++i){
            temp = arr[i];
            for(j=i;j>0&&arr[j-1]>temp;--j){
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
        }
    };*/
    for(int i =0;i<10;++i){
        cout<<arr[i]<<" ";
    }
}
