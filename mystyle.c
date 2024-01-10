#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdarg.h>
#define  tk textcolor
void filer(char *, char[]);
void nfiler(char *, char[]);
void rfiler(char*,char[]); 
void arrange(char *);
void rearrange(char *);
void midputc(char *, char, int *);
void print(char[],int); 
char *wordsep(char*);
void spaces(char*,int);
void filewr(char*,char[]); 
int check(char*,char*);
int keycheck(char data[]);
int scheck(char*,char*);
const char kybd[1000] = {"abcdefghijlnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~"
                         "!1@#$%^&*()_+234567890-=|\"':;?/,>.<\\"};
const char keych[1000] = {"abcdefghijlnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ`~"
                          "!1@#$%^&*()_+234567890-=|\"':;?/,>.<\\{}"};
   


int main(int arg,char *argc[]) 
        {   
        char data[1000000]={'\0'};  
        char name[1000]={'\0'};
        char run[10000];
        data[0]='\0'; 
        if(arg==1)
                {
                printf("\ngive any file name");
                return 0;
                }
        sprintf(name,"%s",argc[1]);
        printf("%s",argc[1]);
        sprintf(run,"clang-format --style=\"{BasedOnStyle: Microsoft, IndentWidth: 8}\" %s >temp.txt",argc[1]);
        system(run);
        filer(data,"temp.txt");  
        filewr(data,name);
        printf("%s",data); 
        return 1;
        }
void nfiler(char *dest, char filename[]) 
        {
        FILE *fp; 
        char data[10000];
        dest[0] = '\0';
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp))
                {
                strcat(dest, data);    
                }
         fclose(fp);
         }

void filer(char *dest, char filename[]) 
        {
        FILE *fp; 
        char data[10000];
        dest[0] = '\0';
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp))
                {
                arrange(data); 
                strcat(dest, data);    
                }
         fclose(fp);
         }
void rfiler(char *dest, char filename[]) 
        {
        FILE *fp; 
        char data[10000];
        dest[0] = '\0';
        fp = fopen(filename, "r");
        while (fgets(data, sizeof(data), fp))
                {
                rearrange(data);
                strcat(dest, data);  
                }
         fclose(fp);
         }
void filewr(char*data,char filename[])
        {  
        FILE*fp; 
         fp=fopen(filename,"w"); 
        fprintf(fp,data); 
        fclose(fp); 
        } /*
int keycheck(char data[])
        {
        int i=0;
        for(i=0;i<strlen(data);i++)
                {  
                 if(data[i]=='\n')
                        { 
                        printf("fail %c",data[i]);  
                        return 1;
                        }
                }
        printf("pass %d",i); 
        return 0;
        }*/
void arrange(char *data) 
        { 
        int i, cn = 0,  j; 
        char tempc[10000]={'\0'};  
        static int  brac = 0;
        static int flag = 0; 
        char  user[100000]={'\0'};
        const char pass[100000]={"{}\n"};
        char jeet[100000];  
        char *token=jeet;
        char *rest=tempc;  
        char small[100000];   
        char *smptr=small;
        char bracke[100000]={'\0'} ;
        char space[100000]; 
        int lp=0,sp=0;
        char ch=' ';  
        char strch[1000000];
        int  col;
        int cases=0;
        flag=0;
        strcpy(tempc, data);
        token[0]='\0'; 
        token=wordsep(tempc);
        strcpy(small,token);
        col=check(small,&ch);
        strcpy(token,small);
        if(col==1)brac+=1;
        if(col)
                 { 
                 static int confus=0;
                 spaces(space,brac);
                 spaces(strch,brac);
                 if(col==1)
                        { 
                        int bck=0;
                        bck=brac-1;  
                        spaces(strch,bck);   
                        sprintf(small,"%s%s%s%c",strch,token,space,ch);
                        confus=1; 
                        }
                 else if(col==2)
                        {
                        int bck=0;
                        bck=brac;     
                        spaces(strch,bck); 
                        strch[0]='\0';   
                        sprintf(small,"%s%s%s%c",strch,token,space,ch);
                        } 
                 else if(col==4)
                        {    
                        if(cases==0)
                                {
                                brac+=1;
                                cases=1;
                                 }
                        else if(cases==1)
                                {
                                brac-=1;
                                cases=0; 
                                }
                        spaces(space,brac); 
                        sprintf(small,"%s%s%s%c",space,token,space,ch);
                        confus=1;
                        } 

                 else
                        { 
                        sprintf(small,"%s%s",space,token);
                        }
                }
        else
                {
                sprintf(small,"%s",token); 
                } 
        if(col==2)
                {
                if(brac>0)
                brac-=1-cases;
                if(cases>0)cases-=1;  
                }
        strcpy(data,small); 
        } 
