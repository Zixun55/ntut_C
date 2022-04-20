#include <stdio.h>
int main(void){
    int x[4],i_x,time=0;
    scanf("%d",&i_x);
    x[0]=i_x/1000;
    x[1]=i_x/100%10;
    x[2]=i_x/10%10;
    x[3]=i_x%10;
    while(1){
        int y[4],i_y,A=0,B=0;
        scanf("%d",&i_y);
        y[0]=i_y/1000;
        y[1]=i_y/100%10;
        y[2]=i_y/10%10;
        y[3]=i_y%10;

        if ((x[0] == y[0]) && x[1] == y[1] && x[2] == y[2] && x[3] == y[3]) {
            printf("win");
            break;
        }
        for (int i=0;i<4;i++){
            if (x[i] == y[i]) A+=1;
            else{
                for (int j=0;j<4;j++){
                    if (j != i){
                        if (x[i] == y[j]) B+=1;
                    }
                }
            }
        }
        printf("%dA%dB\n",A,B);

        time+=1;
        if (time == 6) break;
    }
}

// 014 1A2B

// 小明和小萱在玩猜數字遊戲，
// 由小明先輸入四個數字為謎底，
// 小萱輸入想要猜的四個數字。
// 若猜中數字則顯示win
// 若猜錯則顯示XAYB（X表示位置和數字皆正確的個數，而Y表示數字正確而位置不對的個數）
// ＊＊＊最多猜六次＊＊＊


// sample input1:
// 1234
// 5678
// 1234

// sample output1:
// 0A0B
// win


// ------------------

// sample input2:
// 0487
// 0234
// 1498
// 2378
// 3294
// 3681
// 5412

// sample output2:
// 1A1B
// 1A1B
// 0A2B
// 0A1B
// 1A0B
// 1A0B

