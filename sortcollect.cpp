#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<time.h>

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

void jishu(int *oa,int len){
    int order[len] = {};
    int max=0;
    for(int i=0;i<len;i++){
        max = max>oa[i]?max:oa[i];
    }
    cout<<"max: "<<max;
    int ji[max+1]={0};
    int temp =0,temp1 = 0;
    for(int j=0;j<len;++j)
       ji[oa[j]]++;
    for(int i =1;i<max+1;++i){
        ji[i] = ji[i]+ji[i-1];
    }
    cout<<endl;
    for(int i=0;i<10;++i){
        cout<<i<<" " ;
    }
    cout<<endl;
    for(int i=0;i<max+1;++i){
        cout<<ji[i]<<" " ;
    }
    cout<<endl;
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

bool check(int* a,int len){
    if(len <2) return true;
    for(int i=1;i<len;i++){
        if(a[i]<a[i-1])
            return false;
    }
    return true;
}

void radix(int *a,int len){

}

void randompartition(int *a,int len){
    int *random = new int[len];     //计数排序实现乱序原数组
    for(int i=0;i<len;i++){
        random[i] = rand()%10;
        //cout<<random[i];
    }
    int max=0;
    for(int i=0;i<len;i++){
        max = max>a[i]?max:a[i];
    }
    int order[len] = {};
    int ji[max+1]={0};
    int temp =0,temp1 = 0;
    for(int j=0;j<len;++j)
       ji[random[j]]++;
    for(int i =1;i<max+1;++i){
        ji[i] = ji[i]+ji[i-1];
    }
    for(int i =len-1;i>=0;i--){
        temp = random[i];
        temp1 = ji[temp]-1;
        order[temp1] = a[i];
        ji[random[i]]--;
    }
    for(int i =0;i<len;i++){
        cout<<order[i]<<" ";
    }
    cout<<endl;
    cout<<endl;
    partition(order,0,len-1);
    for(int i=0;i<len;i++){
        a[i] = order[i];
    }
}

void merge_recu(int *arr,int* reg,int start,int end){
    if(start>=end)
        return ;
    int len = end -start,mid = (len>>1)+start;
    int start1= start;
    int end1 = mid;
    int start2 = mid+1;
    int end2 =end;
    merge_recu(arr,reg,start1,end1);
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

int main(){
    srand((unsigned)time(NULL));
    int len = rand()%20+1;
    int arr[len];
    for(int i=0;i<len;i++){
        arr[i] = rand()%100;
    }
    for(int i =0;i<len;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
//    insert(arr,len);
//    partition(arr,0,len-1);
//    jishu(arr,len);
    //radix(arr,len);
    randompartition(arr,len);
//    merge(arr,len);
    for(int i =0;i<len;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"sort succeed?  "<<check(arr,10);
}
