#include<stdio.h>
#include<uconio.h>
#include<string.h>
int kbhit();
char getch();
void start();
void end();
void print();
void outp(); 
void keycheck(int);
int key();
char ndisp();
int nkey(char);
int bks(); 
int bin(int);
int del();
int skey(char);  
#define data d[fn]._data
#define out d[fn]._output
#define keyword d[fn]._keyword
#define cn d[fn]._cn  
#define clipboard d[fn]._clipboard  
#define history d[fn]._history 
struct __data  
        {
        char _data[1000];
        char _output[100000];
        char _keyword[100000];
        char _history[100][100000];
        char _clipboard[1000];
        int  _cn;
        };     
struct __data d[100];
int fn=0; 
int hfn=0,lhfn=0;
const char inputkey[]={" abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNOPQRSTUVWXYZ123456789/*-+`~!@#$%^&*()_+{}|:\"<>?[];',.//"};
int main()
        {  
        FILE*fp;     
        fp=popen("ls -a /usr/bin","r");
        keyword[0]='\0';
        while(fgets(out,sizeof(out),fp)!=NULL)
                {
                strcat(keyword,out);  
                }  
        strcat(keyword,"cd\n");  
        strcat(keyword,"exit");   
        pclose(fp);
        start();
        return 1;
        }
void start()
        {  
        clrscr(); 
        data[0]='\0';
        cn=0;  

        print(); 
        while(1)
                {
                if(kbhit())
                        {
                        key();
                        print();
                        }
                }
        }

int bin(int gt)
        { 
        char tdata[10000];
        char tkey[100000];
        char *drest=tdata;
        char *dtoken;
        char *krest=tkey;
        char *ktoken;
        int flag=0;
        tdata[0]='\0'; 
        strcpy(tdata,data);
        strcpy(tkey,keyword);
        while((dtoken=strsep(&drest," "))!=NULL)
                {  
                while((ktoken=strsep(&krest,"\n"))!=NULL)
                        {  
                        if(strcmp(ktoken,dtoken)==0)flag=1;
                        } 
                if(flag==1) 
                        {
                        tk(BLUE);
                        flag++;
                        }
                else if(flag>1)
                        {
                        tk(CYAN);
                        }
                else 
                        {
                        tk(RED);        
                        }
                printf("%s ",dtoken);  
                }         
        return 1; 
        }
void print()
        {
        int len=strlen(data),i;
        int bk1=0,flag=0;
        tk(WHITE);   
        printf("\r");
        printf("Terminal>");
        tk(15);    
        for(i=0;i<=len;i++)
                {
                if(cn==i)flag=1;
                if(flag==1)bk1++;
               // keycheck(i); 
                } 
        bin(i);  
            
        printf("   ");  
        bk1+=3;  
        for(i=0;i<bk1;i++)
                {
                printf("\b"); 
                } 
       
        }
void outp()
        {
        FILE*fp;
        strcpy(history[lhfn],data);
        lhfn++;
        hfn++;
        if(strstr(data,"ls")!=NULL)strcat(data," -l"); 
        fp=popen(data,"r"); 
        out[0]='\n';
        while(fgets(out,sizeof(out),fp)!=NULL)
                {
                if(out[0]=='d')tk(WHITE);  
                else if(strstr(out,"rwxr-xr-x")!=NULL)tk(GREEN);
                else if(strchr(out,'.')!=NULL)tk(YELLOW);  
               

                printf("%s",out);
                } 
        pclose(fp);
        data[0]='\0';
        cn=0; 
        system(data);
        }
int key() 
        {
        char ch;
        ch=getch(); 
        if(strchr(inputkey,ch)!=NULL)
                {
                nkey(ch);
                }
        else
                {
                 skey(ch);
                }
        }
int skey(char ch)
        {
        int len=strlen(data);
        while(1)
                {
                if(kbhit())
                        {
                        ch=getch();
                        continue;
                        }
                break;
                } 
        switch(ch)
                {
                case 'A':
                        int i,len;
                        len=strlen(data);
                        if(hfn>0)
                                hfn-=1;
                        strcpy(data,history[hfn]);
                        cn=strlen(data);
                        i=cn;
                        for(i=len;i>=cn;i--)
                                {
                                printf("\b");
                                }
                        for(i=cn;i<=len;i++)
                                {
                                printf(" ");
                                }
                        break; 
                case 'B':
                        
                        len=strlen(data);
                        if(hfn<lhfn)
                                hfn+=1;
                        strcpy(data,history[hfn]); 
                        cn=strlen(data); 
                        i=cn; 
                        for(i=len;i>=cn;i--)
                                {
                                printf("\b");
                                }
                        for(i=cn;i<=len;i++)
                                {
                                printf(" ");
                                } 
                        break;
                case 'C':
                        if(cn<len)cn++;
                        break;
                case 'D':
                        if(cn>0)cn--;
                        break;
                case 127:
                        if(cn>0)
                                bks();
                        break;
                case '~':
                        del();
                        break;
                case '\n':
                        printf("\n"); 
                        outp();
                        break; 
                
                }
        }
int del()
        {
        int len;
        len=strlen(data);
        cn++;
        if(cn<len)
                
                bks();
        else cn--; 
        }
int bks()
        {
        char temp[1000];
        int i,j,len;
        len=strlen(data);
        j=cn;    
        temp[0]='\0';
        for(i=0;i<len;i++)
                {
                temp[i]=data[j];
                j++; 
                 } 
        temp[i]='\0';
        cn--;
        len=strlen(temp);        
        j=cn;    
        for(i=0;i<len;i++) 
                { 
                data[j]=temp[i];    
                j++;
                }
        data[j]='\0'; 
          
        }
int nkey(char ch)
        {
        char temp[1000];
        int i,j,len;
        len=strlen(data);
        j=cn;  
        temp[0]='\0';
        for(i=0;i<len;i++)
                {
                temp[i]=data[j];
                j++; 
                 } 
        temp[i]='\0';
        data[cn]=ch; 
        len=strlen(temp);       
        cn++; 
        j=cn;    
        for(i=0;i<len;i++) 
                { 
                data[j]=temp[i];    
                j++;
                }
        data[j]='\0'; 
        }
 
int kbhit() 
	{
    	struct termios old, new;
    	int ch;
    	int oldf;
    	tcgetattr(STDIN_FILENO, &old);
    	new = old;
    	new.c_lflag &= ~(ICANON | ECHO);
    	tcsetattr(STDIN_FILENO, TCSANOW, &new);
    	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF) {
		ungetc(ch, stdin);
		return 1;
		}

    	return 0;
	}
char getch() 
	{
	char ch;
	struct termios old, new;
	tcgetattr(STDIN_FILENO, &old);               // Get the current terminal settings
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);             // Disable canonical mode and echoing
	tcsetattr(STDIN_FILENO, TCSANOW, &new);      // Apply the new terminal settings
	ch = getchar();                              // Read a character from the keyboard
    	tcsetattr(STDIN_FILENO, TCSANOW, &old);      // Restore the original terminal settings
    	return ch;
	}
 
