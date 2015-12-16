
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc, char* argv[]) {
   FILE *file;
   // имя файла
   char *fname = "/etc/passwd";
   // переменнные для логина и userid из файла
   char logname[100],uuid[10]; 
   file = fopen(fname,"r");
   // uid из системного вызова
   register uid;
   uid = geteuid ();
   //printf("uid: %i\n",uid); 
   if(file == 0)
   {
      printf("Не хватет прав для открытия '%s'",fname);
      return 0;
   }
   
   int i=0;

 char symb;
 int dv=0;
 int sl,sm,sn,save;
 sl=sm=sn=0; 
 for (i=0;i<10;i++) uuid[i]=0; 


while(1)
 {
  symb=fgetc(file);
  if(feof(file)!=0) break;
  if(symb!='\n')
  {
   if(symb==',') {sl=0; sm++;}
   if(symb==':') {
	if (dv==3) {
		// если uid из файла passwd совпадает с результатом из системного вызова
		if (atoi(uuid)==uid) {
			printf("%s\n",logname);
			return 0;
		}
		// обнуляем переменные
		for (i=0;i<100;i++) logname[i]=0;
		for (i=0;i<10;i++) uuid[i]=0;
	}
	dv++; sl=0;
   }
   // пока не встретились первое : - это логин
   if(dv==0) {
        logname[sl]=symb; sl++;
   }
   // все что после второго : - uid
   if(dv==2) {
              if(symb!=',' && symb!='.' && symb!=':') {
		uuid[sl]=symb; 
		sl++;
		}
             }
  }
   // после 6 : обнуляем переменные
   if(dv==6) {
              if(symb=='\n') {
                dv=0; sn++; sl=0; sm=0;
                }
 }
}
   fclose(file);
 
return 0;
}
