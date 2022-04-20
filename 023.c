#include<stdio.h>
#include<math.h>
//f1(x) =((a-x^2))^(1/2)
//f2(x) = (ax^3 + 7x)/(a+x)^(1/2)
//A(n) = ((q-p)/2n)[f(p)+2f(p+x)+2f(p+2x)+...+2f(q-x)+f(q)]
int f1(double x,double a){
    double y = a-x*x;
    return (pow(y,0.5));
}
int main(){
    while (1){
        int type,ox,n=1,a,p,q,err;
        scanf("%d",&type);
        double x,ans,restore,sub;
        scanf("%lf",&a);
        scanf("%lf",&p);
        scanf("%lf",&q);
        scanf("%lf",&err);
        scanf("%d",&ox);
        err = 0-err;
        while (1){
            x = (p-q) / n;
            if (type == 1){
                printf("1");
                double f = f1(p,a);
                for (int i=p+x;i<=q;i+x) f += 2*f1(i,a);
                restore = ((q-p)/(2*n))*f;
                sub = restore-ans;
                if (sub<0) sub *= -1;
                if (n!=1 && sub>=pow(10,err)) n = n*2;
                ans = restore;
                if (sub<pow(10,err)) break;
            }
            // else if (type == 2){
                
            // }
        }
        printf("%.12lf",ans);
        if (ox == 0) break;
    }
    
    return 0;
}

// 023
// 使用切割面積加總法公式(將函式切成N個梯形)，
// 計算函式f(x)從f(p)到f(q)之間的面積， x 值從區間起始 p 到區間終點 q
// f1(x) =((a-x^2))^(1/2) ; f2(x) = (ax^3 + 7x)/(a+x)^(1/2), a 為常數(可能有小數)。
// 選定這兩個函數之一，使用梯形法來估計從x=p到x=q的面積
// 梯形面積公式如下，若一個函數圖形切成n塊，則梯形法的估計為:
// A(n) = ((q-p)/2n)[f(p)+2f(p+x)+2f(p+2x)+...+2f(q-x)+f(q)]，其中x = (q-p) / n
// 初始設定 n=1，每次不符合所期待的精確度err時*2( n=n*2 )。
// err為精確小數位數，例如 err=6，即 "目前"與"上一次"兩次切割，
// 計算出的面積值的差小於 10 的負6次方，亦即小於 0.000001。
// 輸入說明：
// 輸入 1 代表計算 f1(x) 面積，輸入 2 代表計算 f2(x)面積，
// 接著依序，輸入 a, p, q, err，輸入0為停止輸入。
// 此題測試資料為連續輸入一至多筆資料(有可能一次輸入包含多組測資)。
// 答案需輸出到小數點第12位
// 範例一.
// Input:
// 1
// 4
// -2
// 1
// 9
// 0
// Output:
// 5.054815608319

// 範例二.
// Input:
// 2
// 1
// 0
// 3
// 9
// 0
// Output:
// 29.752380952687

// 範例三.
// Input:
// 1
// 100
// -10
// 10
// 6
// 1
// 100
// -1
// 8
// 8
// 0
// Output:
// 157.079632241407
// 80.348069141438


