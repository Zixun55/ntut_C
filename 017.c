#include <stdio.h>
#include <string.h>
#include <math.h>
int ans[99][2];
int count=0;

void swap(char *x, char *y) {
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

void reverse(char *first, char *last) {
    --last;
    while (first < last) {
        swap(first, last);
        ++first;
        --last;
    }
}

void bubble_sort(int arr[][2], int n) {
	int i,j;
	int temp[2];
	for (i = 0; i < n; ++i) {
		for (j = 0; j < i; ++j) {
		  if (ans[j][0] > ans[i][0]) {
		    temp[0] = ans[j][0];
		    temp[1] = ans[j][1];
		    ans[j][0] = ans[i][0];
		    ans[j][1] = ans[i][1];
		    ans[i][0] = temp[0];
		    ans[i][1] = temp[1];
		  }
		  else if(ans[j][0] == ans[i][0] && ans[j][1] >ans[i][1])
		  {
		  	temp[0] = ans[j][0];
		    temp[1] = ans[j][1];
		    ans[j][0] = ans[i][0];
		    ans[j][1] = ans[i][1];
		    ans[i][0] = temp[0];
		    ans[i][1] = temp[1];
		  }
		}
	}
}

char* P(int size, char arr[], char arr2[])
{
	if(arr[0]=='0' || (int)strlen(arr)==0){
		return arr;
	}
	else if (arr[0] == '1'){
		if(size==1) {
			int x=0, y=0, i;
			reverse(&arr2[0],&arr2[strlen(arr2)]);
			for(i =0; i<(int)strlen(arr2)-1;i++){
				if(arr2[i]=='1'){
					x+=0*pow(2,i);
					y+=0*pow(2,i);
				}
				if(arr2[i]=='2'){
					x+=1*pow(2,i);
					y+=0*pow(2,i);
				}
				if(arr2[i]=='3'){
					x+=0*pow(2,i);
					y+=1*pow(2,i);
				}
				if(arr2[i]=='4'){
					x+=1*pow(2,i);
					y+=1*pow(2,i);
				}
			}
			ans[count][0]=y;
			ans[count++][1]=x;
			return arr;
		}
		else if(size>1){
			reverse(&arr[0],&arr[strlen(arr)]);
			strcat(arr,"1111");
			reverse(&arr[0],&arr[strlen(arr)]);
			char temp[99];
			strcpy(temp,arr2);
			strcat(temp,"1");
			arr = P(size/2,arr+1,temp);
			strcpy(temp,arr2);
			strcat(temp,"2");
			arr = P(size/2,arr+1,temp);
			strcpy(temp,arr2);
			strcat(temp,"3");
			arr = P(size/2,arr+1,temp);
			strcpy(temp,arr2);
			strcat(temp,"4");
			arr = P(size/2,arr+1,temp);
			return arr;
		}
	}
	else {
		char temp[99];
		strcpy(temp,arr2);
		strcat(temp,"1");
		arr = P(size/2,arr+1,temp);
		strcpy(temp,arr2);
		strcat(temp,"2");
		arr = P(size/2,arr+1,temp);
		strcpy(temp,arr2);
		strcat(temp,"3");
		arr = P(size/2,arr+1,temp);
		strcpy(temp,arr2);
		strcat(temp,"4");
		arr = P(size/2,arr+1,temp);
		return arr;
	}
}
void main(){
	char inp[99],arr[99]={'0'};
	int size;
	scanf("%s\n",&inp);
	scanf("%d",&size);
    P(size,inp,arr);
    int i;
    bubble_sort(ans, count);
    for (i=0;i<count;i++){
    	printf("%d,%d\n",ans[i][0],ans[i][1]);
	}
	if(count==0){
		printf("all white\n");
	}
}

// DF - expression是儲存圖片資訊的表達方式。
// 在一個n*n方陣中，若方格是白色記為0；黑色記為1；
// 若方格可分為更小方格(左上、右上、左下、右下)，則記2，再依序(左上→右上→左下→右下)記錄這四個方格的資訊。
// 以下圖為例 :
// 第一張圖全為白，所以輸出為0。
// 第二張圖全為黑，所以輸出為1。
// 第三張圖因為有黑有白，所以記為2，接著繼續切，從左上開始，全為白，記為0，再來右上，有黑有白繼續切，記為2，接著繼續從右上那塊往下做，從左上開始，全為白，記為0，再來右上(白)，記0，左下(黑)，記1，右下(白)，記0，接著回到外面那塊的左下(黑)，記1，再來右下(白)，記0。最後輸出為202001010。

// □□□□
// □□□□
// □□□□
// □□□□
// 0

// ■■■■
// ■■■■
// ■■■■
// ■■■■
// 1

// □□|□□
// □□|■□
// --------
// ■■|□□
// ■■|□□
// 202001010

// 輸入：給定DF - expression的輸入、這張圖像寬度(必為2的非負整數次方)
// 輸出：這張圖中黑色格子的座標位置(輸出座標順序由左而右、由上到下，最左上為0,0)，如無黑色格子則輸出all white。

// Sample Input
// 1
// 2

// Sample Output
// 0,0
// 0,1
// 1,0
// 1,1
// -------------------------------
// Sample Input
// 202001010
// 4

// Sample Output
// 1,2
// 2,0
// 2,1
// 3,0
// 3,1

