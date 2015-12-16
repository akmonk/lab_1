#include <stdio.h>
#include <string.h>
 
int main(int argc, char* argv[]) {
   FILE *file;
   char *fname = "/etc/passwd";
   char sting[100];
   char logname[100]; 
   file = fopen(fname,"r");
 
   if(file == 0)
   {
      printf("Не хватет прав для открытия '%s'",fname);
      return 0;
   }
   
   int i=0;
   char *name[100];

 char symb;
 int dv=0;
 int sl,sm,sn,save;
 sl=sm=sn=0; 
 

while(1)
 {
  symb=fgetc(file);
  if(feof(file)!=0) break;
  if(symb!='\n')
  {
   if(symb==',') {sl=0; sm++;}
   if(symb==':') {
	if (dv==0) {
		printf("user: %s\n",logname);
		 for (i=0;i<100;i++) logname[i]=0;
	}
	dv++; sl=0;
   }
   if(dv==0) {
	//group[sn].name[sl]=symb; sl++;
        logname[sl]=symb; sl++;
	if(symb==':'){
//	printf("user: %s\n",name);
	}
   }
   if(dv==3) {
              if(symb=='\n') {
		//group[sn].size=sm; 
                
		dv=0; sn++; sl=0; sm=0;
		}
              if(symb!=',' && symb!='.' && symb!=':') {
		//group[sn].users[sm].user[sl]=symb; 
		sl++;
		}
             }
  }
 
   if(dv==6) {
              if(symb=='\n') {
                //group[sn].size=sm;
                dv=0; sn++; sl=0; sm=0;
                }
 }
}
  /*
   Читаем строку из файла
   Читаем строку по символам
   Как только встретилось 3-е "двоеточие",
     считаем слова, идущие через "запятую", записываем их в переменную NAME и увеличиваем счетчик на 1 
     (т.е. как встретили "запятую", записали то, что было после 3-го "двоеточия" и до "запятой", увел. счетчик)
   Выводим NAME и счетчик
 
   пример:
   в файле много строк и есть одна такая "users::20:root,user1,user2". 
   должно вывести "имя группы:users, число пользователей - 3"
   */
 
   fclose(file);
 
return 0;
}
