#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
	 
typedef struct Node 
{ 
  int value;    // 係數 
  int power;    // 次方 
  struct Node *next; 
} LinkedList; 
	 
LinkedList * InputPolynomial(LinkedList *); 
	 
LinkedList * InsertNode(LinkedList *, int, int); 
LinkedList * Add(LinkedList *, LinkedList *); 
LinkedList * Mul(LinkedList *, LinkedList *); 
void printPolynomial(LinkedList *);  // 印出多項式 
void FreeNode(LinkedList *);  // 釋放多項式所佔的記憶體空間 
	 
int main() { 
	int choice, r = 1; 
	LinkedList *p0 = NULL; 
	LinkedList *p1 = NULL; 
	LinkedList *ans = NULL; 
	 
	  /************* 輸入第一個多項式 *************/ 
	printf("Please Input the  First Polynomial (0 0 : 結束)\n"); 
	p0 = InputPolynomial(p0); 
	printf("1.-> "); 
	printPolynomial(p0); 
	   
	  /************* 輸入第二個多項式 *************/ 
	printf("Please Input the Second Polynomial (0 0 : 結束)\n"); 
	p1 = InputPolynomial(p1);   
	printf("2.-> "); 
	printPolynomial(p1); 
	 
	while(r){    // r=1 繼續執行, r=0 跳出 
	    printf("[Menu]\n"); 
	    printf("=====================================\n"); 
	    printf(" 1. Add\n"); 
	    printf(" 0. Exit\n"); 
	    printf("=====================================\n"); 
	    printf("Choice = "); 
	    scanf("%d", &choice); 
	    printf("\n"); 
	 
	    switch(choice) { 
	      case 0:                       // Exit 
	        FreeNode(p0); 
	        FreeNode(p1); 
	        r=0; 
	        break; 
	      case 1:                       // 加法 
	        ans = Add(p0, p1);          // 將 p0, p1 兩個多項式傳入, 並用 ans 指標取得新多項式的起始位置 
	        printf("1. ");              // 列印第一個多項式資料 
	        printPolynomial(p0); 
	        printf("2. ");              // 列印第二個多項式資料 
	        printPolynomial(p1); 
	        printf("-> Answer is "); 
	        printPolynomial(ans);       // 列印答案 
	        FreeNode(ans);              // 釋放 ans 的記憶體空間 
	        break; 
	     
	       
	      default:  
        break; 
	    } 
	    printf("\n"); 
	  } 
	  return 0; 
} 
	 
	LinkedList * InputPolynomial(LinkedList *p)   // 輸入多項式資料 
	{ 
	  int c, power;   // c: 係數, power: 次方 
 
    while(1) { 
	    printf("  係數 and 次方 = "); 
        scanf("%d %d", &c, &power); 
	    if(c==0 && power==0) break; 
	    p = InsertNode(p, c, power); 
	  } 
	  printf("\n"); 
	  return p; 
	} 
	// LinkedList * InputPolynomiall(LinkedList *pp)   // 輸入多項式資料 
	// { 
	//   int  c,power;   // c: 係數, power: 次方 
	 
	//   while(1) { 
    // printf("  係數 and 次方 = "); 
	//     scanf("%d %d", &c, &power); 
	//     if(c==0 && power==0) break; 
    // pp = InsertNode(pp, c, power); 
	//   } 
	//   printf("\n"); 
	//   return pp; 
	// } 
	 
	LinkedList * Add(LinkedList *p0, LinkedList *p1)  // 加法 
	{ 
	  LinkedList *ans = NULL; 
	  LinkedList *current = NULL; 
	 
	  /******* 先放入第一個多項式資料 *******/ 
	  for(current = p0; current != NULL; current = current->next) 
	    ans = InsertNode(ans, current->value, current->power); 
	   
	  /******* 再放入第二個多項式資料 *******/ 
	  for(current = p1; current != NULL; current = current->next) 
	    ans = InsertNode(ans, current->value, current->power); 
	   
	  return ans; 
	} 
	 
	 
	 
	 
	LinkedList * InsertNode(LinkedList *head, int c, int power) 
	{ 
	  int result;     // 儲存兩個多項式相加的結果 
	 
	  LinkedList *temp; 
	  LinkedList *t = NULL; 
	  LinkedList *current = NULL; 
	  LinkedList *papa = NULL; 
	 
	  temp = (LinkedList *) malloc(sizeof(LinkedList)); 
	  temp->value = c; 
	  temp->power = power; 
	  temp->next = NULL; 
	 
	  if(head == NULL) { 
	    head = temp; 
	    return head; 
	  } else if(temp->power > head->power) { 
	    temp->next = head; 
	    head = temp; 
	    return head; 
	  } else { 
	    for(current = head; current != NULL; current = current->next) { 
	      if((current->next != NULL) && (current->power > temp->power) && (current->next->power < temp->power)) { 
	        t = current->next; 
	        current->next = temp; 
	        temp->next = t; 
	        return head; 
	      } else if(current->power == temp->power) { 
	        if((result = (current->value + temp->value)) != 0) {           
	          current->value = result; 
	          free(temp); 
          return head; 
	        } else if(result == 0) {       
	          
	            /*** 刪除節點值為 0 的項次***/ 
	            if(current == head)  
	              head = head->next;               
	            else if(current->next != NULL) 
	              papa->next = current->next; 
	            else papa->next = NULL;            
	            free(current);  
	            return head;  
	        } 
	      } else { 
	        if(current->next == NULL) { 
	          current->next = temp; 
	          return head; 
	          } 
	      } 
	      papa = current; 
	    } 
	  } 
	  return head; 
	} 
	 
	void FreeNode(LinkedList *head)   // 釋放記憶體空間 
	{ 
	  LinkedList *current = head; 
	  LinkedList *papa = NULL; 
	 
	  if(current == NULL) return; 
	 
	  while(current != NULL) { 
	    papa = current->next; 
	    free(current);    
	    current = papa; 
	  }   
	} 
	 
void printPolynomial(LinkedList *head)    // 列印多項式 
{ 
	LinkedList *current = head; 
	 
	if(current == NULL) { 
	    printf("NULL !\n\n"); 
	    return; 
	} 
	 
	while(current != NULL) { 
	    printf("%dx^%d", current->value, current->power); 
	    if((current->next != NULL) && (current->next->value >= 0)) printf(" + "); 
	    current = current->next; 
	} 
	 
  printf("\n\n"); 
} 