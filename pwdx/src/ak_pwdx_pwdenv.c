#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "errno.h"

// длина каталога
#define MAX_PATH_SIZE 128

int pwdx (char * pid)
{
  char *path_buf = malloc(MAX_PATH_SIZE);
  char *buf, *s;
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
