#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void casea(void);
void caseb(void);
void casec(void);
void cased(void);


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

if(n==3)
{
	printf("�w���~3���A�{������\a");
	system("pause");
    return 0;
}
/**************************************************/     /*�ĤG�D*/	

    printf(" ---------------------------\n");             
	printf("|    a.�e�X�����T����       |\n");
    printf("|    b.��ܭ��k��           |\n");
	printf("|    c.����                 |\n");
	printf(" ---------------------------\n\n");

while(1){

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
                    }
				if (userinput == 'D' || userinput == 'd') {
                    cased();
                    getch();
					break; 
                     } 
    

}
}	

 



void casea(void)
{
char input2;
system("cls");	
while (1) 
    {
    printf("�п�J�@��a~n���r��");
    fflush(stdin);
    scanf("%c", &input2);

        if( input2>= 'a' && input2<= 'n')
		{
        int i,j,n=97;
	            for(i=(int)input2;n<=i;i--)
				{
                   for(j=97;j<=i;j++)
                    printf("%c",j);
                    printf("\n");
				}
        break;
		}
         else 
		{
		 
            printf("�L�Ŀ�J�A�Э��s��J");
            flush(stdin);
        }
    }
} 


