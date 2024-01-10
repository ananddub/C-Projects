#include<stdio.h>
#include<conio.h>
#include<string.h>
void filerr(char*,char); 
void rm(data);
int main()
        {
        char data[1000000];
        char name[1000]="temp.txt"; 
        clrscr();
        filer(data,name); 
      //  printf("%s",data); 
        return 1; 
        }   
void filer(char*dest,char namec[1000])
        { 
        FILE*fp;        
        char data[100000]={'\0'};
        fp=fopen(namec,"r");
        dest[0]='\0';  
        while(fgets(data,sizeof(data),fp)!=NULL)
                {      
                rm(data);
                strcat(dest,data);                
                }
        fclose(fp);
        }
void rm(char *token)
        {
        int len=strlen(token)-1;
        int arr[1000];
        int cn=0; 
        int i; 
        int total=0;
        for(i=len;i>0;i++)
                {
                if(token[i]=='\n')
                        {
                        arr[i]=i;
                        total+=1;
                        }
                else if(token[i]!=' ')
                        {
                        printf("pass :%d",token[i]);
                        break;
                        }
                }
        for(i=0;i<total&&total> 1;i++)
                {
                token[arr[i]]='\0';
                }  
        printf("%s",token);   
        }
