#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	int password=0,n; 
	
	printf("�o�OE5A60���ĤG���{���@�~\n");                                        //�ӤH�ʭ�(�D��1) 
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



}	
