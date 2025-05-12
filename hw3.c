#include <stdio.h>        // Header file declarations 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define SIZE 9            // Define array size 
#define ROWS 9
#define COLS 9

// Function declarations for corresponding tasks
void randnsit(char seats[ROWS][COLS]);
void casebegin(void);
void casea(char seats[SIZE][SIZE]);
void caseb(char seats[SIZE][SIZE]);
void casec(char seats[SIZE][SIZE]);
void cased(void);

int main(void)
{
	int password=0,n,row, col,i, j;     // Variable declarations
	char userinput,y;
	char seats[SIZE][SIZE];

/*********************************************************************/ 	// Title display (Task 1)
	
	printf("這是E5A60的第三份程式作業\n");                                        
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

/*********************************************************************/  // Initialize all seats to '-'
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			seats[i][j] = '-';

	randnsit(seats);  // Randomly assign 10 occupied seats

	while(1) {   // Main menu: a, b, c, d choices
		casebegin(); 
		userinput=getch();
		
		if (userinput == 'A' || userinput == 'a') {
			casea(seats);     // Display seat map
			system("pause");
		}
		if (userinput == 'B' || userinput == 'b') {
			caseb(seats);     // System assigns seat
		}
		if (userinput == 'C' || userinput == 'c') {
			casec(seats);     // User chooses seat
		} 
		if (userinput == 'D' || userinput == 'd') {
			cased();          // Confirm exit
			scanf("%c",&y);
		}
		if (y == 'Y' || y == 'y') { 
			system("pause"); 
			return 0; 
		}    
	}
} 

/*********************************************************************/  // Function to generate 10 random seats
void randnsit(char seats[ROWS][COLS]) {
	int count = 0;
	srand(time(NULL));  // Random seed
	while (count < 10) {
		int r = rand() % ROWS;
		int c = rand() % COLS;
		if (seats[r][c] != '*') {
			seats[r][c] = '*';
			count++;
		}
	}
}

/*********************************************************************/  // Main menu display
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

/*********************************************************************/  // Display seat map
void casea(char seats[SIZE][SIZE]) {
	int i,j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%c ", seats[i][j]);
		}
		printf("\n");
	}
}

/*********************************************************************/  // Auto-arrange seats based on user input
void caseb(char seats[SIZE][SIZE]) {
	int sitnumber, i, j, k, found = 0, attempt, row, col, confirm;

	printf("請輸入要預約的座位數(1~4): ");
	scanf("%d", &sitnumber);

	if (sitnumber < 1 || sitnumber > 4) {
		printf("輸入錯誤，請輸入 1~4 的數字。\n");
		system("pause");
		return;
	}

	srand(time(NULL));  // Random seed

	// 1~3 seats: find consecutive seats in a row
	if (sitnumber >= 1 && sitnumber <= 3) {
		for (attempt = 0; attempt < 20 && !found; attempt++) { 
			row = rand() % SIZE;
			for (j = 0; j <= SIZE - sitnumber; j++) {
				int available = 1;
				for (k = 0; k < sitnumber; k++) {
					if (seats[row][j + k] != '-') {
						available = 0;
						break;
					}
				}
				if (available) {
					for (k = 0; k < sitnumber; k++) {
						seats[row][j + k] = '@';  // Suggestion mark
					}
					found = 1;
					break;
				}
			}
		}
	}
	// 4 seats: find 4 in a row
	else if (sitnumber == 4) { 
		for (attempt = 0; attempt < 30 && !found; attempt++) {
			row = rand() % SIZE;
			for (col = 0; col <= SIZE - 4; col++) {
				if (seats[row][col] == '-' && seats[row][col + 1] == '-' &&
					seats[row][col + 2] == '-' && seats[row][col + 3] == '-') {
					seats[row][col] = seats[row][col + 1] = seats[row][col + 2] = seats[row][col + 3] = '@';
					found = 1;
					break;
				}
			}
		}
	}

	printf("建議座位如下（@為建議座位）：\n");  // Show suggestion
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%c ", seats[i][j]);
		}
		printf("\n");
	}

	if (!found) {
		printf("目前找不到符合需求的連續座位。\n");
		system("pause");
		return;
	}

	printf("是否接受此安排？(y/n): ");
	scanf(" %c", &confirm);

	if (confirm == 'y' || confirm == 'Y') {
		// Change @ to *
		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				if (seats[i][j] == '@')
					seats[i][j] = '*';
		printf("預約完成！\n");
	} else {
		// Cancel reservation
		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				if (seats[i][j] == '@')
					seats[i][j] = '-';
		printf("已取消此次安排，返回主選單。\n");
	}

	system("pause");
}

/*********************************************************************/  // Manual seat selection
void casec(char seats[SIZE][SIZE]) {
	int row, col;
	printf("請輸入要預約的座位（例如：3 4 表示第3排第4個座位）: ");
	scanf("%d %d", &row, &col);  // Input row and column
	row--; col--;  // Adjust for 0-indexing

	if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {  // Valid input range
		if (seats[row][col] == '-') {  // If not reserved
			seats[row][col] = '*';
			printf("座位 %d排%d號 預約成功\n", row + 1, col + 1);
		} else {
			printf("這個座位已被預約！\n");
		}
	} else {
		printf("輸入的座位超出範圍，請重新輸入。\n");
	}
	system("pause");
}

/*********************************************************************/  // Exit confirmation (Task 5)
void cased(void)
{
	printf("Continue?(y/n):");
	fflush(stdin);  // Clear input buffer
}

