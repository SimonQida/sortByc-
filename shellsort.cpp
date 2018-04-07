#include<iostream>
#include "rindex.h"
using namespace std;

void insert(int* oa,int len,int pace){
    int temp = 0,i = 0,j=0;
    for(int start = 0;start<pace;start++){
        for(i=start;i<len;i+=pace){
            temp = oa[i];
            for(j=i;j>pace-1&&oa[j-pace]>temp;j-=pace){
                oa[j] = oa[j-pace];
            }
            oa[j] = temp;
        }
    }
}

void shellinsert(int *oa,int len){              //edited by changing function insert
    int temp = 0,start =0,j,pace=len/2+1;
    while(1){
        insert(oa,10,pace);
        if(pace ==1)    break;
        if(pace ==2){
            pace = 1;
            continue;
        }
        pace = pace/2+1;
    }
}

int main(){
    int a[10] ;
    init(a,10);
    shellinsert(a,10);
    for(int x:a)
        cout<<x<<" ";
}
