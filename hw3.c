#include <stdio.h>                            //各種標頭檔的宣告 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int main(void)
{
	int password=0,n; 
	char userinput,y;
	
/*********************************************************************/ 	
	
	printf("這是E5A60的第二份程式作業\n");                                        //個人封面(題目1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("請輸入密碼(密碼為2025):");  
    scanf("%d", &password);           //輸入密碼 

for (n=1;n<=2;n++)                       //錯誤3次會跳離 
    { 
    system("cls");
		if(password==2025)               //密碼審核 
           {
		   printf("輸入正確，歡迎!!\n");
		   system("pause");
           system("cls");
           break;
		   }
        else
           {
          printf("密碼錯誤(已錯誤%d次)，請重新輸入密碼(密碼為2025):",n);  
          scanf("%d", &password);  	 
           }
	} 

if(n==4)
{
	printf("已錯誤3次，程式結束\a");
	system("pause");
    return 0;}
	
/*********************************************************************/       //主選單  

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
