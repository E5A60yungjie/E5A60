#include <stdio.h>   // 包含標頭檔 
#include <stdlib.h>  
int password=0,n;    //定義變數 
char input;

int main(void)
{
	
	printf("這是E5A60的第一份程式作業\n");                                        //個人封面(題目1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");    
    
       printf("請輸入密碼(2024):");  
       scanf("%d", &password);           //輸入密碼 
       
        if(password==2024)               //密碼審核 
           {
		   printf("輸入正確，歡迎!!\n");
		   system("pause");
           system("cls");
		   }
        else
		   {
        	printf("輸入錯誤");
		    return 0; 
		    
		   }   
	
	printf("------------------------------\n");             //主選單(題目3) 
	printf("|  ‘A’...‘Z’ : Uppercase     |\n");
    printf("|  ‘a’...‘z’ : Lowercase     |\n");
	printf("|  ‘0’...‘9’ : Digit         |\n");
	printf("|   Otherwise : Your name    |\n");
	printf("------------------------------\n\n");
	
	printf("請使用者輸入 1 個字元:");                        //題目4 
	getchar();                                             
               scanf("%c",&input);                 
	             if (input >= 'A' && input <= 'Z') {         
                printf("Uppercase");}
                 else if (input >= 'a' && input <= 'z') {
                printf("Lowercase");}
                 else if (input >= '0' && input <= '9') {
                printf("Digit ");}
                 else{ printf("E5A60彭永傑");}
             
                

}
