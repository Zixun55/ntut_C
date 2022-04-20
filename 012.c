#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b){ 
    int ans=1;
    int i=2;
    if( a==1 || b==1 ) return 1;
    if( a==0 || b==0 ) return 1;
    else if( a>=i && b>=i ){
        while( a>=i && b>=i){
            while( a%i==0 && b%i==0){ 
                ans = ans * i; 
                a /= i; 
                b /= i; 
            } 
            i++; 
        } 
        return ans; 
     }
}
int main(void){
    while (1){
        int a1,a2,b1,b2,g,i;
        char d_a,d_b,cal,con;
        scanf("%d%c%d",&a1,&d_a,&a2);
        scanf(" %d%c%d",&b1,&d_b,&b2);
        scanf(" %c",&cal);
        scanf(" %c",&con);
        if (a2 == 0 || b2 == 0){
            printf("ERROR\n");
            if (con == 'n') break;
            continue;
        }
        if (cal == '+'){
            a1 *= b2;
            b1 *= a2; 
            a2 *= b2;
            a1 += b1;
        }
        else if (cal == '-'){
            a1 *= b2;
            b1 *= a2;
            a2 *= b2;
            a1 -= b1;
        }
        else if (cal == '*'){
            a1 *= b1;
            a2 *= b2;
        }
        else if (cal == '/'){
            a1 *= b2;
            a2 *= b1;
        }
        
        g = gcd(abs(a1),abs(a2));
        a1 /= g;
        a2 /= g;
        if (a1<0 && a2<0){
            a1 = abs(a1);
            a2 = abs(a2);
        }
        if (a1>0 && a2<0){
            a1 = 0-a1;
            a2 = abs(a2);
        }
        if (a1 == 0){
            printf("0\n");
        }
        else if (abs(a1)>=abs(a2)){
            i = a1/a2;
            a1 = a1 - (a2 * i);
            if (a1%a2 == 0) printf("%d\n",i);
            else{
                a1 = abs(a1);
                a2 = abs(a2);
                printf("%d(%d/%d)\n",i,a1,a2);
            }
        }
        else printf("%d/%d\n",a1,a2);
        if (con == 'n') break;
    }
}

// 012
// 分數四則運算

// 計算兩個分數四則運算 。

// 輸入說明:
// ----------------------------
// 輸入四行，第一、二行各代表一個分數，第三行代表數學運算符號(+-*/)，第四行代表是否繼續運算(y表示繼續運算、n表示不繼續運算)

// --------------------
// 輸出說明:
// ----------------------------
// 輸出分數結果

// **輸入分子可能大於分母**
// 若有輸入分數的分母為0，則輸出ERROR。
// 若分數大於1，則分數部分要加括號，如一又六分之一輸出為1(1/6)
// 若為負數，負號在最前面。
// 若輸出為0，則顯示0
// 輸出的結果必須化簡為最簡分數
// ----------------
// Sample input:
// ----------------
// 1/2
// 2/3
// +
// y
// -1/4
// 1/5
// *
// n


// ----------------
// Sample output:
// ----------------
// 1(1/6)
// -1/20



// ----------------
// Sample input:
// ----------------
// 2/0
// 2/3
// -
// n


// ----------------
// Sample output:
// ----------------
// ERROR

