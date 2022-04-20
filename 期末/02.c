#include<stdio.h>
int swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int per(int *str,int begin,int end,int e[][200],int l_ans[],int s_ans[],int l_path[][200],int s_path[][200],int l[],int s[]){
    if(begin == end){
        int node=1,next=str[1],store=0,path_store[200];
        for (int i=0;i<=end;i++){
            //printf("%d",str[i]);
            store+=e[node-1][next-1];
            path_store[i] = node;
            node=next;
            next=str[i+2];
            
        }
        //printf("\n");
        if (store<s_ans[0]){
            s_ans[0]=store;
            for(int i=0;i<=end;i++) s_path[s[0]][i] = path_store[i];
            if (s[0] == 0) s[0]+=1;
        }
        else if (store>l_ans[0]){
            l_ans[0]=store;
            for(int i=0;i<=end;i++) l_path[l[0]][i] = path_store[i];
            if (l[0] == 0) l[0]+=1;
        }
        else if (store==s_ans[0]){
            s_ans[0]=store;
            for(int i=0;i<=end;i++) s_path[s[0]][i] = path_store[i];
            s[0]+=1;
        }
        else if (store==l_ans[0]){
            l_ans[0]=store;
            for(int i=0;i<=end;i++) l_path[l[0]][i] = path_store[i];
            l[0]+=1;
        }
    }
    else{
        for (int i=begin;i<=end;i++){
            swap(&str[i],&str[begin]);
            per(str,begin+1,end,e,l_ans,s_ans,l_path,s_path,l,s);
            swap(&str[i],&str[begin]);
        }
    }
}
int main(){
    int n,e[200][200],tmp[200],l_ans[1]={0},s_ans[1]={5000},l_path[200][200],s_path[200][200],l[1]={0},s[1]={0};
    int a;
    char b;
    scanf("%d",&n);
    for (int i=0;i<=n;i++){
        if (i==0) scanf("%d%c",&a,&b);
        else scanf("%d%c",&tmp[i-1],&b);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<=n;j++){
            if (j==0) scanf("%d%c",&a,&b);
            else scanf("%d%c",&e[i][j-1],&b);
        }
    }
    per(tmp,1,n-1,e,l_ans,s_ans,l_path,s_path,l,s);
    printf("%d\n",s_ans[0]);
    for(int i=0;i<s[0];i++){
        for (int j=0;j<n;j++){
            printf("%d",s_path[i][j]);
            if (j == (n-1)) printf("\n");
            else printf("->");
        }
    }
    printf("%d\n",l_ans[0]);
    for(int i=0;i<l[0];i++){
        for (int j=0;j<n;j++){
            printf("%d",l_path[i][j]);
            if (j == (n-1)) printf("\n");
            else printf("->");
        }
    }
    return 0;
}