#include <stdio.h>                            //�U�ؼ��Y�ɪ��ŧi 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void casebegin(void);                           //�U�ب禡���ŧi 
void casea(void);
void caseb(void);
void casec(void);
char y;


int main(void)
{ 
/**************************************************/   /*�ŧi�ܼ�*/ 
	int password=0,n; 
	char userinput,y; 
	
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
                    ; 
                    }
                if (userinput == 'C' || userinput == 'c') {
                    casec();
                    scanf("%c",&y);
                if (y == 'N' || y == 'n') { 
	            system("pause"); 
                return 0; } 
                    
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

void casea(void)                          //�D��3 
{
    char input2;
    system("cls");    
    while (1) 
    {
        printf("�п�J�@��a~n���r���G");
        
        fflush(stdin);  // �M�Žw�İ�
        scanf("%c", &input2);

        if (input2 >= 'a' && input2 <= 'n')
        {
            int i, j, n = 97;  // n �O 'a' �� ASCII ��

            
            for (i = n; input2 >= i; i++) 
            {
                
                for (j = 0; j < (input2 - i); j++) 
                {
                    printf(" "); 
                }

               
                for (j = 97+input2-i ; j <=input2 ;j++ ) 
                {
                     printf("%c",j);
                  
				}
                
                printf("\n"); 
            }
            break;  
        }
        else 
        {
            printf("�L�Ŀ�J�A�Э��s��J�C\n");
            system("cls"); 
            fflush(stdin);  
        }
    }
    system("pause"); 
}








void caseb(void) {                          //�D��4 

    int input3, i, j;
    system("cls");
    while (1) {    
        printf("�п�J�@��1~9���Ʀr: ");
        fflush(stdin);  
        scanf("%d", &input3);
        
        if (input3 >= 1 && input3 <= 9) {
            printf("\n���k��G\n");

            
            for (i = 1; i <= input3; i++)  /* �~�h�j�� */
            {
               for (j = 1; j <= input3; j++)  /* ���h�j�� */
               {
               printf("%d*%d=%2d ", i, j, i * j);
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

void casec(void)                           //�D��5 
{
 
 printf("Continue?(y/n):");
 fflush(stdin);  
   
}
