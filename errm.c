#include<stdio.h>
#include<conio.h>
#include<string.h>  
void back(char *);
void restart();
const char inputkey[]={" abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ123456789/*-+`~!@#$%^&*()_+{}|:\"<>?[];',./\\"};
int main()
        {
        FILE*fp;
        char arr[100000];
        char data[1000000];  
        static char filename[1000];
        char num[1000];
        static int flagc=1;
        int i=1,j=0;
        bk(0);
        clrscr();
        printf("Enter your filename and see magic :");
        if(flagc==1)
                {
                scanf("%s",filename); 
                }
        else clrscr(); 
        fp=fopen(filename,"r");
        if(fp==NULL)
                {
                printf("unable to open file %s",filename);
                return 1;  
                }
        data[0]='\0';
        num[0]='\0';
        while(fgets(arr,sizeof(arr),fp))
                { 
                char temp[10000];
                
                if(strchr(arr,'\342')!=NULL)
                        {
                        tk(9); 
                        sprintf(temp,"%d|%s",i,arr);   
                        strcat(num,temp);
                        printf("pass");
                        back(arr);                  
                        }
               
                else tk(15); 
                
                printf("%d |%s",i,arr); 
                sprintf(temp,"%s",arr);
                strcat(data,temp);
                
                i++;   
                }
       
        fclose(fp); 
        fp=fopen(filename,"w");
        if(fp==NULL)
                {
                printf("error");
                return 2;
                }
        fprintf(fp,data);
        fclose(fp); 
        fp=fopen("temp.txt","w");
        if(fp==NULL)
                {
                printf("error");
                return 2;
                }
        fprintf(fp,num); 
        fclose(fp); 
        if(flagc)
                {
                flagc=0;
                restart();
                }
        return 0;
        }

void back(char *arr)
        {
        
        char temp[10000];
        char *ptr=temp;
        int i,j,flag=0,c_flag=0; 
          
        for(i=0,j=0;i<=strlen(arr);i++)
                {
                if(strchr(arr,'\342')!=NULL)
                        {
                        tk(9);     
                        c_flag++;
                        if(c_flag==1)i+=3;
                        flag=1;
                        
                        }
                if(flag)
                        {
                        temp[j]=arr[i]; 
                        }
                else 
                        { 
                        if(strchr(inputkey,arr[i])!=NULL)
                                        {
                                        temp[j]=arr[i];
                                        }
                        else temp[j]=' ';
                        }
               j++; 
               }  
        
        strcpy(arr,temp);
        if(strchr(arr,'\342')!=NULL)
                        {
                        tk(9);                                                                 
                        }
        else tk(6); 
        }
void restart()
        {
        main(); 
        }
