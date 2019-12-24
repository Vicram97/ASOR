#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(){
    const int MAX = 255;
    for(int i = 0; i < MAX;++i){
        printf("ERROR(%d):%s\n",i,strerror(i));
    }
    return 1;
}