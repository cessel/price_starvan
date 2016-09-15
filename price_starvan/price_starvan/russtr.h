int razbor_praisa(char *price, char (*str1)[1024])
{
   int i=0,k=0,l=0,m=0,j=0;
   char buffer[15][1024]; 
   for (i=0;i<strlen(price);i++)
   if (price[i]=='\t')
   {k++;} 
         l=0;
       for(m=0;m<strlen(price);m++)
       {
             if (price[m]=='\t')
             {
              l++;
              str1[l][0]=0;
              j=0;
              continue;
              }
              str1[l][j]=price[m];
              j++;
              continue;        
       }
       if (str1[k][strlen(str1[k])-1]=='\n')
       str1[k][strlen(str1[k])-1]=0;
    return k; 
}




void bubble_sort_str_dir(char *mass[], int n, int dir)
{
     int i,j;   
     char *t;
for(i=n-1;i>=0;i--)
for (j=0;j<i;j++)
 if (dir*strcmp(mass[j],mass[j+1])>0)//поменяв знак ">" на "<" меняет порядок сортировки.
 {t=mass[j];mass[j]=mass[j+1];mass[j+1]=t;}
}

void bubble_sort_str(char *mass[], int n)
{
     int i,j;   
     char *t;
for(i=n-1;i>=0;i--)
for (j=0;j<i;j++)
 if (strcmp(mass[j],mass[j+1])>0)//поменяв знак ">" на "<" меняет порядок сортировки.
 {t=mass[j];mass[j]=mass[j+1];mass[j+1]=t;}
}
//------------------------------------------
void bubble_sort(int *mass, int n)
{
     int i,j,t,seconds;   
for(i=n-1;i>=0;i--)
{ for (j=0;j<i;j++)
 if (mass[j]<mass[j+1])//поменяв знак ">" на "<" меняет порядок сортировки.
 {t=mass[j];mass[j]=mass[j+1];mass[j+1]=t;}
 
 if(i%10000==0)
 {seconds=clock()/CLOCKS_PER_SEC;
 printf("прошло %d секунд - ",seconds);
 printf("Отсортировано %d позиций\n",n-i);}
}
}
//------------------------------------------
int random(int n)
{
 static int next, start=1; 
 if(start) {next = time(0); start=0;} 
 next = next*1103515245 + 12345; 
 return (unsigned int)(next/128) % n;    
}
//------------------------------------------
int double_defis(char * str)
{
int i_ish=0, i_new=0, dlina=0;
char buffer[255];
while (str[i_ish])
{
 if(((i_ish!=0)&&(str[i_ish]=='-')&&(str[i_ish+1] >= 'а' && str[i_ish+1] <= 'я'))||(str[i_ish] >= 'а' && str[i_ish] <= 'я'))
      
      {buffer[i_new++] = str[i_ish];}
     
     i_ish++;    
}
buffer[i_new]=0;
strcpy(str,buffer);
}
//------------------------------------------
int bez_probelov(char * str)
{
  int i_ish=0, i_new=0;
  //char buffer[255];
  
  while (str[i_ish])
  {
        if(str[i_ish]!=' ')
        str[i_new++] = str[i_ish];
        i_ish++;
  //      buffer[i_new]=0;
  
  } 
 // str[i_new]=0;              
 // strcpy(str,buffer);          
}
//------------------------------------------
char toupper_rus(char ch)
{
    ch=toupper(ch);
    if (ch=='ё')
    ch='Ё';
    if (ch >= 'а' && ch <= 'я')
     ch=ch&223;
     return ch;
}
//------------------------------------------
char tolower_rus(char ch)
{
    ch=tolower(ch);
    if (ch=='Ё')
    ch='ё';
    if (ch >= 'А' && ch <= 'Я')
     ch=ch|32;
     return ch;
}
//------------------------------------------
int russian_glas(char bukva)
    {
     int i=0;
     char RU_glas[]={'а','о','и','е','ё','у','ы','э','ю','я','А','Е','Ё','И','О','У','Ы','Э','Ю','Я'};
     for   (i=0;i<20;i++)
           {
           if (bukva==RU_glas[i]) 
           {return 1;}               
           }
     return 0;
}
//------------------------------------------
int english_glas(char bukva)
    {
     int i=0;
     char EN_glas[]={'a','e','i','u','o','y','A','E','I','U','O','Y'};
     for   (i=0;i<12
     ;i++)
           {
           if (bukva==EN_glas[i]) 
           {return 1;}               
           }
     return 0;
}
//------------------------------------------
int russian_soglas(char bukva)
    {
     int i=0, l=0;
     char RU_soglas[]={'Б','В','Г','Д','Ж','З','Й','К','Л','М','Н','П','Р','С','Т','Ф','Х','Ъ','Ь','Ч','Ц','Ч','Ш','Щ'};
     for   (i=0;i<24;i++)
           {
           bukva=toupper_rus(bukva);
           if (bukva==RU_soglas[i]) 
           {return 1;}               
           }
     return 0;
}
//------------------------------------------
int english_soglas(char bukva)
    {
     int i=0;
     char EN_soglas[]={'B','F','J','N','R','V','M','Q','X','S','W','Z','C','G','K','D','H','L','P','T'};
     for   (i=0;i<20;i++)
           {
           bukva=toupper(bukva);              
           if (bukva==EN_soglas[i]) 
           {return 1;}               
           }
     return 0;
}
//------------------------------------------
int etodigit(char bukva)
{
    int i=0;
     char digit[]={'0','1','2','3','4','5','6','7','8','9'};
     for   (i=0;i<10;i++)
           {         
           if (bukva==digit[i]) 
           {return 1;}               
           }
     return 0;      
}
//------------------------------------------
int etoznak(char ch)
{
    int k;
   k=etodigit(ch)+english_soglas(ch)+russian_soglas(ch)+english_glas(ch)+russian_glas(ch);
       if (k==0)
       return 1;
       
   return 0;   
}
//------------------------------------------
int bez_znakov(char * str)
{
  int i_ish=0, i_new=0, dlina=0;
  char buffer[255];
  
  while (str[i_ish])
  {
        if(etoznak(str[i_ish]))
        buffer[i_new++] = str[i_ish];
        i_ish++;
        buffer[i_new]=0;
  }               
  strcpy(str,buffer);          
}
//------------------------------------------
int bez_znakov_s_defisami(char * str)
{
  int i_ish=0, i_new=0, dlina=0;
  char buffer[255];  
  while (str[i_ish])
  {
        if((etoznak(str[i_ish])!=1)||((str[i_ish]=='-')&&(str[i_ish+1]!=0)))
        buffer[i_new++] = str[i_ish];
        i_ish++;
        buffer[i_new]=0;
  }               
  strcpy(str,buffer);   
}
//------------------------------------------
void nreg(char *stroka)
{
     int i;
     
     for (i=0;i<strlen(stroka);i++)
        { if (stroka[i]!=' ')
            stroka[i] = stroka[i]|32;
            else stroka[i]=' '; 
            }   
     }
//------------------------------------------
void treg(char *stroka)

{
     int i;
     if (stroka[0]!=' ')
     stroka[0]=stroka[0]&223;
     
     for (i=0; i<strlen(stroka);i++)
     if((stroka[i]==' '||stroka[i]=='-')&&(stroka[i+1]!=' '))
       stroka[i+1]==stroka[i+1]&223;
}
//------------------------------------------
void delspace (char *Str)
{
int Pntr = 0;
int Dest = 0;
char buff[100];
 
while (Str [Pntr])
{
if (Str [Pntr] != ' ')
	buff [Dest++] = Str [Pntr];
Pntr++;
}
}
//------------------------------------------
char *zamena_stroki (char *stroka, char *poisk, char *zamena)
{
char *p;
static char buffer[4096];

if (!(p=strstr(stroka, poisk))) return stroka;

strncpy(buffer,stroka,(p-stroka));
buffer[p-stroka]=0;

strcat(buffer,zamena);
strcat(buffer,p+strlen(poisk));

return buffer;  
}



