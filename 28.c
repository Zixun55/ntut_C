#include <stdio.h>
#define ShapeText(TYPE) \
    float (*perimeter)(struct TYPE*);
typedef struct _Shape {
    ShapeText(_Shape);
} Shape_t;

typedef struct _Circle {
    ShapeText(_Circle);
    double radius;
} Circle;

typedef struct _triangle{
    ShapeText(_triangle);
    double e1;
    double e2;
    double e3;
} Triangle;

typedef struct _square{
    ShapeText(_square);
    double e;
} Square;

typedef struct _rectangle{
    ShapeText(_rectangle);
    double length;
    double width;
} Rectangle;

float CirclePerimeter(Circle *obj)
{ 
    return 2*3.14 * obj->radius; 
}

float RectanglePerimeter(Rectangle *obj)
{ 
    return 2*obj->length+2*obj->width; 
}

float TrianglePerimeter(Triangle *obj)
{ 
    return obj->e1+obj->e2+obj->e3; 
}

float SquarePerimeter(Square *obj){ 
    return 4*obj->e; 
}

void CircleNew(Circle *obj) {
    obj->perimeter = CirclePerimeter;
}

void SquareNew(Square *obj) {
    obj->perimeter = SquarePerimeter;
}

void TriangleNew(Triangle *obj){
    obj->perimeter = TrianglePerimeter;
}

void RectangleNew(Rectangle *obj){
    obj->perimeter = RectanglePerimeter;
}

int main(){
    int time;
    double total,perimeter_num;
    char which;
    Triangle tri;
    Rectangle rec;
    Square squ;
    Circle cir;
    scanf(" %d",&time);
    double ans[time];
    for (int i = 0; i<time ;i++){
        scanf(" %c",&which);
        switch (which)
        {
            case  'T':
            {
                scanf("%lf %lf %lf",&tri.e1,&tri.e2,&tri.e3);
                TriangleNew(&tri);
                perimeter_num=tri.perimeter(&tri);
                ans[i]=perimeter_num;
                break;
            }
            case 'S':
            {
                scanf("%lf",&squ.e);
                SquareNew(&squ);
                perimeter_num=squ.perimeter(&squ);
                ans[i]=perimeter_num;
                break;
            }
            case 'R':
            {
                scanf("%lf %lf",&rec.length,&rec.width);
                RectangleNew(&rec);
                perimeter_num=rec.perimeter(&rec);
                ans[i]=perimeter_num;    
                break;
            }
            case 'C':
            {
                scanf("%lf",&cir.radius);
                CircleNew(&cir);
                perimeter_num=cir.perimeter(&cir);
                ans[i]=perimeter_num;
                break;           
            }
        }
        total+=perimeter_num;
    }
    for(int i=0;i<time;i++){
        printf("%.2f\n",ans[i]);
    }
    printf("%.2f\n",total);
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
