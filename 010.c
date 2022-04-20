#include <stdio.h>
#include <math.h>
int con(long long n){//二進制轉十進制
    int d = 0, i = 0, r;
    while (n!=0){
        r = n%10;
        n /= 10;
        d += r*pow(2,i);
        ++i;
    }
    return d;
}
int C_m(int n,int time){
    if (n == 0 || n == 1) return time;
    else if (n%2 == 0) time = 1 + C_m(n/2,time);
    else if (n%2 != 0) time = 1+ C_m((n+1)/2,time);
    else return time;
}
int main(void){
    while (1){
        long long n;
        int j,time = 0,a[4]={0,0,0,0},i=0;
        scanf("%lld", &n);
        scanf("%d",&j);
        n = con(n);
        time = C_m(n,time);
        while (time>0){  //十進制轉二進制
            a[i] = time%2;   
            i = i+1;
            time = time/2;
        }
        printf("%d%d%d%d\n",a[3],a[2],a[1],a[0]);
        if (j == -1) break;
    }
}

// 010 數位電路模擬I

// 模擬一個數位IC，內有回饋電路與紀錄器電路
// 輸入m 是二進位 8 位元，輸出是二進位 4 位元
// 輸入範圍從 00000000 到 11111111 (十進位 0~255)
// 回饋方式為 :
// C(m) = m if m = 0 or m = 1 (十進位)
// C(m) = C(m/2) if m 偶數(十進位)
// C(m) = C((m+1)/2) if m 奇數(十進位)
// 例 :
// m=00001010(十進位 10)，則電路回饋依序為十進位 5, 3, 2, 1
// C(10)= C(5)=C(3)=C(2)=C(1)=1，共回饋 4 次
// 紀錄器會記錄回饋電路的回饋次數
// R(m) = [C(m) 的回饋次數]，例如 R(10) = 4
// 若數位IC的輸入為m=00001010(十進位 10) ，因回饋電路的回饋次數為4，則此數位IC輸出為 0100 (十進位 4)

// -------------
// 輸入說明 :
// 二進位 8 bit 位元
// 第一行是第一個測試案例資料
// 接著是一行 0 分隔測試資料
// 第三行是第二個測試案例資料
// ....
// 最後 -1 結束

// -------------
// 輸出說明 :
// 二進位 4 bit 位元
// 每一行是一個測試案例資料的結果

// -------------
// Sample Input:
// 00000000
// 0
// 11111111
// 0
// 00000001
// 0
// 10000000
// 0
// 00111111
// -1
// -------------
// Sample Output:
// 0000
// 1000
// 0000
// 0111
// 0110

// -------------
// Sample Input:
// 00001010
// 0
// 01100100
// -1
// -------------
// Sample Output:
// 0100
// 0111
