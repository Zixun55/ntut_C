#include<stdio.h>
float check(char x,float y){
    if (x == 'A') y = 1;
    if (x == '2') y = 2;
    if (x == '3') y = 3;
    if (x == '4') y = 4;
    if (x == '5') y = 5;
    if (x == '6') y = 6;
    if (x == '7') y = 7;
    if (x == '8') y = 8;
    if (x == '9') y = 9;
    if (x == '1') {
        y = 10;
        char l;         //處理0
        scanf(" %c",&l);
    }
    if (x == 'J' || x == 'Q' || x == 'K') y = 0.5;
    return y;
}
int main(void) {
    char a,b,c,d,e,f;
    float c1,c2,c3,c4,c5,c6;
    scanf(" %c",&a);
    c1 = check(a,c1);
    scanf(" %c",&b);
    c2 = check(b,c2);
    scanf(" %c",&c);
    c3 = check(c,c3);
    scanf(" %c",&d);
    c4 = check(d,c4);
    scanf(" %c",&e);
    c5 = check(e,c5);
    scanf(" %c",&f);
    c6 = check(f,c6);
    float A = c1+c2+c3;
    float B = c4+c5+c6;
    if (A>10.5) A = 0;
    if (B>10.5) B = 0;
    printf("%.1f\n",A);
    printf("%.1f\n",B);
    if (A>B) printf("A wins.");
    else if (A<B) printf("B wins.");
    else if (A == B) printf("It's a tie.");
}

// 007
// 撲克牌
// A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K
// A~10 點數為 1~10，J, K, Q 為 0.5。
// A, B 兩個人各發三張撲克牌，加總點數越接近 10.5 的贏；超過 10.5 ，爆掉且分數為 0。
// 程式：
// 輸入：A, B 兩個人的三張撲克牌。
// 輸出：兩個人的點數，以及A wins.或B wins.或It's a tie.。

// Sample Input：
// A
// 2
// 3
// 2
// 3
// 4
// Sample Output：
// 6.0
// 9.0
// B wins.

// Sample Input：
// A
// 2
// 3
// A
// 2
// 3
// Sample Output：
// 6.0
// 6.0
// It's a tie.

