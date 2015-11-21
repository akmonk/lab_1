#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main (void) {
 char buf[3];
 sprintf( buf, "%d", getuid());
 printf("%s\n",buf); 
return 0;
}
