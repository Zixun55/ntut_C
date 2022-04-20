#include<stdio.h>

int main(){
    int n,m,kid[200],ans=0,count=0;
    char space;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) kid[i] = 0;
    for (int i=0;i<m;i++){
        int s;
        scanf("%d%c",&s,&space);
        kid[s-1] = 1;
    }
    if (kid[n-1] == 0) count+=1;
    for (int i=0;i<n;i++){
        if (kid[i] == 0) count+=1;
        else if (kid[i] == 1){
            if (count>ans) ans = count;
            count = 0;
        }
    }
    printf("%d",ans);
    return 0;
}

// N 位小朋友手牽手圍成一個圓圈玩遊戲 (如下圖 N = 8), 分別為編號 1 ~ N。抽取 M 個編號 (M <= N), 求這 M 個編號以外的小朋友中, 手牽手相連最多的小朋友是幾位。例如下圖 M = 5, 分別為 1, 2, 5, 6, 8, 這五個編號以外的最大相連為 3, 4 兩位。

// https://imgur.com/a/aMuDGGM

// 輸入說明
// 第一行正整數 N M
// 第二行輸入 M 個小朋友編號

// 輸出說明
// M 個編號以外的最大相連個數

// Sample Input
// 8 5
// 5 1 6 2 8

// Sample Output
// 2

