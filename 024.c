#include<stdio.h>
#include <string.h>
int g(char inp[]){
    if (strcmp(inp,"A+")==0) return 95;
    else if (strcmp(inp,"A")==0) return 87;
    else if (strcmp(inp,"A-")==0) return 82;
    else if (strcmp(inp,"B+")==0) return 78;
    else if (strcmp(inp,"B")==0) return 75;
    else if (strcmp(inp,"B-")==0) return 70;
    else if (strcmp(inp,"C+")==0) return 68;
    else if (strcmp(inp,"C")==0) return 65;
    else if (strcmp(inp,"C-")==0) return 60;
    else if (strcmp(inp,"F")==0) return 50;
}
int gpa(char inp[]){
    if (strcmp(inp,"4.3")==0) return 95;
    else if (strcmp(inp,"4.0")==0) return 87;
    else if (strcmp(inp,"3.7")==0) return 82;
    else if (strcmp(inp,"3.3")==0) return 78;
    else if (strcmp(inp,"3.0")==0) return 75;
    else if (strcmp(inp,"2.7")==0) return 70;
    else if (strcmp(inp,"2.3")==0) return 68;
    else if (strcmp(inp,"2.0")==0) return 65;
    else if (strcmp(inp,"1.7")==0) return 60;
    else if (strcmp(inp,"0")==0) return 50;
}
int s(char inp[]){
    if (strcmp(inp,"90-100")==0) return 95;
    else if (strcmp(inp,"85-89")==0) return 87;
    else if (strcmp(inp,"80-84")==0) return 82;
    else if (strcmp(inp,"77-79")==0) return 78;
    else if (strcmp(inp,"73-76")==0) return 75;
    else if (strcmp(inp,"70-72")==0) return 70;
    else if (strcmp(inp,"67-69")==0) return 68;
    else if (strcmp(inp,"63-66")==0) return 65;
    else if (strcmp(inp,"60-62")==0) return 60;
    else if (strcmp(inp,"59以下")==0) return 50;
}

void bubble_sort(int avg[],int id[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (avg[j] < avg[i]) {
        int t_id=id[j];
        id[j]=id[i];
        id[i]=t_id;
        int temp = avg[j];
        avg[j] = avg[i];
        avg[i] = temp;
      }
    }
  }
}

int main(){
    int m,n,count=0,id[50],avg[50];
    float score[50];
    char type[50][4];
    for (int i=0;i<50;i++) score[i] = 0;
    scanf("%d",&m);
    for (int i=0;i<m;i++){
        scanf("%s",&type[i]);
        count+=1;
    }
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&id[i]);
        for (int j=0;j<m;j++){
            char inp[7];
            scanf(" %s",&inp);
            if (strcmp(type[j],"G") == 0) score[i] += g(inp);
            else if (strcmp(type[j],"GPA") == 0) score[i] += gpa(inp);
            else if (strcmp(type[j],"S") == 0) score[i] += s(inp);
        }
        score[i] /= m;
        avg[i] = (int)(score[i]+0.5);

    }
    bubble_sort(avg,id,n);
    printf("%d\n",id[0]);
    printf("%d\n",avg[0]);
    printf("%d\n",id[1]);
    printf("%d\n",avg[1]);
    printf("%d\n",id[2]);
    printf("%d\n",avg[2]);

    return 0;
}

// ********：必須使用enum定義不同評分制資料型別，使用union定義分數資料型別。***********
// 一個班級有N位同學(ID)，M門課，每一門課可以設定評分方式。
// 設定M門課評分制，輸入N位同學M門課成績，根據下表換算，計算每一位同學百分制對照平均成績，
// 印出前三名ID與平均成績，四捨五入到整數。

// 等第 GPA 百分制區間 百分制對照
// A+ 4.3 90-100 95
// A 4.0 85-89 87
// A- 3.7 80-84 82
// B+ 3.3 77-79 78
// B 3.0 73-76 75
// B- 2.7 70-72 70
// C+ 2.3 67-69 68
// C 2.0 63-66 65
// C- 1.7 60-62 60
// F 0 59以下 50



// 先輸入有幾門課 M ，並依序設定評分方式 等第 = G, GPA = GPA,百分制區間 = S
// 在輸入學生數量與學生學號、成績。

// 範例1.
// Input:
// 2
// G
// GPA
// 5
// 10801
// A+
// 4.3
// 10802
// B+
// 4.0
// 10803
// B-
// 3.3
// 10804
// C
// 2.3
// 10805
// F
// 0
// Ouput:
// 10801
// 95
// 10802
// 83
// 10803
// 74

// 範例2.

// Input:
// 2
// G
// S
// 5
// 10801
// F
// 59以下
// 10802
// C
// 63-66
// 10803
// B
// 73-76
// 10804
// A
// 85-89
// 10805
// A+
// 90-100

// Output:
// 10805
// 95
// 10804
// 87
// 10803
// 75

