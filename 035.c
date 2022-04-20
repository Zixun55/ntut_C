#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node { 
    char name[50];
    int age;
    int year;
    int month;
    int day;
    struct Node *next; 
} LinkedList;

LinkedList * InsertNode(LinkedList *head, char name[],int age,int year,int month,int day){ 
	LinkedList *temp; 
	LinkedList *current = NULL; 	 
	temp = (LinkedList *) malloc(sizeof(LinkedList)); 
    strcpy(temp->name, name); 
    temp->age = age; 
    temp->year = year; 
    temp->month = month; 
    temp->day = day; 
	temp->next = NULL; 
	if(head == NULL) { 
	    head = temp; 
	    return head; 
	} 
    else{
	    for(current = head; current != NULL; current = current->next) { 
            if(current->next == NULL) { 
                current->next = temp; 
                return head; 
            } 
	    } 
    }
	return head; 
} 

LinkedList * pop(LinkedList *head){
    LinkedList *current=head;
    if(head == NULL) return NULL;
    if(head->next == NULL){
        free(head);
        return NULL;
    }
    while(current != NULL){
        if(current->next != NULL && current->next->next == NULL){
            free(current->next);
            current->next = NULL; 
        }else{
            current = current->next;
        }
    }
    return head;
}


int main(){
    LinkedList *data = NULL; 
    int n=0,age,year,month,day,t,type;
    char name[500];
    while (scanf("%d", &t) && t != 3){
        switch (t){
        case 1:
            scanf(" \"%[^'\"']\" %d %d %d %d%*c", name, &age, &year, &month, &day);
            data = InsertNode(data,name,age,year,month,day);
            break;

        case 2:
            scanf("%d%*c",&type);
            if (type == 1){
                
                LinkedList *current = data; 
                if(current == NULL) printf("The Stack is empty\n"); 
                else{
                    while (current->next != NULL) current = current->next;
                    printf("%s\n",current->name);
                    
                }
            }
            else if (type == 2){
                LinkedList *current = data; 
                if(current == NULL) printf("The Stack is empty\n");
                else{
                    while (current->next != NULL) current = current->next;
                    printf("%d\n",current->age);
                } 
            }
            else if (type == 3){
                LinkedList *current = data; 
                if(current == NULL) printf("The Stack is empty\n");
                else{
                    while (current->next != NULL) current = current->next;
                    printf("%d_%d_%d\n",current->year,current->month,current->day);
                }
            }
            data = pop(data);
            break;
        }
    }
    return 0;
}

// ***此題務必使用 Link List***

// 實作stack
// 在一端進行後進先出（LIFO, Last In First Out）的原理運作。
// 兩種基本操作：push 和 pop
// push：將數據放入堆疊的頂端（串列形式），堆疊頂端top指標加一。
// pop：將頂端數據資料輸出（回傳），堆疊頂端top指標減一。

// 每一次push和pop的一筆資料都包含姓名、年齡、生日(年、月、日)

// 輸入說明:
// 1 代表 push，再依序輸入姓名、年齡、生日(年、月、日)，參數之間以空白相隔
// 2 代表 pop，再輸入一個數字，進行不同的操作，操作數字如下:
// 1:印出該次pop的資料中的姓名
// 2:印出該次pop的資料中的年齡
// 3:印出該次pop的資料中的生日(年、月、日之間以底線連結)
// 若stack中為空則印出 The Stack is empty\n
// 3 結束程式。

// Sample Input

// 1 "Marry Hu" 19 1989 7 16
// 1 "Tom Chen" 22 1996 10 19
// 2 1
// 1 "Billy Wu" 15 2005 3 18
// 2 3
// 2 2
// 1 "Lucas Su" 24 1993 5 21
// 2 3
// 2 1
// 3

// Sample Output

// Tom Chen
// 2005_3_18
// 19
// 1993_5_21
// The Stack is empty

