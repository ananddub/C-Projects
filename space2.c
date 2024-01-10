#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h> 
void filer(char*,const char[]);
void filew(const  char[],const char[]);
void filea(const char[],const char[]);
void space(char*,const int);
void purify(char*); 
int swcheck(char*,const int);
void cmd(const char[],const char[]);
void namech(char*);
int main(int arg,char *argc[]) 
        {
        char data[1000000];
        char name[10000]="test";
        if(arg==0)
                {
                printf("please give filename");
                return 0;
                }
        strcpy(name,argc[1]);  
        namech(name);
        cmd("temp.txt",name);    
        filer(data,"temp.txt"); 
        filew(data,name) ;  
        printf("read :%s\n%s",name,data); 
        return 1;
        }  
void filer(char*token,const char name[])
        { 
        FILE*fp;
        char data[10000]; 
        fp=fopen(name,"r");
        if(fp==NULL)
                { 
                printf("unable to open file for read");
                return ;
                } 

        token[0]='\0';
        while((fgets(data,sizeof(data),fp))!=NULL)
                {
                purify(data); 
                strcat(token,data);
                }
        } 
void namech(char *token)
        { 
        char data[1000]; 
        strcpy(data,token);
        if(strstr(data,".c")==NULL)
                {  
                sprintf(token,"%s.c",data); 
                printf("%s",token); 
                }
        }
void locexa(char *cd, char *data, char *temp)
{
char tempc[1000];
char *ptr = tempc;
char cc[10000];
char *token = cc;
char len;
int cn = 0;
int tlen = 0;
int i;
len = 0;

strcpy(tempc, data);
cd[0] = '\0';
temp[0] = '\0';
strcpy(cc, tempc);
for (i = strlen(tempc); ptr[i] != '/'; i--)
{
ptr[i] = '\0';
}
sprintf(cd, "%s", ptr);
token[i] = '\0';
token += i + 1;
strcpy(temp, token);
}

void cmd(const char dest[],const char name[])
        {
        FILE*fp; 
        char clang[]="clang-format --style=\"{BasedOnStyle: Microsoft, IndentWidth: 8}\"";         
        char cmdrun[1000];
        char data[10000]; 
        sprintf(cmdrun,"%s %s",clang,name); 
        fp=popen(cmdrun,"r");
        if(fp==NULL)
                {
                printf("unable to run command");
                return ;
                } 
        filew("",dest);
        while(fgets(data,sizeof(data),fp)!=NULL)
                { 
                filea(data,dest); 
                }
        pclose(fp);
        }
void purify(char*token)
        {
        static int switchc=0;
        if(strstr(token,"switch")||switchc==1)
                {
                switchc=swcheck(token,8);
                } 
        else if(( strchr(token,'=')==NULL)&&(strchr(token,'{')!=NULL ||strchr(token,'}')!=NULL))
                {
                space(token,8);
                }
        }
int swcheck(char*token,const int sp)
        {
        static int casee=0;
        static int broc=0;
        static int rest=0;
        static int iff=1;
        if(strstr(token,"switch")!=NULL)rest=1;
        else if(strchr(token,'=')==NULL&&strchr(token,'{')!=NULL)
                {  
                broc+=1;
                space(token,sp);
                }
        else if(strchr(token,';')==NULL&&strchr(token,'}')!=NULL)
                { 
                broc-=1;
                space(token,sp); 
                }
        else if(broc>=1)
                 {
                space(token,sp); 
                } 
        if(rest)return 1;
        else if(broc==0)return 0;
        else return 1;
        } 
void space(char*token,const int sp)
        {
        char space[100];
        char cont[100000];
        int i;
        for(i=0;i<sp;i++)space[i]=' ';
        space[i]='\0';   
        strcpy(cont,token);
        sprintf(token,"%s%s",space,cont);
        } 
void filew(const char token[],const char name[])
        {
        FILE* fp=fopen(name,"w");  
        if(fp==NULL)
                {
                printf("unable to open file for write");
                return ;
                } 
        fp=fopen(name,"w");
        fprintf(fp,"%s",token);
        fclose(fp);    
        }
void filea(const char token[],const char name[])
        {
        FILE*fp=fopen(name,"a"); 
        if(fp==NULL)
                {
                printf("unable to open file for append");
                return ;
                }  
       
        fprintf(fp,"%s",token);
        fclose(fp);   
        } 

