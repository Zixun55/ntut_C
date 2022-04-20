#include<stdio.h>
#include <string.h>
int main(void){
    int n,ans=0,l_voc=0,check[100][100];
    char str[100],s1[100],s2[100][100],input[100][100];
    char *delim =" ";
    char *pch;
    char *pch2;
    scanf("%[^\n]",str);
    scanf("%d",&n);
    pch = strtok(str,delim);
    while(pch!=NULL){                  
        strcpy(input[l_voc],pch);
        pch = strtok(NULL,delim);
        l_voc++;
    }
    for (int i=0;i<n;i++){
        scanf(" %[^\n]",s1);
        int a=0;
        pch2 = strtok(s1,delim);
        while(pch2!=NULL){                  
            strcpy(s2[a],pch2);
            pch2 = strtok(NULL,delim);
            a++;
        }
        for (int j=0;j<a;j++){
            for (int k=0;k<l_voc;k++){
                if (strcmp(s2[j],input[k]) == 0) check[i][k] = 1;
                else if (strcmp(s2[j],input[k]) != 0 && check[i][k]!=1)check[i][k] = 0;
            }
        }
    }
    for (int i=0;i<n-1;i++){
        for (int k=i;k<n;k++){
            int time=0;
            for (int j=0;j<l_voc;j++){
                if (check[i][j] ^ check[k][j] == 1) time+=1;
            }
            if (time == l_voc) ans+=1;
        }
        
    }
    printf("%d",ans);
}

// 互補字S1, S2的定義是字串S1, S2沒有重複出現的字，且字串S1, S2內的字需包含在字串S內的字。
// 此處，字串是英文字的一個集合，亦即，元素有重複只算一個，也不管排列情況。
// 例如"Happy Happy Day"與"Day Happy Day"是相同的字串。輸入n個字串，輸出這n個字串互補的個數。
// ----------------
// 輸入說明 :
// 第一行，字串S
// 第二行，輸入字串個數n
// 第三行，第一個字串
// 第四行，第二個字串
// ........
// ----------------
// 輸出說明 :
// 第一行，n個字串互補的個數
// -------------
// Sample Input:
// happy birthday to you
// 4
// happy to you
// birthday birthday
// to you
// happy birthday
// -------------
// Sample Output:
// 2

// -------------
// Sample Input:
// what are you doing
// 3
// what what are
// doing doing
// what are are you you
// -------------
// Sample Output:
// 1