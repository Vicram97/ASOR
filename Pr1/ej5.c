#include <unistd.h>
#include <sys/utsname.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/types.h>



int main(){
    struct utsname info;
    if(uname (&info) == -1){
    printf("ERROR(%d): %s\n",errno, strerror(errno));
    return 1;
    } 
    else{
        printf("Nombre del sistema: %s\n", info.sysname);
    }
    return 1;
}