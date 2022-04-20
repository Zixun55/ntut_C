#include<stdio.h>
int print(int i){
    for (int j=0;j<i;j++) printf("*");
}
int print2(int i){
    for (int j=0;j<i;j++) printf(".");
}
int main(void){
    int type;
    int line;
    scanf("%d",&type);
    scanf("%d",&line);
    if (type == 1){
        for (int i=1;i<line/2+2;i++){
            print(i);
            printf("\n");
        }
        for (int i=line/2;i>0;i--){
            print(i);
            printf("\n");
        }
    }
    else if (type == 2){
        for (int i=line/2;i>0;i--){
            print2(i);
            print(line/2+1-i);
            printf("\n");
        }
        print(line/2+1);
        printf("\n");
        for (int i=1;i<line/2+1;i++){
            print2(i);
            print(line/2+1-i);
            printf("\n");
        }
    }
    else if (type == 3){
        if (line !=1){
            for (int i=1;i<=line/2;i++){
                print2(line/2+1-i);
                print(i*2-1);
                printf("\n");
            }
            print(line);
            printf("\n");
            for (int i=line/2;i>0;i--){
                print2(line/2+1-i);
                print(i*2-1);
                printf("\n");
            }
        }
        else printf("*");
    }
}

// 008
// 請使用 while loop或for loop
// 第一個輸入意義為選擇三種圖形:
// 1 三角形方尖方面向右邊
// 2 三角形方尖方面向左邊
// 3 菱形
// 第二個輸入意義為畫幾行
// (奇數，範圍為 3,5,7,9,....,21)
// input
// 1 (第一種圖形，三角形尖方面向右邊)
// 9 (共 9 行)
// --------------------------
// output
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
// ---------------------------
// input
// 2 (第二種圖形，三角形尖方面向左邊)
// 5 (共 5 行)
// ---------------------------
// output
// ..*
// .**
// ***
// .**
// ..*
// --------------------------
// input
// 3 (第三種圖形: 菱形 )
// 3 (共 3 行數)

// 輸出
// .*
// ***
// .*


