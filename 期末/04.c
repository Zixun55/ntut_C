#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int winner(int player[][200],int n,int no){
    int c;
    for (int i=0;i<n;i++){
        c=0;
        for (int j=0;j<n;j++){
            if (player[i][j] == -1)c+=1;
        }
        if (c == n) return no;
    }
    for (int i=0;i<n;i++){
        c=0;
        for (int j=0;j<n;j++){
            if (player[j][i] == -1)c+=1;
        }
        if (c == n) return no;
    }
    for (int i=0;i<n;i++){
        c=0;
        if (player[i][i] == -1)c+=1;
    }
    if (c == n) return no;
    for (int i=0;i<n;i++){
        c=0;
        if (player[i][n-i-2] == -1)c+=1;
    } 
    if (c == n) return no;
    else return 0;
}
int main(){
    int m,n,i_m[200],player0[200][200],player1[200][200],win=0,p0[200][200],p1[200][200],check=0;
    char a;
    scanf("%d, %d",&m,&n);
    for (int i=0;i<m;i++) scanf("%d%c",&i_m[i],&a);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d%c",&player0[i][j],&a);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d%c",&player1[i][j],&a);
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                p0[j][k] = player0[j][k];
                p1[j][k] = player1[j][k];
            }
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            for (int k=0;k<n;k++){
                if (player0[j][k] == i_m[i]){
                    win += winner(player0,n,1);
                    player0[j][k] = -1;
                }
                if (player1[j][k] == i_m[i]){
                    win += winner(player1,n,2);
                    player1[j][k] = -1;
                }
                if(win == 1 || win == 2){
                    check = -1;
                    break;
                }
                if (win == 3){
                    check = -1;
                    break;
                }
                else win=0;
            }
            if(check == -1) break;
        }
        if(check == -1) break;
    }
    
    
    if (win == 0 || win == 3) printf("Tie");
    else if (win == 1){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                printf("%d ",p0[i][j]);
            }
            printf("\n");
        }
    }
    else if (win == 2){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                printf("%d ",p1[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}