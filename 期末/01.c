#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int value;
    struct Node *next;
}LinkedList;

LinkedList * Insert(LinkedList *head,int c){
    LinkedList *temp;
    LinkedList *current = NULL;
    temp = (LinkedList *) malloc(sizeof(LinkedList));
    temp->value = c;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
        return head;
    }
    else{
        for (current = head;current != NULL;current = current->next){
            if (current->next == NULL){
                current->next = temp;
                return head;
            }
        }
    }
    return head;
}

LinkedList * Input(LinkedList *p){
    int c[200],n=0;
    char str[200];
    scanf(" %[^\n]",str);
    char *s = strtok(str," ");
    char *end;
    while(s != NULL){
        c[n++] = (int)strtol(s,&end,10);
        s = strtok(NULL," ");
    }
    for (int i=n-1;i>=0;i--){
        p = Insert(p,c[i]);
    }
    return p;
}

LinkedList * add(LinkedList *p0,LinkedList *p1){
    LinkedList *ans = NULL;
    LinkedList *current = NULL;
    LinkedList *current1 = NULL;
    int n_p1 = 0,n_p0 = 0;
    for (current = p0;current != NULL;current = current->next)n_p0+=1;
    for (current = p1;current != NULL;current = current->next)n_p1+=1;
    if (n_p0<n_p1) n_p0 = n_p1;
    current = p0;
    current1 = p1;
    for (int i=0;i<n_p0;i++){
        if (current != NULL && current1 != NULL){
            ans = Insert(ans,(current->value)+(current1->value));
            current = current->next;
            current1 = current1->next;
        }
        else if(current1==NULL && current!=NULL){
            ans = Insert(ans,(current->value));
            current = current->next;
        }
        else if(current==NULL && current1!=NULL){
            ans = Insert(ans,(current1->value));
            current1 = current1->next;
        }
    }
    return ans;
}

LinkedList * sub(LinkedList *p0,LinkedList *p1){
    LinkedList *ans = NULL;
    LinkedList *current = NULL;
    LinkedList *current1 = NULL;
    int n_p1 = 0,n_p0 = 0;
    for (current = p0;current != NULL;current = current->next)n_p0+=1;
    for (current = p1;current != NULL;current = current->next)n_p1+=1;
    if (n_p0<n_p1) n_p0 = n_p1;
    current = p0;
    current1 = p1;
    for (int i=0;i<n_p0;i++){
        if (current != NULL && current1 != NULL){
            ans = Insert(ans,(current->value)-(current1->value));
            current = current->next;
            current1 = current1->next;
        }
        else if(current==NULL && current1!=NULL){
            ans = Insert(ans,(0-(current1->value)));
            current1 = current1->next;
        }
        else if(current1==NULL && current!=NULL){
            ans = Insert(ans,(current->value));
            current = current->next;
        }
    }
    return ans;
}

LinkedList * mux(LinkedList *p0,LinkedList *p1){
    LinkedList *ans = NULL;
    LinkedList *current = NULL;
    LinkedList *current1 = NULL;
    int n_p1 = 0,n_p0 = 0,n,store[200];
    for (int i=0;i<200;i++) store[i] = 0;
    for (current = p0;current != NULL;current = current->next)n_p0+=1;
    for (current = p1;current != NULL;current = current->next)n_p1+=1;
    n = n_p0+n_p1-2;
    current = p0;
    for (int i=0;i<n_p0;i++){
        current1 = p1;
        for (int j=0;j<n_p1;j++){
            store[i+j] += (current1->value) * (current->value);
            current1 = current1->next;
        }
        current = current->next;
    }
    for (int i=0;i<=n;i++) ans = Insert(ans,store[i]);
    return ans;
}

void print(LinkedList *head){
    LinkedList *current = head;
    int c[200],k=0,h,even=0;
    if(current == NULL) return; 
    while (current != NULL){
        if (even%2 == 0){
            c[k] = current->value;
            k+=1;
        }
        even+=1;
        current = current->next;
    }
    h = k-1;
    for (int i=k-1;i>=0;i--){
        if (i == h && c[i] == 0){
            if (h == 0){
                printf("0");
                break;
            }
            h-=1;
            continue;
        }
        printf("%d ",c[i]);
    }
}

void value_add(LinkedList *head){
    LinkedList *current = head;
    int c[200],k=0,h,total=0;
    if(current == NULL) return; 
    while (current != NULL){
        c[k] = current->value;
        k+=1;
        current = current->next;
    }
    h = k-1;
    for (int i=k-1;i>=0;i--) total+=c[i];
    printf("%d ",total);
}

int main(){
    LinkedList *p0 = NULL;
    LinkedList *p1 = NULL;
    LinkedList *ans=NULL;
    LinkedList *ans1=NULL;
    LinkedList *ans2=NULL;
    p0 = Input(p0);
    p1 = Input(p1);
    ans = add(p0,p1);
    print(ans);
    printf("\n");
    value_add(ans);
    printf("\n");
    ans1 = sub(p0,p1);
    print(ans1);
    printf("\n");
    value_add(ans1);
    printf("\n");
    ans2 = mux(p0,p1);
    print(ans2);
    printf("\n");
    value_add(ans2);
    printf("\n");
    return 0;
}

// ***本題務必使用 Link List***

// 輸入兩個多項式，輸出相加、相減、相乘的結果。例如:

// 2x^4 + 3x^3 + x -1
// x^5 - x^3 + 4x^2 - 3x +2
// 結果：
// x^5 + 2x^4 + 2x^3 + 4x^2 - 2x + 1
// -x^5 + 2x^4 + 4x^3 - 4x^2 + 4x - 3
// 2x^9 + 3x^8 - 2x^7 + 6x^6 + 5x^5 - 6x^4 + 11x^3 - 7x^2 + 5x - 2

// 輸入說明
// 輸入兩筆資料，分別代表兩個多項數。
// 每一筆輸入 n 個整數，第一個代表 n-1次方的係數，第 n 個代表 0 次方係數。

// 輸出說明
// 輸出計算後多項式的偶次方(ex: 2x^8 or 5x^2or常數項)係數，由最高次方到低次方排列(係數為零也需印出)，並輸出所有係數和(不分奇偶次方)。
// Ex:
// 相加結果為： x^5 + 2x^4 + 2x^3 + 4x^2 - 2x + 1
// 故需輸出：
// 2 4 1
// 8
// (2 4 1為2x^4 + 4x^2 + 1偶次方係數，
// 8為所有係數總和(x^5 + 2x^4 + 2x^3 + 4x^2 - 2x + 1):1+2+2+4-2+1 = 8

// Sample Input
// 2 3 0 1 -1
// 1 0 -1 4 -3 2

// Sample Output
// 2 4 1
// 8
// 2 -4 -3
// 2
// 3 6 -6 -7 -2
// 15

