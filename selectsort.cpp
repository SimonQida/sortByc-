#include<iomanip>
#include<iostream>
#include "rindex.h"
using namespace std;

int selectsort(int *oa,int len){
    int tempi,tmp;           //tempi stands index and tmp is to exchange the two nums 
    for(int i=0;i<len;i++){
        tempi = i;
        for(int j=i;j<len;j++){
            tempi = oa[j]<oa[tempi]?j:tempi;    //symbol the mini num's index
        }
        if(tempi<i) abort();            // logically, it won't abort
        swap(oa[tempi],oa[i]);          //swap good to use
        /*tmp =  oa[i];
        oa[i] = oa[tempi];
        oa[tempi] = tmp;
        */
    }
}

int bssort(int *oa,int len){
    int tempa,tmp,tempi;       //tempa means max  tempi means min
    for(int i=0;i<len/2;i++){
        tempi = i;
        tempa = len-i-1;
        cout<<i<<" "<<len-i<<" `` "<<tempi<<" "<<tempa<<" ";
        for(int j=i;j<len-i;j++){           //a strange bug once again
            if(oa[j]>oa[tempa])
                tempa = j;
            if(oa[j]<oa[tempi])
                tempi = j;
            //tempi = oa[j]<oa[tempi]?j:tempi;
            //tempa = oa[j]>oa[tempa]?j:tempa;
        }
        cout<<" `` "<<tempi<<" "<<tempa<<" ";
        if(tempi ==len-i-1||tempa==i){
            if(tempi ==len-i-1&&tempa ==i){
                swap(oa[tempi],oa[tempa]);
            }
            else if(tempi ==len-i-1){
                swap(oa[tempi],oa[i]);
                swap(oa[tempa],oa[len-i-1]);
            }
            else{
                swap(oa[tempa],oa[len-i-1]);
                swap(oa[tempi],oa[i]);
            }
        }else{
            swap(oa[tempi],oa[i]);
            swap(oa[tempa],oa[len-i-1]);
        }
        cout<<i<<" ";
        for(int i=0;i<len;i++)
            cout<<setw(5)<<oa[i];
        cout<<endl;
    }

}
bool check(int * oa,int len){
    for(int i=1;i<len;i++){
        if(oa[i]<oa[i-1]) return false;
    }
    return true;
}

int main(){
    cout<<"                        ";
    cout.setf(ios::right);
    for(int i =0;i<10;i++)
        cout<<setw(5)<<i;
    cout<<endl;
    int a[10] ;
    init(a,10);
    for(int  x:a)
        cout<<x<<" ";
    cout<<endl;
    bssort(a,10);
    for(int  x:a)
        cout<<x<<" ";
    cout<<endl<<check(a,10);
}
