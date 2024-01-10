#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bk textbackground
#define tk textcolor
typedef struct node
{
        char data[1000];
        struct node *next;
        struct node *prev;
} node;
node *create(char *);
void maintain(char *);
void insert(node *, char *);
void print(node *, int, int);
void nodefree(node *);
void extract(node *, char *, char *);
void operation(node *);
void live(node *, node *);
void display(node *);
void srem(char *);
int main()
{
        clrscr();
        maintain("test.c");
        return 1;
}
void maintain(char *filename)
{
        FILE *fp;
        char data[1000];
        int i = 0;
        node *head = create("None");
        if ((fp = fopen(filename, "r")) == NULL)
        {
                printf("\nUnable to open file");
                return;
        }
        while (fgets(data, sizeof(data), fp) != NULL)
        {
                // printf("%s %d",data,i);
                // i++;
                srem(data);
                extract(head, data, data);
        }
        fclose(fp);
        display(head);
}
void extract(node *head, char *temp, char *ptr)
{
        static char *max;
        static int flag = 1;
        char *back=ptr-1;
        static char *last;
        const char num[]="1234567890";
        const char not [] = " `-=~!@#$%^&*()_+[]\;'./{}|:\" < > ? ";
        // const char *max = &temp[strlen(temp)];
        if (flag)
        {
                max = &temp[strlen(temp) - 1];
                flag = 0;
                last = ptr;
        }
        if (ptr > max)
                return;
        else
        {
                if (strchr(not, *ptr) != NULL)
                {
                        char ch[3];
                        sprintf(ch, "%c", *ptr);
                        *ptr = '\0';
                        if (strlen(last) > 0)
                                insert(head, last);
                        insert(head, ch);
                        last = ptr + 1;
                }
                ptr++;
                extract(head, temp, ptr);
        }
        flag = 1;
}
void live(node *move, node *cur)
{
        int len;
        printf("\t\t\t\t\t\t");
        if (move == cur)
                printf("<-");
        len = printf("%s", move->data);
        if (move == cur)
                printf("->");
        printf("\n");
        bk(0);
        move = move->next;
        if (move == NULL)
                return;
        live(move, cur);
}
void display(node *head)
{
        static node *move;
        static int flag = 1;
        clrscr();
        if (flag)
        {
                move = head;
                flag = 0;
        }
        live(head, move);
        switch (getch())
        {
        case 'A':
                if (move->prev != NULL)
                        move = move->prev;
                break;
        case 'B':
                if (move->next != NULL)
                        move = move->next;
                break;
        }
        display(head);
        flag = 1;
}
void insert(node *head, char *data)
{
        node *move = head;
        if (move->next != NULL)
        {
                move = move->next;
                insert(move, data);
        }
        else
        {
                node *Node = (node *)malloc(sizeof(node));
                move->next = Node;
                Node->next = NULL;
                Node->prev = move;
                strcpy(Node->data, data);
        }
}
node *create(char *data)
{
        node *head = (node *)malloc(sizeof(node));
        head->next = NULL;
        head->prev = NULL;
        strcpy(head->data, data);
        return (node *)head;
}
void srem(char *token)
{
        char *rev = token;
        char *lm = token;
        char not[]=" \n";
        char temp[2000];
        int i=0;
        lm = &token[strlen(token)-1];
        // printf("%s",token);
        for (; (strchr(not,*lm)!=NULL || *lm==13)&& lm >=token; lm--)
        {
                i++;
                // printf("%d",*lm);
                *lm = '\0';
        }
        // printf("{%d}",*lm);
        for (; (*rev == ' ' || *rev == '\n'); rev++)
                ;
        sprintf(temp, "%s", rev);
        strcpy(token, rev);
        printf("len=%d|||%s\n",strlen(token), token);
}
