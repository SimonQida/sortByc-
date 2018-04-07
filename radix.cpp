#include<iostream>
#include<cmath>
#include"rindex.h"
using namespace std;
//undone with strange problem

void jishu_radix(int *oa,int *ori,int len){
    int order[len] = {};
    int ji[10]={0};
    int temp =0,temp1 = 0;
    for(int j=0;j<len;++j)
        ji[oa[j]]++;
    for(int i =1;i<10;++i)
        ji[i] += ji[i-1];
    for(int i =len-1;i>=0;i--){
        temp = oa[i];
        temp1 = ji[temp]-1;
        order[temp1] = ori[i];      //
        ji[oa[i]]--;
    }
    for(int i =0;i<len;i++){
        ori[i] = order[i];
    }
}

void radix(int *a,int len){
    double t;
    int point,x;
    int max =1;
    int temp[len];
    int pace=1 ;
    for(int i =0;i<10;i++){
        while(a[i]>pow(10,max)){
            max++;
        }
    }
    for(int j=0;j<max;++j){
        for(int i=0;i<len;i++){
            x = a[i]%(pace*10)/pace;
            temp[i] = x;
        }
        jishu_radix(temp,a,len);
        pace*=10;
    }
}

int main(){
    int a[24] ;
    init(a,sizeof(a)/sizeof(int));
    radix(a,sizeof(a)/sizeof(int));
    for(int x:a)
        cout<<x<<" ";
}