int sheck(char *token,char *ch)
        {
        char tempc[1000]; 
        char *data=tempc;
        int i;    
        strcpy(tempc,token);    
        for(i=strlen(token)-1;i>=0;i--)
                { 
                if(token[i]=='{')
                        {
                        token[i]='\0';
                        *ch='{';
                        return 1;
                        } 
                else if(token[i]=='}')
                        {
                        token[i]='\0';
                        *ch='}';
                        return 2;
                        }
                else if(token[i]==';') 
                        {
                        return 3;
                        }
                else if(strstr(token,"case")!=NULL) 
                        {
                        return 4;
                        }  
                else if(token[i]!=' ')
                        {
                        return 10;
                        }
                } 
        }

int check(char *token,char *ch)
        {
        char tempc[1000]; 
        char *data=tempc;
        int i;    
        strcpy(tempc,token);    
        for(i=strlen(token)-1;i>=0;i--)
                { 
                if(token[i]=='{')
                        {
                        token[i]='\0';
                        *ch='{';
                        return 1;
                        } 
                else if(token[i]=='}')
                        {
                        token[i]='\0';
                        *ch='}';
                        return 2;
                        }
                else if(token[i]==';') 
                        {
                        return 3;
                        }
                else if(strstr(token,"case")!=NULL) 
                        {
                        return 4;
                        }  
                else if(token[i]!=' ')
                        {
                        return 10;
                        }
                } 
        }
void spaces(char*token,int times)
        { 
        int i=0;  
        char spac[]={"    "};
        token[0]='\n'; 
        token[1]='\0';
        for(i=0;i<times;i++)
                {
                strcat(token,spac);
                }
        }
char *wordsep(char *token)
        {
        int i;
        int st,end;
        int flag=0,count=0;
        char temp[1000];  
        char dtemp[1000];  
        char *data=dtemp;
        char  *ptr=temp;
        int cflag=0;
        strcpy(dtemp,token); 
        for(i=0;i<strlen(data);i++)
                {   
                if(dtemp[i]!=' '&&flag==0)
                        {
                        st=i; 
                        break;
                        flag=1; 
                        }
                }
        strcpy(temp,token); 
        ptr[strlen(temp)-1]='\0'; 
        st-=1;
        ptr[st]='\0';
        ptr+=st+1;  
        return (char*)ptr;
        }
void midputc(char *data, char ch, int *cn) 
        {
        char tempc[1000];
        int i = *cn;
        char tempj[1000];
        char *stp = tempc;
        char *endp = tempj;
        strcpy(tempc, data);
        strcpy(tempj, data);
        i = *cn;
        stp[i] = '\0';
        i = *cn - 1;
        endp[i] = '\0';
        endp += i + 1;
        *cn += 1;
        sprintf(data, "%s%c%s", stp, ch, endp);
        } 
void rearrange(char *data) 
        { 
        int i, cn = 0,  j; 
        char tempc[1000]={'\0'}; 
        static int  brac = 0;
        static int flag = 0; 
        char  user[1000]={'\0'};
        const char pass[1000]={"{}\n"};
        char jeet[1000];  
        char *token=jeet;
        char *rest=tempc;  
        char small[1000];   
        char *smptr=small;
        char bracke[1000]={'\0'} ;
        char space[1000]; 
        int lp=0,sp=0;
        char ch=' ';  
        char strch[10000];
        int  col;
        flag=0;
        strcpy(tempc, data);
        token[0]='\0'; 
        token=wordsep(tempc);
        strcpy(small,token);
        col=check(small,&ch);
        strcpy(token,small);
        if(col==1)brac+=1;
        if(col)
                {
                 static int confus=0;
                 spaces(space,brac);
                 spaces(strch,brac);
                 if(col==1)
                        { 
                        sprintf(small,"%s%s%c%s",token,space,ch,space);
                        strcpy(data,small); 
                        }
                 else if(col==2)
                        {
                        int bck=0;
                        bck=brac-1; 
                        spaces(strch,bck);
                        sprintf(small,"%s%s%c%s",token,space,ch,strch);
                        strcpy(data,small);
                        }
                }
        if(col==2)
                {
                if(brac>0)
                brac-=1; 
                }

  //      strcpy(data,small); 
        } 
void print(char data[],int cl)
        {
        tk(cl);
        printf("%s",data); 
        tk(15);
        }
