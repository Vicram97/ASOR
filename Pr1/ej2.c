#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(){

if(setuid(0) == -1){
printf("Error(%d): %s \n",errno,strerror(errno));

}

return 1;
}
