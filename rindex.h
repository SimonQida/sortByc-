#include<stdlib.h>
#include<time.h>

void init(int *oa,int len){
    srand((unsigned)time(NULL));
    for(int i=0;i<len;i++)
        oa[i] = random()%199;
}

int getr(){
    srand((unsigned)time(NULL));
    return random()%200;
}
