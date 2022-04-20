#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct  node
{
    char name[20];
    int age;
    int year;
    int month;
    int day;
    struct node *next;  
}node_t;
node_t *createNewNode(char names[],int ages,int years,int months,int days){
    node_t *newNode=malloc(sizeof(node_t));
    strcpy(newNode->name,names);
    newNode->age=ages;
    newNode->year=years;
    newNode->month=months;
    newNode->day=days;
    newNode->next=NULL;
    return newNode;
}
void dequeue(node_t **p,int type){
    node_t *current,*previous,*top;
    if((*p==NULL)){
        printf("The Queue is empty\n");
        return;
    }
    current=(*p)->next;
    top=*p;
    switch (type)
        {
            case 1:
            printf("%s\n",top->name);
            free(top);
            break;
        case 2:
            printf("%d\n",top->age);
            free(top);
            break;
        case 3:
            printf("%d_%d_%d\n",top->year,top->month,top->day);
            free(top);
            break;
        }
    *p=current;
}
void enqueue(node_t **p) {
    char names[20];
    int ages,years,months,days;
    scanf(" \"%[^'\"']\" %d %d %d %d%*c", names, &ages, &years, &months, &days);
    node_t *current;
    node_t *newNode = createNewNode(names,ages,years,months,days);
    if ( *p==NULL) {
        *p = newNode;
    }
    else {
        current = (*p);
    while (current->next!=NULL)
        current = current->next;
        current->next = newNode;
    }
}
int main(){
    node_t *data=NULL;
    int chose,sure=1;
    while(sure){
        int t;
        scanf(" %d",&t);
        switch (t)
        {
        case 1:
            enqueue(&data);
            break;
        
        case 2:
            scanf(" %d",&chose);
            dequeue(&data,chose);
            break;
        case 3:
            sure=0;
            break;
        }
    }
}