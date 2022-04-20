#include<stdio.h>
int move1(int x[]){
    int top = x[3],front = x[0],buttom = x[1],back = x[2];
    x[0] = top;
    x[1] = front;
    x[2] = buttom;
    x[3] = back;
}
int move2(int x[]){
    int top = x[1],front = x[2],buttom = x[3],back = x[0];
    x[0] = top;
    x[1] = front;
    x[2] = buttom;
    x[3] = back;
}
int move3(int x[]){
    int top = x[5],buttom = x[4],right = x[0],left = x[2];
    x[0] = top;
    x[2] = buttom;
    x[4] = right;
    x[5] = left;
}
int move4(int x[]){
    int top = x[4],buttom = x[5],right = x[2],left = x[0];
    x[0] = top;
    x[2] = buttom;
    x[4] = right;
    x[5] = left;
}
int main(void){
    int dice_a[6] = {1,4,6,3,2,5},dice_b[6] = {1,4,6,3,2,5},dice_c[6] = {1,4,6,3,2,5},dice_d[6] = {1,4,6,3,2,5};//上,前,下,後,右,左
    int time,a,b,c,d,ans,sto[4]={0,0,0,0},j=0;
    scanf(" %d",&time);
    for (int i=0;i<time;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if (a==1) move1(dice_a);
        else if (a==2) move2(dice_a);
        else if (a==3) move3(dice_a);
        else if (a==4) move4(dice_a);
        if (b==1) move1(dice_b);
        else if (b==2) move2(dice_b);
        else if (b==3) move3(dice_b);
        else if (b==4) move4(dice_b);
        if (c==1) move1(dice_c);
        else if (c==2) move2(dice_c);
        else if (c==3) move3(dice_c);
        else if (c==4) move4(dice_c);
        if (d==1) move1(dice_d);
        else if (d==2) move2(dice_d);
        else if (d==3) move3(dice_d);
        else if (d==4) move4(dice_d);
    }
    for (int i=1;i<7;i++){
        if (dice_a[0] == i){
            sto[j] = i;
            j++;
        }
        if (dice_b[0] == i){
            sto[j] = i;
            j++;
        }
        if (dice_c[0] == i){
            sto[j] = i;
            j++;
        }
        if (dice_d[0] == i){
            sto[j] = i;
            j++;
        }
    }
    if ((dice_a[0]==dice_b[0]) && (dice_a[0]==dice_c[0]) && (dice_a[0]==dice_d[0])) ans = 18;
    else if ((dice_a[0]!=dice_b[0]) && (dice_a[0]!=dice_c[0]) && (dice_a[0]!=dice_d[0]) && (dice_b[0]!=dice_c[0]) && (dice_b[0]!=dice_d[0]) && (dice_c[0]!=dice_d[0])) ans = 0;
    else if ((sto[0]==sto[1] && sto[1]==sto[2] && sto[0]!=sto[3]) || (sto[1]==sto[2] && sto[2]==sto[3] && sto[0]!=sto[1])) ans = 0;
    else if (sto[0]==sto[1] && sto[2]==sto[3] && sto[0]!=sto[2]) ans = sto[2] + sto[3];
    else if (sto[0]==sto[1] && sto[0]!=sto[2] && sto[0]!=sto[3] && sto[2]!=sto[3]) ans = sto[2] + sto[3];
    else if (sto[1]==sto[2] && sto[1]!=sto[0] && sto[1]!=sto[3] && sto[0]!=sto[3]) ans = sto[0] + sto[3];
    else if (sto[2]==sto[3] && sto[2]!=sto[0] && sto[2]!=sto[1] && sto[0]!=sto[1]) ans = sto[0] + sto[1];
    printf("%d\n",ans);
}

// 十八骰子是一種常見的擲骰子遊戲，用四顆骰子計點。四顆一開始都是點數 1 朝上，點數 4 朝前，點數 2 朝右，如連結所示 (https://imgur.com/Ntds1Ri)，骰子展開如連結所示(https://imgur.com/xEVHA5h)。

// 接下來 N 次修改操作，每次操作包含四個整數 a, b, c, d 代表四個骰子操作。a, b, c, d意義為：
// 1. 1 表示向前滾一次。
// 2. 2 表示向後滾一次。
// 3. 3 表示向右滾一次。
// 4. 4 表示向左滾一次。
// 操作修正完成，請輸出點數，計點方式：
// 1. 若四顆點數均相同，稱一色，計18點，例如6, 6, 6, 6 或 3, 3, 3, 3。
// 2. 若四顆點數均不同；或有三顆點數相同，一顆不同，計 0點，例如 1, 2, 3, 4 或 2, 2, 2, 6。
// 3. 若兩顆點數相同，另兩顆點數也相同，但兩組兩顆點數不同，則點數計算為 - 加總兩顆較大點數，例如 2, 2, 5, 5，加總兩顆較大點數為 5+5=10點。
// 4. 若兩顆點數相同，另兩顆點數不同，則點數計算為加總兩顆不同點數，例如 2, 2, 4, 5，加總兩顆不同點數為 4+5=9點。

// Sample Input
// 1
// 1 1 1 1
// Sample Output
// 18

// Sample Input
// 2
// 1 2 3 4
// 1 2 3 4
// Sample Output
// 18

// Sample Input
// 2
// 1 2 3 4
// 4 3 2 1
// Sample Output
// 0

