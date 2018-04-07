#include<iostream>
#include "rindex.h"
using namespace std;

void bubble(int a[],int n){
    int temp;
    for(int i=0;i<n;++i)
        for(int j=0;j<n-i-1;++j)
            if(a[j]>a[j+1])
                temp = a[j],a[j] = a[j+1],a[j+1] = temp;
}

/*int main(){
    int a[20];
    init(a,sizeof(a)/sizeof(int));
    bubble(a,sizeof(a)/sizeof(int));
    for(int x:a)
        cout<<x<<" ";
}*/
