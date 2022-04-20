#include<stdio.h>
int main(void){
    int id1;
    int h1;
    int id2;
    int h2;
    int id3;
    int h3;
    int t[5][9] = {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
    scanf("%d",&id1);
    scanf("%d",&h1);
    int con[3];
    for (int i=0;i<h1;i++){
        int c;
        scanf("%d",&c);
        int a = c/10 - 1;
        int b = c%10 - 1;
        t[a][b] = id1;
    }

    scanf("%d",&id2);
    scanf("%d",&h2);
    for (int i=0;i<h2;i++){
        int c;
        scanf("%d",&c);
        int a = c/10 - 1;
        int b = c%10 - 1;
        if (t[a][b] != 0){
            con[0] = t[a][b];
            con[1] = id2;
            con[2] = c;
        }
        else t[a][b] = id2;
    }

    scanf("%d",&id3);
    scanf("%d",&h3);
    for (int i=0;i<h3;i++){
        int c;
        scanf("%d",&c);
        int a = c/10 - 1;
        int b = c%10 - 1;
        if (t[a][b] != 0){
            con[0] = t[a][b];
            con[1] = id3;
            con[2] = c;
        }
        else t[a][b] = id3;
    }
    printf("%d and %d conflict on %d",con[0],con[1],con[2]);
}

// 005
// 檢查三門課程是否衝堂，
// 依序輸入課程編號(數字)、
// 上課小時數(1-3小時)、
// 上課時間(星期1-5, 第1-9節)
// 輸入說明
// 1001 (第一門課課程編號)
// 3 (3小時)
// 11 (星期1 第1節課)
// 59 (星期5 第9節課)
// 25 (星期2 第5節課)
// 2020 (第二門課課程編號)
// 2
// 25
// 16
// 2030 (第三門課課程編號)
// …

// 輸出說明 (兩課程編號衝突在哪幾節)
// 1001 and 2020 conflict on 25

// Sample Input：
// 1001
// 3
// 11
// 12
// 13
// 1002
// 3
// 21
// 22
// 23
// 1003
// 3
// 31
// 32
// 13
// Sample Output：
// 1001 and 1003 conflict on 13

// Sample Input：
// 1001
// 1
// 11
// 1002
// 3
// 21
// 22
// 11
// 1003
// 3
// 31
// 32
// 33
// Sample Output：
// 1001 and 1002 conflict on 11


