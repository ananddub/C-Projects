#include <stdio.h>
#include <conio.h>

typedef struct Node
        {
        char ch;
        struct Node *next;
        }Node;
void alloc(Node*);

void salloc(Node*,int);
void print(Node*)
void st();;
void main()
        {
        //allocs();
        //printf("helloo world ");
        }

void print(Node*start)
        {
        move=&*start->next;
        printf("\nadd:%x",move);
        while(move.next!=NULL)
                {
                printf("\npirnting data :%c",move->ch);
                move=&*move.next;
                }
        }
void alloc(Node*prev)
        {
        static char ch='a';
        Node *node = (Node *)calloc(1, sizeof(Node));
        prev->next=&*node;
        node->ch=ch;
        ch++;
        }
