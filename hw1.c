#include <stdio.h>   // �]�t���Y�� 
#include <stdlib.h>  
int password=0,n;    //�w�q�ܼ� 
char input;

int main(void)
{
	
	printf("�o�OE5A60���Ĥ@���{���@�~\n");                                        //�ӤH�ʭ�(�D��1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");    
    
       printf("�п�J�K�X(2024):");  
       scanf("%d", &password);           //��J�K�X 
       
        if(password==2024)               //�K�X�f�� 
           {
		   printf("��J���T�A�w��!!\n");
		   system("pause");
           system("cls");
		   }
        else
		   {
        	printf("��J���~");
		    return 0; 
		    
		   }   
	
	printf("------------------------------\n");             //�D���(�D��3) 
	printf("|  ��A��...��Z�� : Uppercase     |\n");
    printf("|  ��a��...��z�� : Lowercase     |\n");
	printf("|  ��0��...��9�� : Digit         |\n");
	printf("|   Otherwise : Your name    |\n");
	printf("------------------------------\n\n");
	
	printf("�ШϥΪ̿�J 1 �Ӧr��:");                        //�D��4 
	getchar();                                             
               scanf("%c",&input);                 
	             if (input >= 'A' && input <= 'Z') {         
                printf("Uppercase");}
                 else if (input >= 'a' && input <= 'z') {
                printf("Lowercase");}
                 else if (input >= '0' && input <= '9') {
                printf("Digit ");}
                 else{ printf("E5A60�^�ó�");}
             
                

}
