#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void casebegin(void);
void casea(void);
void caseb(void);
void casec(void);



int main(void)
{ 
/**************************************************/   /*�ŧi�ܼ�*/ 
	int password=0,n; 
	char userinput; 
	
/**************************************************/ 	
	printf("�o�OE5A60���ĤG���{���@�~\n");                                        //�ӤH�ʭ�(�D��1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");    
    
    
/**************************************************/     /*�Ĥ@�D*/	
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
    return 0;
}
/**************************************************/     /*�ĤG�D*/	

while(1){
    casebegin(); 
    userinput=getch();
                if (userinput == 'A' || userinput == 'a') {
                casea();
                     
                    }
                if (userinput == 'B' || userinput == 'b') {
                    caseb();
                    getch(); 
                    }
                if (userinput == 'C' || userinput == 'c') {
                    casec();
                    getch(); 
                    break;  
                     } 
    

}
}	

void casebegin(void)
{
	system("cls");
    printf(" ---------------------------\n");             
	printf("|    a.�e�X�����T����       |\n");
    printf("|    b.��ܭ��k��           |\n");
	printf("|    c.����                 |\n");
	printf(" ---------------------------\n\n"); 
return;
} 

void casea(void)
{
    char input2;
    system("cls");    
    while (1) 
    {
        printf("�п�J�@��a~n���r���G");
        
        fflush(stdin);  
        scanf("%c", &input2);

        if (input2 >= 'a' && input2 <= 'n')
        {
            int i, j, n = 97;  

            
            for (i = (int)input2; i >= n; i--) 
            {
            printf(" ");  
                for (j = n; j <= (int)input2 ; j++) 
                {
                	if(j!=(int)input2){printf(" "); 
					}
                    else
					{
					 printf("%c",input2) ;
					 } 
                }
                
                
                printf("\n");
            }
            break;
        }
        else 
        {
            printf("�L�Ŀ�J�A�Э��s��J�C\n");
            fflush(stdin); 
        }
    }
    system("pause");
}






void caseb(void) {

    int input3, i, j;

    while (1) {    
        printf("�п�J�@��1~9���Ʀr: ");
        fflush(stdin);  
        scanf("%d", &input3);
        
        if (input3 >= 1 && input3 <= 9) {
            printf("\n���k��G\n");

            
            for (i = 1; i <= input3; i++) {           /*���ͭ��k��A�q 1 �� input3*/ 
                for (j = 1; j <= input3; j++) {
                    printf("%2d ", i * j);  
                }
                printf("\n");  
            }
            break; 
        } else {
            printf("��J���b1~9�����A�Э��s��J�C\n");
            fflush(stdin);  
        }
    }
}

void casec(void)
{
 char y;
 printf("Continue?(y/n):");
 scanf("%c",&y);
  if (y == 'Y' || y == 'y') { 
    casebegin();} 
  if (y == 'N' || y == 'n') { 
    system("pause");
	return; } 
}
