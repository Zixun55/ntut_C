#include<stdio.h>
int turn10(int x[][9]){
    int top1 = x[1][0],front1 = x[2][0],buttom1 = x[3][0],back1 = x[0][0];
    int top2 = x[1][3],front2 = x[2][3],buttom2 = x[3][3],back2 = x[0][3];
    int top3 = x[1][6],front3 = x[2][6],buttom3 = x[3][6],back3 = x[0][6];
    int left1 = x[5][2],left2 = x[5][5],left3 = x[5][8],left4 = x[5][1],left5 = x[5][4],left6 = x[5][7],left7 = x[5][0],left8 = x[5][3],left9 = x[5][6];
    x[0][0] = top1;
    x[0][3] = top2;
    x[0][6] = top3;
    x[1][0] = front1;
    x[1][3] = front2;
    x[1][6] = front3;
    x[2][0] = buttom1;
    x[2][3] = buttom2;
    x[2][6] = buttom3;
    x[3][0] = back1;
    x[3][3] = back2;
    x[3][6] = back3;
    x[5][0] = left1;
    x[5][1] = left2;
    x[5][2] = left3;
    x[5][3] = left4;
    x[5][4] = left5;
    x[5][5] = left6;
    x[5][6] = left7;
    x[5][7] = left8;
    x[5][8] = left9;
}
int turn11(int x[][9]){
    int top1 = x[1][1],front1 = x[2][1],buttom1 = x[3][1],back1 = x[0][1];
    int top2 = x[1][4],front2 = x[2][4],buttom2 = x[3][4],back2 = x[0][4];
    int top3 = x[1][7],front3 = x[2][7],buttom3 = x[3][7],back3 = x[0][7];
    x[0][1] = top1;
    x[0][4] = top2;
    x[0][7] = top3;
    x[1][1] = front1;
    x[1][4] = front2;
    x[1][7] = front3;
    x[2][1] = buttom1;
    x[2][4] = buttom2;
    x[2][7] = buttom3;
    x[3][1] = back1;
    x[3][4] = back2;
    x[3][7] = back3;
}
int turn12(int x[][9]){
    int top1 = x[1][2],front1 = x[2][2],buttom1 = x[3][2],back1 = x[0][2];
    int top2 = x[1][5],front2 = x[2][5],buttom2 = x[3][5],back2 = x[0][5];
    int top3 = x[1][8],front3 = x[2][8],buttom3 = x[3][8],back3 = x[0][8];
    int right1 = x[4][6],right2 = x[4][3],right3 = x[4][0],right4 = x[4][7],right5 = x[4][4],right6 = x[4][1],right7 = x[4][8],right8 = x[4][5],right9 = x[4][2];
    x[0][2] = top1;
    x[0][5] = top2;
    x[0][8] = top3;
    x[1][2] = front1;
    x[1][5] = front2;
    x[1][8] = front3;
    x[2][2] = buttom1;
    x[2][5] = buttom2;
    x[2][8] = buttom3;
    x[3][2] = back1;
    x[3][5] = back2;
    x[3][8] = back3;
    x[4][0] = right1;
    x[4][1] = right2;
    x[4][2] = right3;
    x[4][3] = right4;
    x[4][4] = right5;
    x[4][5] = right6;
    x[4][6] = right7;
    x[4][7] = right8;
    x[4][8] = right9;
}
int turn20(int x[][9]){
    int front1 = x[4][0],back1 = x[5][0],right1 = x[3][0],left1 = x[1][0];
    int front2 = x[4][1],back2 = x[5][1],right2 = x[3][1],left2 = x[1][1];
    int front3 = x[4][2],back3 = x[5][2],right3 = x[3][2],left3 = x[1][2];
    int top1 = x[0][6],top2 = x[0][3],top3 = x[0][0],top4 = x[0][7],top5 = x[0][4],top6 = x[0][1],top7 = x[0][8],top8 = x[0][5],top9 = x[0][2];
    x[1][0] = front1;
    x[1][1] = front2;
    x[1][2] = front3;
    x[3][0] = back1;
    x[3][1] = back2;
    x[3][2] = back3;
    x[4][0] = right1;
    x[4][1] = right2;
    x[4][2] = right3;
    x[5][0] = left1;
    x[5][1] = left2;
    x[5][2] = left3;
    x[0][0] = top1;
    x[0][1] = top2;
    x[0][2] = top3;
    x[0][3] = top4;
    x[0][4] = top5;
    x[0][5] = top6;
    x[0][6] = top7;
    x[0][7] = top8;
    x[0][8] = top9;
}
int turn21(int x[][9]){
    int front1 = x[4][3],back1 = x[5][3],right1 = x[3][1],left1 = x[0][3];
    int front2 = x[4][4],back2 = x[5][4],right2 = x[3][4],left2 = x[0][4];
    int front3 = x[4][5],back3 = x[5][5],right3 = x[3][5],left3 = x[0][5];
    x[1][3] = front1;
    x[1][4] = front2;
    x[1][5] = front3;
    x[3][3] = back1;
    x[3][4] = back2;
    x[3][5] = back3;
    x[4][3] = right1;
    x[4][4] = right2;
    x[4][5] = right3;
    x[5][3] = left1;
    x[5][4] = left2;
    x[5][5] = left3;
}
int turn22(int x[][9]){
    int front1 = x[4][6],back1 = x[5][6],right1 = x[3][6],left1 = x[0][6];
    int front2 = x[4][7],back2 = x[5][7],right2 = x[3][7],left2 = x[0][7];
    int front3 = x[4][8],back3 = x[5][8],right3 = x[3][8],left3 = x[0][8];
    int buttom1 = x[2][2],buttom2 = x[2][5],buttom3 = x[2][8],buttom4 = x[2][1],buttom5 = x[2][4],buttom6 = x[2][7],buttom7 = x[2][0],buttom8 = x[2][3],buttom9 = x[2][6];
    x[1][6] = front1;
    x[1][7] = front2;
    x[1][8] = front3;
    x[3][6] = back1;
    x[3][7] = back2;
    x[3][8] = back3;
    x[4][6] = right1;
    x[4][7] = right2;
    x[4][8] = right3;
    x[5][6] = left1;
    x[5][7] = left2;
    x[5][8] = left3;
    x[2][0] = buttom1;
    x[2][1] = buttom2;
    x[2][2] = buttom3;
    x[2][3] = buttom4;
    x[2][4] = buttom5;
    x[2][5] = buttom6;
    x[2][6] = buttom7;
    x[2][7] = buttom8;
    x[2][8] = buttom9;
}

