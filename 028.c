#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    double total=0;
    for (int i=0;i<n;i++){
        char type;
        scanf(" %c",&type);
        if (type=='T'){
            double a,b,c;
            scanf(" %lf %lf %lf",&a,&b,&c);
            printf("%.2lf\n",a+b+c);
            total+=a+b+c;
        }
        else if (type=='S'){
            double a;
            scanf(" %lf",&a);
            printf("%.2lf\n",a*4);
            total+=4*a;
        }
        else if (type=='R'){
            double a,b;
            scanf(" %lf %lf",&a,&b);
            printf("%.2lf\n",2*a+2*b);
            total+=2*a+2*b;
        }
        else if (type=='C'){
            double a;
            scanf(" %lf",&a);
            a=2*a*3.14;
            printf("%.2lf\n",a);
            total+=a;
        }
    }
    printf("%.2lf\n",total);
    return 0;
}

// 利用結構 struct 定義
// Shape（圖形）, Circle（圓）, Rectangle（矩形）, Square（正方形）, Triangle（三角形）。
// 圓有半徑，矩形有長和寬，正方形有邊長，三角形有三個邊。
// 計算各個圖形的周長，以及所有圖形的周長加總。
// 此題須使用以下struct及function pointer實作，否則不予計分。
// (使用規定架構進行實作並通過所有測資才予以給分，期末會進行檢查)

// 輸入說明:
// 圖形個數、圖形種類與其屬性
// 圖形種類以代號輸入，代號如下所示：
// C：圓形，屬性內容具有radius (圓周率請使用3.14)
// R：矩形，屬性內容具有length、width
// S：正方形，屬性內容具有edge
// T：三角形，屬性內容具有3個edge

// 輸出說明：
// 各個圖形的周長、各個圖形的周長總和
// (四捨五入到小數點後第2位，總和請先加總好再四捨五入)

// Sample Input：
// 4
// T 2.2 3.3 4.4
// S 1.1
// R 1.1 2.2
// C 1.0

// Sample Output：
// 9.90
// 4.40
// 6.60
// 6.28
// 27.18

// -----------------

// Sample Input：
// 1
// C 0.31847

// Sample Output：
// 2.00
// 2.00



// ------程式碼架構規範之範例---------------------
// #define ShapeText(TYPE) char name[10];
// double (*perimeter)(struct TYPE*);
// double (*area)(struct TYPE*);
// typedef struct shape_s {
// ShapeText(shape_s);
// } shape_t;
// typedef struct circle_s {
// ShapeText(circle_s);
// double radius;
// } circle_t;


