#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(){
char *s = "E";
if(setuid(0)==-1){
	perror("E");
}
else{perror("A");}
return 1;
}
