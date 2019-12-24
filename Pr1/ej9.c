#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main(){

printf("UID Real: %d\n", getuid());
printf("UID Efectivo:%d\n", getgid());

printf("Username:%s\n",getpwuid(getuid())->pw_name);
printf("Home:%s\n",getpwuid(getuid())->pw_dir);
printf("Info:%s\n",getpwuid(getuid())->pw_gecos);

return 1;
}