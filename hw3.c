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
	
	printf("�o�OE5A60���ĤT���{���@�~\n");                                        
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("�п�J�K�X(�K�X��2025):");  
    scanf("%d", &password);    // Input password

	// Password attempts (n=1,2,3; exit on n=4)
	for (n=1;n<=3;n++) { 
		system("cls");
		if(password==2025) {    // Password check
			printf("��J���T�A�w��!!\n");
			system("pause");
			system("cls");
			break;
		}
		else {
			printf("�K�X���~(�w���~%d��)�A�Э��s��J�K�X(�K�X��2025):",n);  
			scanf("%d", &password);  	 
		}
	} 

	if(n==4) {   // Password failed 3 times, exit program
		printf("�w���~3���A�{������\a");   
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

	printf("�п�J�n�w�����y���(1~4): ");
	scanf("%d", &sitnumber);

	if (sitnumber < 1 || sitnumber > 4) {
		printf("��J���~�A�п�J 1~4 ���Ʀr�C\n");
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

	printf("��ĳ�y��p�U�]@����ĳ�y��^�G\n");  // Show suggestion
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%c ", seats[i][j]);
		}
		printf("\n");
	}

	if (!found) {
		printf("�ثe�䤣��ŦX�ݨD���s��y��C\n");
		system("pause");
		return;
	}

	printf("�O�_�������w�ơH(y/n): ");
	scanf(" %c", &confirm);

	if (confirm == 'y' || confirm == 'Y') {
		// Change @ to *
		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				if (seats[i][j] == '@')
					seats[i][j] = '*';
		printf("�w�������I\n");
	} else {
		// Cancel reservation
		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				if (seats[i][j] == '@')
					seats[i][j] = '-';
		printf("�w���������w�ơA��^�D���C\n");
	}

	system("pause");
}

/*********************************************************************/  // Manual seat selection
void casec(char seats[SIZE][SIZE]) {
	int row, col;
	printf("�п�J�n�w�����y��]�Ҧp�G3 4 ��ܲ�3�Ʋ�4�Ӯy��^: ");
	scanf("%d %d", &row, &col);  // Input row and column
	row--; col--;  // Adjust for 0-indexing

	if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {  // Valid input range
		if (seats[row][col] == '-') {  // If not reserved
			seats[row][col] = '*';
			printf("�y�� %d��%d�� �w�����\\n", row + 1, col + 1);
		} else {
			printf("�o�Ӯy��w�Q�w���I\n");
		}
	} else {
		printf("��J���y��W�X�d��A�Э��s��J�C\n");
	}
	system("pause");
}

/*********************************************************************/  // Exit confirmation (Task 5)
void cased(void)
{
	printf("Continue?(y/n):");
	fflush(stdin);  // Clear input buffer
}

