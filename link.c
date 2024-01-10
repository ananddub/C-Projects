#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define tk textcolor
typedef struct node
        {
        int a;
        struct node *prev;
        struct node *next;
        } node;
void insert(node *);
void print(node *);
void frees(node *);
void main()
        {
        int i;
        node *head = (node *)malloc(sizeof(node));
         head->next=head;
        clrscr();
        for (i = 0; i < 10; i++)
                insert(head);
        clrscr();
        tk(15);
        print(head);
        getch();
        }
void insert(node *head)
        {
        static int i = 1;
        node *past = head;
        node *move = head;
        node *Nodes = (node *)malloc(sizeof(node));
        Nodes->a = i;
        while (move->next != head )
                {
                past = move;
                move = move->next;
                }
        Nodes->prev = past;
        Nodes->next = head;
        move->next = Nodes;
        head->prev = Nodes;
        i += 1;
        }
void frees(node *head)
        {
        node *prev = NULL;
        node *move = head;
        head->
        if (prev != NULL)
                {
                prev->next = NULL;
                free(move);
                }
        else if (head != NULL)
                {
                head = NULL;
                free(head);
                head = NULL;
                }
        }
void print(node *head)
        {
        node *move = head;
        while (1)
                {
                clrscr();
                printf("\nmove=%d", move->a);
                switch (getch())
                        {
                case 'B':
                        if (move->next != NULL)
                                {
                                move = move->next;
                                }
                        break;
                case 'A':
                        if (move->prev != NULL)
                                {
                                move = move->prev;
                                }
                        break;
                case '\n':
                        exit(0);
                        break;
                        }
                }
        }
