#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "errno.h"

// длина каталога
#define MAX_PATH_SIZE 128

int main(int argc, char *argv[])

{
  int i;
  char *pid;
	// переданы ли pid
	if (argc < 2)
	{
	  printf("Ошибка. Введите pwdx pid1 [pid2]\n");
	  return 1;
	}
        else
	{
          for (i=1;i<argc;i++)
	  {
	  char *path_buf = malloc(MAX_PATH_SIZE);
          char *buf, *s;
	  pid = argv[i];
          ssize_t len, buf_len;
          buf_len = 10 + strlen(pid) + 1;
          buf = malloc(buf_len);
                sprintf(buf,"/proc/%s/cwd",pid);
                len = readlink(buf, path_buf, MAX_PATH_SIZE);
                free(buf);
                if (len < 0)
                {
                        s = strerror(errno == ENOENT ? ESRCH : errno);
                        fprintf(stderr, "%s: %s\n", pid, s);
                        free(path_buf);
                        return 1;
                }
                printf("%s: %s\n",pid,path_buf);
                free(path_buf);
                return 0;
	}
	}
}

