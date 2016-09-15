#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
//#include "libfunctions.c"
#include "russtr.h"
#define _PC putchar('\n'); 
#define _SP system("pause");
#define _RZ return 0;
#define _R1 return 1;
#define _CP SetConsoleCP(1251);SetConsoleOutputCP(1251); 
#define _FF fflush(stdin);
/*Запись в текстовый файл*/
/*Writing into text file*/



int main()
{
    double num=0;
    int i=0, j=0,k=0,vote; 
    char v,buffer[1024], buffer2[1024], buffer0[1024], str1[15][1024], path1[256],path2[256] ;
    char str[]="|";
 _CP
 FILE *file, *file1;

 file=fopen("\\\\CESSEL-PC\Desktop\SEND_PRICE_DONT_CHANGE\pr","r+");
 if(file == NULL){printf("Не получилось открыть файл");_SP;_R1}
 printf("[1] Сокол\n[2] Питер\n[3] Клон: ");
 scanf("%d",&vote);
 
 switch (vote)
 {
        case 1:
             file1=fopen("starvan_test.txt","w+");
             printf("Получилось! Сокол! %d\n",vote);
             if(file1 == NULL){printf("Не получилось открыть файл");_SP;_R1}
             break;
        case 2:
           file1=fopen("price_starvan_test.csv","w+");
           printf("Получилось! Питер! %d\n",vote);
           if(file1 == NULL){printf("Не получилось открыть файл");_SP;_R1}
           break;
        case 3:
           file1=fopen("price_starvan_test.csv","w+");
           printf("Получилось! Клон! %d\n",vote);
           if(file1 == NULL){printf("Не получилось открыть файл");_SP;_R1}
           break;
        default: 
           printf("Неверный выбор %d\n",vote);_SP;_R1  
           break;
}

 
 while (feof(file)==0)
 {      
 fgets (buffer, 1024, file);
 k=razbor_praisa(&buffer,&str1);

  /*if (str1[5][strlen(str1[5])-1]!='\n')
  fprintf(file1,"%s\t%s\t%s\t%s\t%s\t%s\n",str1[0],str1[1],str1[2],str1[3],str1[4],str1[5]);
  else*/
  
   switch (vote)
 {
        case 1:
             fprintf(file1,"%s\t%s\t%s\t%s\t%s\n",str1[0],str1[2],str1[7],str1[3],str1[6]);
             break;
        case 2:
           fprintf(file1,"%s,%s,%s,%s,%s,%s\n",str1[0],str1[1],str1[2],str1[3],str1[4],str1[5]);
           break;
        case 3:
           fprintf(file1,"%s,%s,%s,%s,%s,%s\n",str1[0],str1[1],str1[2],str1[3],str1[4],str1[5]);
           break;
}

 for (i=0;i<15;i++)
     for(j=0;j<1024;j++)
     str1[i][j]=0;
 }
 fclose(file);
 fclose(file1);
 _FF
 _PC
 _SP
 _RZ 
}













