#include <stdio.h>
#define NEXT_hole_NUM 2

typedef struct hole_s{
    int id, gold;
    struct hole_s *nexthole[NEXT_hole_NUM];
} hole_t;

void dataInput(hole_t holes[], int n){
    int id, nexthole;

    for (int i = 0; i < n; i++){
        scanf("%d", &id);
        holes[id - 1].id = id;
        scanf("%d", &holes[id - 1].gold);
        for (int j = 0; j < NEXT_hole_NUM; j++){
            scanf("%d", &nexthole);
            holes[id - 1].nexthole[j] = nexthole ? &holes[nexthole - 1] : NULL;
        }
    }
}

int computeMaxGold(hole_t *hole, int isWalk){
    int max = 0, tmp;

    if (hole == NULL || (isWalk >> hole->id - 1) & 1) return 0;

    for (int i = 0; i < NEXT_hole_NUM; i++){
        tmp = computeMaxGold(hole->nexthole[i], isWalk + (1 << hole->id - 1));
        if (tmp > max) max = tmp;
    }

    return hole->gold + max;
}

void printPath(hole_t *hole, int path[], int index, int max, int isWalk){
    int isNull = 1;

    path[index++] = hole->id;
    for (int i = 0; i < NEXT_hole_NUM && isNull; i++) isNull = hole->nexthole[i] != NULL ? 0 : 1;
    if ((isNull && hole->gold == 0) || (isWalk >> hole->id - 1) & 1){
        if (max == 0){
            for (int i = 0; i < index; i++) printf("%d ", path[i]);
            printf("\n");
        }
    }
    else{
        max -= hole->gold;
        for (int i = 0; i < NEXT_hole_NUM; i++) printPath(hole->nexthole[i], path, index, max, isWalk + (1 << hole->id - 1));
    }
}

int main(){
    int n, k, max;

    scanf("%d %d%*c", &n, &k);
    hole_t holes[n];
    int path[n + 1];
    dataInput(holes, n);

    max = computeMaxGold(&holes[k - 1], 0);

    printPath(&holes[k - 1], path, 0, max, 0);
    printf("%d", max);

    return 0;
}

// 小明獲得一個尋寶祕笈和一隻鑰匙 A，依此找到第一個山洞 (編號 1)，發現裡面有三個寶箱 (X, Y, Z)，用鑰匙打開第一個寶箱 X，發現裝著一些數量的黃金 G1 和另一支鑰匙 B。鑰匙 B 只能選擇打開第二 (Y) 或第三個 (Z) 寶箱的其中一個。兩個寶箱裡面裝有第二、三個山洞的第一個寶箱鑰匙。小明只能利用鑰匙 B 開啟其中一個寶箱 (Y 或 Z) 往下一個山洞尋寶。每一個山洞都和第一個山洞一樣有三個寶箱，其中一個藏有某數量的黃金和一把鑰匙開啟其他寶箱往下一個山洞尋寶。下一個山洞可能是空的山洞或是已經走過的山洞，若是如此則尋寶之旅結束，如下圖所示。請寫一個程式找出可以獲得最多黃金的山洞編號順序。

// https://imgur.com/a/uZO4pAP


// 輸入說明：
// ------------------------------------------------------------------------
// 第一行是二個整數，代表山洞個數 N，以及第一個進入的山洞編號 K
// 之後 N 行，每一行有四個整數，分別是山洞編號、黃金數量、下一個可以前往的兩個山洞編號

// 輸出說明：
// ------------------------------------------------------------------------
// 從山洞編號 K 進入，獲得最多黃金的山洞編號順序 (若多條路徑排序輸出) 以及可獲得的黃金數量


// 範例一：
// ------------------------------------------------------------------------
// input：
// 5 1
// 1 6 2 4
// 2 5 3 4
// 3 7 2 5
// 4 4 2 5
// 5 0 0 0

// output：
// 1 4 2 3 2
// 1 4 2 3 5
// 22

