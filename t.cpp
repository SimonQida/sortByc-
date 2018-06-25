#include<iostream>
#include<algorithm>

using namespace std;
class A{
    int Ax;
};

class B{
    A a;
};

void get(int a[][4]){
    //int aa[4][4] = a;
}
int main(){
    int i =1,j=2;
    cout<<i<<" "<<j<<endl;
    swap(i,j);
    cout<<i<<" "<<j<<endl;
    int a[][3]={1,2,3,4,52,4,3,423};
    /*for(auto &x:a[0])
        cout<<x<<" ";*/
    int outrange[5]={},ax=1,bx=2;           //a strange truth
    int num10[10]={};
    for(int i=0;i<10;i++){
        num10[i] = i;
    }
    copy(num10,num10+10,outrange);
    for(auto &x:outrange)
        cout<<x<<" ";
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<outrange[i]<<" ";
    }
    cout<<endl<<"``origin ax = 1 but ax:"<<ax<<endl<<"``origin bx = 2 but bx: "<<bx;
}
