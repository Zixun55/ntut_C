#include <stdio.h>
#include <string.h>

void rev(int big[], char str[],int *neg){//反轉陣列
    int i=0, len=strlen(str);
    for (int j=0;j<200;j++) big[j]=0;
    for(i=len-1; i>=0; --i){
        if (str[i] == '-') *neg=-1;
        else big[len - i - 1] = str[i] - '0';
    }
}
void sub(int ans[],int x[],int y[]){//減法
    int borrow=0;
    for(int i=0; i<200; i++) {
        ans[i] = x[i]-y[i]-borrow;
        if(ans[i]<0) {
            borrow=1, ans[i]+=10;
        } else {
            borrow=0;
        }
    }
}
int main(void){
    int choose,x[200],y[200],ans[200],neg1=1,neg2=1;
    char c_x[200],c_y[200];
    scanf("%d",&choose);
    scanf("%s",&c_x);
    scanf("%s",&c_y);
    for (int j=0;j<200;j++) ans[j]=0;
    rev(x,c_x,&neg1);
    rev(y,c_y,&neg2);

    if (choose == 1){
        int carry = 0;
        if (neg1 * neg2 == 1){
            for (int i=0;i<200;i++){
                ans[i] = x[i] + y[i] + carry;
                if (ans[i]>9){
                    carry = ans[i]/10;
                    ans[i]%=10;
                }
                else carry = 0;
            }
            if (neg1 == -1 && neg2 == -1) printf("-");
        }
        else if (neg1 == -1 && neg2 == 1){
            int a=200-1;
            while(a>0 && x[a] == y[a]) a--;
            if (x[a] < y[a]) sub(ans,y,x);
            else if (x[a] > y[a]){
                printf("-");//負號
                sub(ans,x,y);
            }
        }
        else if (neg1 == 1 && neg2 == -1){
            int a=200-1;
            while(a>0 && x[a] == y[a]) a--;
            if (x[a] > y[a]) sub(ans,x,y);
            else if (x[a] < y[a]){
                printf("-");//負號
                sub(ans,y,x);
            }
        }
    }

    else if (choose == 2){
        if (neg1 == 1 && neg2 == 1){
            int a=200-1;
            while(a>0 && x[a] == y[a]) a--;
            if (x[a] > y[a]) sub(ans,x,y);
            else if (x[a] < y[a]){
                printf("-");//負號
                sub(ans,y,x);
            }
        }
        else if (neg1 == 1 && neg2 == -1){
            int carry = 0;
            for (int i=0;i<200;i++){
                ans[i] = x[i] + y[i] + carry;
                if (ans[i]>9){
                    carry = ans[i]/10;
                    ans[i]%=10;
                }
                else carry = 0;
            }
        }
        else if (neg1 == -1 && neg2 == 1){
            int carry = 0;
            for (int i=0;i<200;i++){
                ans[i] = x[i] + y[i] + carry;
                if (ans[i]>9){
                    carry = ans[i]/10;
                    ans[i]%=10;
                }
                else carry = 0;
            }
            printf("-");
        }
        else if (neg1 == -1 && neg2 == -1){
            int a=200-1;
            while(a>0 && x[a] == y[a]) a--;
            if (x[a] > y[a]){
                printf("-");//負號
                sub(ans,x,y);
            }
            else if (x[a] < y[a]) sub(ans,y,x);
        }
    }

    else if (choose == 3){
        int c=0;
        for(int i=0; i<200; i++) {
            for(int j=0; i+j<200; j++)
                ans[i+j]+= x[i]*y[j];
        }

        for(int i=0; i<200; i++) {
            ans[i]+=c;
            c = ans[i] / 10;
            ans[i] %= 10;
        }
        if (neg1*neg2 == -1) printf("-");
    }

    int b=200-1;
    for (int i=200-1;i>=0;i--) {
        if (ans[b]==0)b--;
        else break;
    }
    while(b>=0) printf("%d", ans[b]), b--;
}

// 輸入長整數運算的模式，
// 以1代表長整數相加；2代表長整數相減；3代表長整數相乘。
// 再輸入兩個20位數以上的整數做運算，
// 並輸出計算過後的結果。
// **長整數可能為負數**
// sample input:
// 1
// 10000000000000000001
// 99999999999999999999
// sample output:
// 110000000000000000000

// --------------------------------

// sample input:
// 2
// -45112365412452139545
// 13245645215412645641

// sample output:
// -58358010627864785186

// --------------------------------

// sample input:
// 3
// 11111222221111122222
// -10000123452000012345

// sample output:
// -111113593913716999998298869960803830590

// --------------------------------

// sample input:
// 3
// -10000100000000000001
// -12121212121212121212

// sample output:
// 121213333333333333344242412121212121212

