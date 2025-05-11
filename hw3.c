#include <stdio.h>                            //各種標頭檔的宣告 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define SIZE 9

#define ROWS 9
#define COLS 9

int main(void)
{
	int password=0,n,row, col; 
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
    return 0;}
	
randnsit(seats);	
/*********************************************************************/       //主選單  

while(1){
	
                casebegin(); 
                userinput=getch();
                
				if (userinput == 'A' || userinput == 'a') 
				{
                casea();
                }
                if (userinput == 'B' || userinput == 'b') 
				{
                caseb();
                getch();
				}
                if (userinput == 'C' || userinput == 'c') 
				{
                casec();
				} 
                if (userinput == 'D' || userinput == 'd') 
				{
                cased();
                scanf("%c",&y);
				}
                if (y == 'N' || y == 'n') 
				{ 
	            system("pause"); 
                return 0; 
				} 
                    
                   
        }	
	

} 
/*********************************************************************/    //產生10個隨機座位
void randnsit(char seats[ROWS][COLS]) {
	
	int sitbegin = 0;
	
	for(sitbegin=0;sitbegin<10;sitbegin++ ) 
    {   
     
	    int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] != '*') {
            seats[r][c] = '*';
            
        }
    }    
} 
void casebegin(void)
{
	system("cls");
    printf(" ---------------------------\n");             
	printf("|    a.Available seats       |\n");
    printf("|    b.Arrange for you           |\n");
	printf("|    c.Choose by yourself          |\n");
	printf("|    d. Exit                 |\n");
	printf(" ---------------------------\n\n"); 
return;
}

void casea(char seats[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", seats[i][j]);
        }
        printf("\n");
    }
}


void caseb(char seats[SIZE][SIZE], int row, int col) {
    if (seats[row][col] == '-') {
        seats[row][col] = '*';
        printf("座位 %d, %d 預約成功！\n", row + 1, col + 1);
    } else {
        printf("這個座位已被預約！\n");
    }
}





