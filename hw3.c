#include <stdio.h>                            //各種標頭檔的宣告 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define SIZE 9
#define ROWS 9
#define COLS 9

void randnsit(char seats[ROWS][COLS]);
void casebegin(void);
void casea(char seats[SIZE][SIZE]);
void caseb(char seats[SIZE][SIZE]);
void casec(char seats[SIZE][SIZE]);
void cased(void);

int main(void)
{
	int password=0,n,row, col,i, j; 
	char userinput,y;
	char seats[SIZE][SIZE];
/*********************************************************************/ 	
	
	printf("這是E5A60的第三份程式作業\n");                                        //個人封面(題目1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("請輸入密碼(密碼為2025):");  
    scanf("%d", &password);           //輸入密碼 

for (n=1;n<=2;n++)                       //錯誤3次會跳離 
    { 
    system("cls");
		if(password==2025)               //密碼審核 
           {
		   printf("輸入正確，歡迎!!\n");
		   system("pause");
           system("cls");
           break;
		   }
        else
           {
          printf("密碼錯誤(已錯誤%d次)，請重新輸入密碼(密碼為2025):",n);  
          scanf("%d", &password);  	 
           }
	} 

if(n==4)
{
 printf("已錯誤3次，程式結束\a");
 system("pause");
 return 0;
}

/*********************************************************************/       //把座位都設成'-'(初始化)
for (i = 0; i < SIZE; i++)
        for (j = 0; j < SIZE; j++)
            seats[i][j] = '-';	


randnsit(seats);	                                       
  

while(1){
	
                casebegin(); 
                userinput=getch();
                
				if (userinput == 'A' || userinput == 'a') 
				{
                casea(seats);
                system("pause");
                }
                if (userinput == 'B' || userinput == 'b') 
				{
                caseb(seats);
                getch();
				}
                if (userinput == 'C' || userinput == 'c') 
				{
                casec(seats);
				} 
                if (userinput == 'D' || userinput == 'd') 
				{
                cased();
                scanf("%c",&y);
				}
                if (y == 'Y' || y == 'y') 
				{ 
	            system("pause"); 
                return 0; 
				} 
                    
                   
        }	
	

} 
/*********************************************************************/    //產生10個隨機座位
void randnsit(char seats[ROWS][COLS]) {
    int count = 0;
    srand(time(NULL));
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] != '*') {
            seats[r][c] = '*';
            count++;
        }
    }
}

/*********************************************************************/       //主選單  
void casebegin(void)
{
	system("cls");
    printf(" ---------------------------\n");             
	printf("|    a.Available seats       |\n");
    printf("|    b.Arrange for you       |\n");
	printf("|    c.Choose by yourself    |\n");
	printf("|    d. Exit                 |\n");
	printf(" ---------------------------\n\n"); 
return;
}

void casea(char seats[SIZE][SIZE]) {
    
	int i,j;
	for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }
}


void caseb(char seats[SIZE][SIZE]) {
    
	int i,j;
	for ( i = 0; i < SIZE; i++) {
        for ( j = 0; j < SIZE; j++) {
            if (seats[i][j] == '-') {
                seats[i][j] = '*';
                printf("為您安排的座位為：%d排 %d號\n", i + 1, j + 1);
                return;
            }
        }
    }
    printf("目前無空位可預約！\n");
}

void casec(char seats[SIZE][SIZE]) {
    int row, col;
    printf("請輸入要預約的座位（例如：3 4 表示第3排第4個座位）: ");
    scanf("%d %d", &row, &col);
    row--; col--;  // 使用者從1開始，但陣列從0開始

    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            printf("座位 %d排%d號 預約成功\n",row+1,col+1);
        } else {
            printf("這個座位已被預約！\n");
        }
    } else {
        printf("輸入的座位超出範圍，請重新輸入。\n");
    }
    system("pause");
}

void cased(void)                           //題目5 
{
 
 printf("Continue?(y/n):");
 fflush(stdin);  
   
}

