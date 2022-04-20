#include<stdio.h>
#include <string.h>
void bubble_sort(int time_num[],char time_name[][1000], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (time_num[j] < time_num[i] || (time_num[j] == time_num[i] && strcmp(time_name[j],time_name[i]) >0 )) {
        char name_temp[1000];
        strcpy(name_temp,time_name[j]);
        strcpy(time_name[j],time_name[i]);
        strcpy(time_name[i],name_temp);
        int temp = time_num[j];
        time_num[j] = time_num[i];
        time_num[i] = temp;
      }
    }
  }
    for(int i = 0;i<n;i++){
        printf("%s : ",time_name[i]);
        printf("%d\n",time_num[i]);
    }
}
int main(void){
    char str[1000],p[500],q[500];
    scanf("%[^\n]",str);
    scanf("%s",&p);
    scanf("%s",&q);
    int l = strlen(str),l_p = strlen(p),l_q = strlen(q);
    //取代
    for (int i=0;i<l;i++){
        if (i==0){
            int time = 0;
            for (int j=0;j<l_p;j++){
                if (str[j] == p[j]) time+=1;
                if (str[j+1] == ' ' || str[j+1] == '\0') time+=1;
            }
            if (time == l_p+1){
                for (int j=0;j<l_q;j++) printf("%c",q[j]);
                i+=l_p;
                printf(" ");
            }
            else printf("%c",str[i]);
        }
        else if (str[i] == ' '){
            int time = 0;
            for (int j=0;j<l_p;j++){
                if (str[i+1+j] == p[j]) time+=1;
                if (str[i+j+2] == ' ' || str[i+j+2] == '\0') time+=1;
            }
            if (time == l_p+1){
                printf(" ");
                for (int j=0;j<l_q;j++) printf("%c",q[j]);
                i+=l_p;
            }
            else printf("%c",str[i]);
        }
        else printf("%c",str[i]);
    }printf("\n");
    //插入
    for (int i=0;i<l;i++){
        if (i==0){
            int time = 0;
            for (int j=0;j<l_p;j++){
                if (str[j] == p[j]) time+=1;
                if (str[j+1] == ' ' || str[j+1] == '\0') time+=1;
            }
            if (time == l_p+1){
                for (int j=0;j<l_q;j++) printf("%c",q[j]);
                printf(" %c",str[i]);
            }
            else printf("%c",str[i]);
        }
        else if (str[i] == ' '){
            int time = 0;
            for (int j=0;j<l_p;j++){
                if (str[i+1+j] == p[j]) time+=1;
                if (str[i+j+2] == ' ' || str[i+j+2] == '\0') time+=1;
            }
            if (time == l_p+1){
                printf(" ");
                for (int j=0;j<l_q;j++) printf("%c",q[j]);
                printf(" ");
            }
            else printf("%c",str[i]);
        }
        else printf("%c",str[i]);
    }printf("\n");
    //刪除
    for (int i=0;i<l;i++){
        if (i==0){
            int time = 0;
            for (int j=0;j<l_p;j++){
                if (str[j] == p[j]) time+=1;
                if (str[j+1] == ' ' || str[j+1] == '\0') time+=1;
            }
            if (time == l_p+1)  i+=l_p;
            else printf("%c",str[i]);
        }
        else if (str[i] == ' '){
            int time = 0;
            for (int j=0;j<l_p;j++){
                if (str[i+1+j] == p[j]) time+=1;
                if (str[i+j+2] == ' ' || str[i+j+2] == '\0') time+=1;
            }
            if (time == l_p+1)  i+=l_p;
            else printf("%c",str[i]);
        }
        else printf("%c",str[i]);
    }printf("\n");
    //計算次數和排序
    char word[1000][1000],time_name[1000][1000];
    char *delim =" ";
    char *pch;
    int i=0,m = 0,time_num[1000],same,time=0;
    pch = strtok(str,delim);
    while(pch!=NULL){             //切割      
        strcpy(word[i],pch);
        pch = strtok(NULL,delim);
        i++;
    }

    for (;m<i;m++){
        int k = 0;
        for(;k<i;k++){
            same = strcmp(word[k],"");
            if(same != 0){
                strcpy(time_name[m],word[k]);
                break;
            }
        }
        if (k == i)break;
        for(int l = 0;l<i;l++){
            same = strcmp(word[l],time_name[m]);
            if(same == 0){
                time++;
                strcpy(word[l],"");
            }
        }
        time_num[m] = time;
        time = 0;
    }
    bubble_sort(time_num,time_name,m);

}

// 輸入一篇英文文章 A，文章中英文字以一個空白間隔。另外輸入 2 個英文字(word) P、Q。
// (1) 將文章 A 中 P 字串以 Q 字串取代，並輸出。
// (2) 在文章 A 中 P 字串前插入 Q 字串，並輸出。
// (3) 將文章 A 中 P 字串刪除，並輸出。
// (4) 分析文章 A 所有英文字 (word) 的頻率，依頻率由大自小排序， 頻率相同則以 word由小自大排序(That > This....)輸出。

// ----------------
// 輸入說明 :
// 第一行，文章 A
// 第二行，英文字 P
// 第三行，英文字 Q
// ----------------
// 輸出說明 :
// 第一行，將文章 A 中的 P 字串以 Q 字串取代之結果
// 第二行，在文章 A 中的 P 字串前插入 Q 字串之結果
// 第三行，將文章 A 中的 P 字串刪除之結果
// 第四~n行，將文章 A 中所有的英文字出現的頻率統計出來，由頻率高到低排列，若頻率一樣則由字母小到大排列(大寫在小寫之前)，請用 : 隔開單字與頻率(冒號前後皆有空白)，一個單字與頻率一行

// -------------
// Sample Input:
// Can you can a can as a canner can can a can
// can
// ban
// -------------
// Sample Output:
// Can you ban a ban as a canner ban ban a ban
// Can you ban can a ban can as a canner ban can ban can a ban can
// Can you a as a canner a
// can : 5
// a : 3
// Can : 1
// as : 1
// canner : 1
// you : 1

// -------------
// Sample Input:
// Whether the weather be cold or whether the weather be hot
// the
// a
// -------------
// Sample Output:
// Whether a weather be cold or whether a weather be hot
// Whether a the weather be cold or whether a the weather be hot
// Whether weather be cold or whether weather be hot
// be : 2
// the : 2
// weather : 2
// Whether : 1
// cold : 1
// hot : 1
// or : 1
// whether : 1

