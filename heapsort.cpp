#include"heaphop.cpp"
#include<vector>
#include "rindex.h"
#include<iostream>
using namespace std;

BinaryHeap<int> aborttest;
void print(){
    aborttest.showheap();
    cout<<"size: "<<aborttest.currentsize<<endl;
}
int main(){
    srand((unsigned)time(NULL));
    int a[10];
    init(a,10);
    for(int x:a){
        cout<<x<<" ";
    }
    vector<int> v1(a,a+10);
    BinaryHeap<int> b1(v1);
    cout<<endl;
    try{
        aborttest.insert(12);
        aborttest.insert(112);
        for(int i=0;i<1000;i++)
            aborttest.insert(random()%100);
        for(int i=0;i<1000;i++)
            aborttest.deleteMin();
        print();
        print();

    }catch (exception &e ){
        cout<<e.what();
        abort();
    }
    cout<<endl;
    cout<<aborttest.isEmpty();
    cout<<endl;
    /*try{
    }catch (exception &e){
        cout<<e.what();
    }*/
    /*for(int x:a){
        cout<<x<<" ";
    }
    for(int i=0;i<20;i++){
        int x = random()%20;
        if(x<15)
            b1.insert(x);
        else
        
        try{
            b1.deleteMin();
        }catch (exception &e){
            cout<<e.what();
        }
        cout<<" c "<<b1.currentsize<<" ";
    }*/
}
