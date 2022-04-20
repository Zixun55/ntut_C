#include <stdio.h>
#include <stdlib.h>
int gcd(int a,int b){ 
    int ans=1; //起始數為1
    int i=2; //質因數分解由2開始
    if( a==1 || b==1 ) return 1;
    if( a==0 || b==0 ) return 1;
    else if( a>=i && b>=i ){//a,b皆大於等於2時，開始質因數分解 
        while( a>=i && b>=i){ //餘數皆為0時，2開始質因數分解，若皆被2分完，則陸續增加為3、4、5…… 
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
    int x1,y1,x2,y2,x,y,b1,b2,m,b,g1,g2;
    char d1,d2;
    scanf ("%d%c%d",&x1,&d1,&y1);
    scanf ("%d%c%d",&x2,&d2,&y2);
    x = x1-x2;
    y = y1-y2;
    b1 = x2*y1-x1*y2;
    b2 = x2-x1;
    m = y/x;
    b = b1/b2;
    g1 = gcd(abs(x),abs(y));
    g2 = gcd(abs(b1),abs(b2));
    if (x<0 && y<0){
        x = abs(x);
        y = abs(y);
    }
    if (b1<0 && b2<0){
        b1 = abs(b1);
        b2 = abs(b2);
    }
    x = x/g1;
    y = y/g1;
    b1 = b1/g2;
    b2 = b2/g2;
    if (y == 0){
        if (b1%b2 == 0) printf("y=%d",b);}
    else if (m==1 && y%x == 0){
        if (b>0){
            if (b1%b2 == 0)printf("y=x+%d",b);
            else if (b1%b2 != 0)printf("y=x+%d/%d",b1,b2);
        }else if(b<0){
            if (b1%b2 == 0)printf("y=x%d",b);
            else if (b1%b2 != 0)printf("y=x%d/%d",b1,b2);
        }else printf("y=x");
    }else if (m==-1 && y%x == 0){
        if (b>0){
            if (b1%b2 == 0)printf("y=-x+%d",b);
            else if (b1%b2 != 0)printf("y=-x+%d/%d",b1,b2);
        }else if(b<0){
            if (b1%b2 == 0)printf("y=-x%d",b);
            else if (b1%b2 != 0)printf("y=-x%d/%d",b1,b2);
        }else printf("y=-x");
    }else{
        if (b>0){
            if (y%x == 0 && b1%b2 == 0)printf("y=%dx+%d",m,b);
            else if (y%x != 0 && b1%b2 == 0)printf("y=%d/%dx+%d",y,x,b);
            else if (y%x == 0 && b1%b2 != 0)printf("y=%dx+%d/%d",m,b1,b2);
            else printf("y=%d/%dx+%d/%d",y,x,b1,b2);
        }else if(b<0){
            if (y%x == 0 && b1%b2 == 0)printf("y=%dx%d",m,b);
            else if (y%x != 0 && b1%b2 == 0)printf("y=%d/%dx%d",y,x,b);
            else if (y%x == 0 && b1%b2 != 0)printf("y=%dx%d/%d",m,b1,b2);
            else printf("y=%d/%dx%d/%d",y,x,b1,b2);
        }else{
            if (y%x == 0)printf("y=%dx",m);
            else printf("y=%d/%dx",y,x);
        }}
    }

// 013
// 輸入平面上兩個點，求直線方程式
// 輸入兩點座標，(x1, y1), (x2, y2)
// 輸出 y = mx + b(其中，m=(y1-y2)/(x1-x2)、b = (x2y1-x1y2)/(x2-x1))
// 註:1.不考慮斜率不存在的問題 2.若m與b為分數,表示方式同第12題

// ex:
// input:
// 1,0
// 0,-1

// output:
// y=x-1

// -------------

// input:
// 1,0
// 0,1

// output:
// y=-x+1

