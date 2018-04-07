#include<iostream>

using namespace std;

void jishu(int *oa,int len){
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
        order[temp1] = temp;
        ji[oa[i]]--;
    }
    for(int i =0;i<len;i++){
        oa[i] = order[i];
    }
}
/*
  int main(){
   int oa[20] = {2,4,5,1,6,9,8,5,7,2,2,4,5,1,6,9,8,5,7,2};
   jishu(oa,sizeof(oa)/sizeof(int));
   for(int i =0;i<sizeof(oa)/sizeof(int);i++){
       cout<<oa[i]<<" ";
   }
}
*/