int main(void){
    int time,turn;
    int ans[6][9]={{1,1,1,1,1,1,1,1,1},{4,4,4,4,4,4,4,4,4},{6,6,6,6,6,6,6,6,6},{3,3,3,3,3,3,3,3,3},{2,2,2,2,2,2,2,2,2},{5,5,5,5,5,5,5,5,5}};//上,前,下,後,右,左
    scanf("%d",&time);

    for (int i=0;i<time;i++){
        scanf("%d",&turn);
        if (turn == 10) turn10(ans);
        else if (turn == 11) turn11(ans);
        else if (turn == 12) turn12(ans);
        else if (turn == 20) turn20(ans);
        else if (turn == 21) turn21(ans);
        else if (turn == 22) turn22(ans);
    }
    printf("%d %d %d\n%d %d %d \n%d %d %d\n\n",ans[0][0],ans[0][1],ans[0][2],ans[0][3],ans[0][4],ans[0][5],ans[0][6],ans[0][7],ans[0][8]);
}
// 魔術方塊有六面，一開始白色朝自己，藍色朝上，紅色2 朝右 如連結所示(https://imgur.com/kzYkXZ8)，展開如連結所示(https://imgur.com/7JnAXUZ)。
// 顏色編號，1: 藍色，2: 紅色，3: 黃色，4: 白色，5: 橘色，6:綠色。
// 接下來 M 次修改操作，每次操作包含一個整數 a，意義為：
// 10 表示直欄(column)最左邊向前轉一次。
// 11 表示直欄(column)中間向前轉一次。
// 12 表示直欄(column)最右邊向前轉一次。
// 20 表示橫列(row)最上面向左轉一次。
// 21 表示橫列(row)中間向左轉一次。。
// 22 表示橫列(row)最下面向左轉一次。。
// 操作修正完成，請輸出朝上9格的顏色編號。
// Sample Input
// 1
// 10
// Sample Output
// 4 1 1
// 4 1 1
// 4 1 1
// Sample Input
// 3
// 10
// 20
// 10
// Sample Output
// 2 4 4
// 6 1 1
// 6 1 1

// Sample Input
// 4
// 10
// 21
// 12
// 20
// Sample Output
// 4 4 4
// 1 1 1
// 4 2 4

