#include <stdio.h>
#include <string.h>
int main(void){
    int m,m_count=0;
    char inp[20];
    scanf("%s",&inp);
    scanf( "%d",&m);
    int l = strlen(inp);
    for (int i=0;i<l-m+1;i++){
        int time=0;
        for (int j=0;j<m-1;j++){//判斷重複
            for (int k=j+1;k<m;k++){
                if (inp[i+j] == inp[i+k]){
                    time = -1;
                    break;
                }    
            }
            if (time == -1) break;
            else time+=1;
        }
        if (time==(m-1)) m_count+=1;
    }
    printf("%d",m_count);
}
// 016 分散度
// 輸入一串整數序列和m分散度，輸出m分散度數量。
// m分散度定義為，序列中擁有長度為m 且有m 種不同數字的連續子序列之數量。
// 例如，m = 3，序列{1 2 3 5 4 5 4}，3 分散度數量{1 2 3}, {2 3 5}, {3 5 4}，總共三個。
// sample input:
// 1235454
// 3
// sample output:
// 3
// ----------------
// sample input:
// 1866454122
// 5
// sample output:
// 0

