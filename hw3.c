#include <stdio.h>                            //�U�ؼ��Y�ɪ��ŧi 
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
	
	printf("�o�OE5A60���ĤT���{���@�~\n");                                        //�ӤH�ʭ�(�D��1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("�п�J�K�X(�K�X��2025):");  
    scanf("%d", &password);           //��J�K�X 

for (n=1;n<=2;n++)                       //���~3���|���� 
    { 
    system("cls");
		if(password==2025)               //�K�X�f�� 
           {
		   printf("��J���T�A�w��!!\n");
		   system("pause");
           system("cls");
           break;
		   }
        else
           {
          printf("�K�X���~(�w���~%d��)�A�Э��s��J�K�X(�K�X��2025):",n);  
          scanf("%d", &password);  	 
           }
	} 

if(n==4)
{
	printf("�w���~3���A�{������\a");
	system("pause");
    return 0;}
	
randnsit(seats);	
/*********************************************************************/       //�D���  

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
/*********************************************************************/    //����10���H���y��
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
        printf("�y�� %d, %d �w�����\�I\n", row + 1, col + 1);
    } else {
        printf("�o�Ӯy��w�Q�w���I\n");
    }
}





