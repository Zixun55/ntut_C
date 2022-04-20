#include<stdio.h>
int main(void) {
    int base1 = 0,base2 = 0,base3 = 0,out = 0,i;
    for ( i = 1; i <= 5; i++) {
        char input;
        scanf(" %c",&input);
        if (input == 'O') out = out + 1;
        else if (input == '1'){
            if (base2 == 1) base3 = 1;
            if (base2 == 0) base3 = 0;
            if (base1 == 1) base2 = 1;
            if (base1 == 0) base2 = 0;
            base1 = 1;
        }else if (input == '2'){
            if (base1 == 1) base3 = 1;
            if (base1 == 0) base3 = 0;
            base1 = 0;
            base2 = 1;
        }else if (input == '3'){
            base1 = 0;
            base2 = 0;
            base3 = 1;
        }else if (input == 'H'){
            base1 = 0;
            base2 = 0;
            base3 = 0;
        }if (out == 3) {
            base1 = 0;
            base2 = 0;
            base3 = 0;
            out = 0;
        }
    }
    printf("%d\n",base1);
    printf("%d\n",base2);
    printf("%d",base3);
}

// 002. 跑壘問題

// 輸入棒球隊球員打擊結果，計算出隊得分。假設球員打擊情況：
// 安打：以1, 2, 3 和 H代表一、二、三和全(四)壘打。
// 出局：以 O表示 (OUT)。
// 簡化版的規則如下：
// 球場 上有四個壘包， 稱為本壘、一、二和三壘。
// 本壘握球棒打的稱「擊球員」 ，在另外三個壘包的稱為「跑員」。
// 當擊球員打擊「安打」時， 擊球員與跑壘員可移動；「出局」時，跑壘員不動，擊球員離場換下一位。
// 比賽開始由第 1位打擊，接著2, 3, 4, 5位球員。
// 打出 K 壘打時，場上球員(擊球員和跑壘員)會前進 K個壘包。本壘到一壘，接著二、三壘，最後回到本壘。回到本壘可得 1分。
// 每達到三個出局數時，壘包清空(跑壘員都得離開)，重新開始。
// 輸入5位打者打擊資料，輸出最後一、二、三壘狀況，有人為1，沒人為0。

// ---------------
// Input
// 1
// 1
// O
// O
// 1

// Output
// 1
// 1
// 1

// ---------------
// Input
// 1
// H
// O
// 3
// 1

// Output
// 1
// 0
// 0
