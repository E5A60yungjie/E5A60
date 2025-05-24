#include <stdio.h>        // Header file declarations 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

void casebegin(void);

int main(void)
{
/*********************************************************************/ 	// 題目一 

	int password=0,n,row, col,i, j;     // Variable declarations
	char userinput,y;
	
	printf("這是E5A60的第四份程式作業\n");                                        
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("請輸入密碼(密碼為2025):");  
    scanf("%d", &password);    // Input password

	// Password attempts (n=1,2,3; exit on n=4)
	for (n=1;n<=3;n++) { 
		system("cls");
		if(password==2025) {    // Password check
			printf("輸入正確，歡迎!!\n");
			system("pause");
			system("cls");
			break;
		}
		else {
			printf("密碼錯誤(已錯誤%d次)，請重新輸入密碼(密碼為2025):",n);  
			scanf("%d", &password);  	 
		}
	} 

	if(n==4) {   // Password failed 3 times, exit program
		printf("已錯誤3次，程式結束\a");   
		system("pause");
		return 0;
	}
	
/*********************************************************************/


  casebegin(); 
} 














/*********************************************************************/  //題目二(主畫面) 

void casebegin(void)
{
	system("cls");
	printf(" -----------------------------------\n");             
	printf("|    a.Enter student grades         |\n");
	printf("|    b.Display student grades       |\n");
	printf("|    c.Search for student grades    |\n");
	printf("|    d.Grade ranking                |\n");
	printf("|    e.Exit system                  |\n");
	printf(" -----------------------------------\n"); 
	return;
}

/*********************************************************************/ 
