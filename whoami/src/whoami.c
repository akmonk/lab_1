// zabbix:x:502:503::/home/zabbix:/bin/bash
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>

int main (void) {
 register struct passwd *pw;
 register uid_t uid;
 int c;

 uid = geteuid ();
 pw = getpwuid (uid);
  if (pw)
  {
	puts (pw->pw_name);
//	puts (pw);
  }

 return 0;
}
