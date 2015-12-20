#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
int i;
char buf[PATH_MAX+1];
     regex_t re;

if (argc < 2){
          printf("укажите pid\n");
	  return 0;
}

//проверка на существование процесса с нужным pid
for (i = 1; i < argc; i++) {
          if (regexec(&re, argv[i], 0, NULL, 0) != 0) {
               snprintf(buf, sizeof buf, "pwdx: invalid process id: %s\n", argv[i]);
               //die(buf);
	       exit(1);
          }
     } 
for (i = 1; i < argc; i++) {
          char * s = buf;
          int len;
          
          // At this point, all arguments are in the form /proc/nnnn
          // or nnnn, so a simple check based on the first char is
          // possible
          if (argv[i][0] != '/')
               snprintf(buf, sizeof buf, "/proc/%s/cwd", argv[i]);
          else
               snprintf(buf, sizeof buf, "%s/cwd", argv[i]);
	
	if ((len = readlink(buf, buf, PATH_MAX)) < 0) {
//               s = strerror(errno == ENOENT ? ESRCH : errno);
          } else {
               buf[len] = 0;
          }

          printf("%s: %s\n", argv[i], s);
}

return 0;
}
