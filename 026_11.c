#include <stdio.h>
typedef struct{
    int num[1000];
    int h, t;
}Queue;
int front(Queue q){
    return q.num[q.h];
}
void push(Queue *q, int n){
    q->num[q->t++] = n;
}
void pop(Queue *q){
    q->h++;
}
int isempty(Queue q){
    return q.t - q.h == 0;
}
Queue newQueue(){
    Queue q;
    q.h = 0;
    q.t = 0;
    return q;
}
int main(){
    int id[100], od[100], e[100][100], ot[100], tt[100];
    int run, k, n;
    Queue que = newQueue();
    scanf("%d", &run);
    while(run-- >  0){
        int ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d" ,&ot[i]);
            tt[i] = ot[i];
            scanf("%d", &k);
            od[i] = k;
            for(int j = 0; j < k; j++){
                scanf("%d", &e[i][j]);
                id[e[i][j]]++;
            }
        }
        for(int i = 1; i <= n; i++){
            if(id[i] == 0) push(&que, i);
        }
        while(isempty(que) == 0){
            int cur = front(que);
            for(int i = 0; i < od[cur]; i++){
                int node = e[cur][i];
                if(tt[cur] + ot[node] > tt[node]) tt[node] = tt[cur] + ot[node];
                id[node]--;
                if(id[node] == 0) push(&que, node);
            }
            if(od[cur] == 0 && tt[cur] > ans) ans = tt[cur];
            pop(&que);
        }
        printf("%d\n", ans);
    }
    return 0;
}