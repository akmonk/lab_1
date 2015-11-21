// zabbix:x:502:503::/home/zabbix:/bin/bash
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main (void) {
 char buf[3];
 struct user_info {
	char name[8];
	char pass[8];
	int uid;
	int guid;
	char gecos[50];
	char dir[50];
	char shell[50];
 };
 sprintf( buf, "%d", getuid());
 printf("%s\n",buf); 
 return 0;
}
