#include<stdio.h>
#define GATEVALUE(TYPE) int(*GateValue)(int,int)
typedef struct _GateOr{
    GATEVALUE();
}GateOr;
int GateOrValue(int i1,int i2){
    if (i1 == 1 || i2 == 1) return 1;
    else return 0;
}

typedef struct _GateAnd{
    GATEVALUE();
}GateAnd;
int GateAndValue(int i1,int i2){
    return i1 == 1 && i2 ==1;
}

typedef struct _GateXor{
    GATEVALUE();
}GateXor;
int GateXorValue(int i1,int i2){
    if ((i1 == 0 && i2 == 0) || (i1 == 1 && i2 == 1)) return 0;
    else return 1;
}

void CreateGateOR(GateOr *obj){obj->GateValue = GateOrValue;}
void CreateGateAND(GateAnd *obj){obj->GateValue = GateAndValue;}
void CreateGateXOR(GateXor *obj){obj->GateValue = GateXorValue;}

int main(int argc, char *argv[]){
    int I1,I2,I3,I4,p1,p2,p3;
    char str[12];
    int pa,pc,pe;
    scanf("%d,%d,%d,%d",&I1,&I2,&I3,&I4);
    scanf("%s",&str);
    char A = str[0],B = str[2],C = str[4],D = str[6],E = str[8],F = str[10];
    GateOr or;
    CreateGateOR(&or);
    GateAnd and;
    CreateGateAND(&and);
    GateXor xor;
    CreateGateXOR(&xor);

    if (A == 'A') pa = and.GateValue(I1,I1);
    else if (A == 'O') pa = or.GateValue(I1,I1);
    else if (A == 'X') pa = xor.GateValue(I1,I1);
    else if (A == 'N'){
        if (I1 == 1) pa = 0;
        else if (I1 == 0) pa = 1;
    }
    else if (A == 'E') pa = I1;

    if (B == 'A') p1 = and.GateValue(I2,pa);
    else if (B == 'O') p1 = or.GateValue(I2,pa);
    else if (B == 'X') p1 = xor.GateValue(I2,pa);

    if (C == 'A') pc = and.GateValue(I3,p1);
    else if (C == 'O') pc = or.GateValue(I3,p1);
    else if (C == 'X') pc = xor.GateValue(I3,p1);

    if (D == 'A') p2 = and.GateValue(p1,pc);
    else if (D == 'O') p2 = or.GateValue(p1,pc);
    else if (D == 'X') p2 = xor.GateValue(p1,pc);

    if (E == 'A') pe = and.GateValue(I4,I4);
    else if (E == 'O') pe = or.GateValue(I4,I4);
    else if (E == 'X') pe = xor.GateValue(I4,I4);
    else if (E == 'N'){
        if (I4 == 1) pe = 0;
        else if (I4 == 0) pe =  1;
    }
    else if (E == 'E') pe = I4;

    if (F == 'A') p3 = and.GateValue(p2,pe);
    else if (F == 'O') p3 = or.GateValue(p2,pe);
    else if (F == 'X') p3 = xor.GateValue(p2,pe);

    printf("%d,%d,%d",p1,p2,p3);
    return 0;
}

// 本題必須使用後所附程式碼架構
// (使用規定架構進行實作並通過所有測資才予以給分，期末會進行檢查)
// 以下邏輯電路圖，輸入為 I1, I2, I3，輸出為 O1, O2, O3

// 　　　　　　　　O1
// I1 -->A---->B　　↑
// 　　　　　B------★------------->D　O2
// I2 --------->B　　　　|　　　　D　↑
// 　　　　　　　　　----->C 　D---★-->F　　O3
// 　　　　　　　　　　　C--->D　　　F　　↑
// I3 --------------------------->C　　D　　　F-----★
// 　　　　　　　　　　　　　　　　　F
// I4------------------E--------------------------->F

// (社團會再放一張更整齊的版本，同學可以去查看)


// 輸入I1, I2, I3, I4，以及設定AND, OR, XOR, NOT四種邏輯閘與Empty邏輯閘(即不設置邏輯閘)
// 輸出O1, O2, O3

// A, E邏輯閘：單輸入單輸出邏輯閘(NOT 與 Empty)
// B, C, D, F邏輯閘：雙輸入單輸出邏輯閘(AND, OR與XOR)

// 輸入說明:
// 第一行依次輸入I1, I2, I3, I4為 0 或 1，中間以逗號間隔。
// 第二行輸入A, B, C, D, E, F邏輯閘的設定，欲輸入的邏輯閘種類代號如下所示：
// A：AND Gate
// O：OR Gate
// X：XOR Gate
// N：NOT Gate
// E：Empty Gate
// (A邏輯閘僅代表順序第一順位輸入，並非固定為AND閘，只會有N與E邏輯閘種類代號輸入)
// 輸入順序：
// I1,I2,I3,I4
// A,B,C,D,E,F


// 輸出說明:
// 輸出O1, O2, O3為 0 或 1，中間以逗號間隔
// 輸出順序：O1,O2,O3

// 範例:

// Sample Input:
// 0,0,0,0
// N,A,O,X,N,A

// Sample Output:
// 0,0,0

// -------------

// Sample Input:
// 1,0,1,1
// E,X,A,A,N,O

// Sample Output:
// 1,1,1


// ------程式碼架構規範之範例---------------------

// #include
// #include
// #define GATEVALUE(TYPE) int(*GateValue)(void)
// typedef struct _Gate{
// GATEVALUE();
// }Gate;
// int GateGetValue(){return 0;}
// typedef struct _GateAnd{
// GATEVALUE();
// }GateAnd;
// int GateAndValue(){return 1;}
// void CreateGate(Gate *obj){
// obj->GateValue = GateGetValue;
// }
// void CreateGateAND(GateAnd *obj){
// obj->GateValue = GateAndValue;
// }
// int main(int argc, char *argv[]){
// Gate gate;
// CreateGate(&gate);
// GateAnd and;
// CreateGateAND(&and);
// printf("Gate = %d, GateAND = %d\n", gate.GateValue(), and.GateValue());
// return 0;
// }


