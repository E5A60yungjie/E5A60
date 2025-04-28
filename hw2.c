#include <stdio.h>                            //各種標頭檔的宣告 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
void casebegin(void);                           //各種函式的宣告 
void casea(void);
void caseb(void);
void casec(void);
char y;


int main(void)
{ 
/**************************************************/   /*宣告變數*/ 
	int password=0,n; 
	char userinput,y; 
	
/**************************************************/ 	
	printf("這是E5A60的第二份程式作業\n");                                        //個人封面(題目1) 
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");    
    
    
/**************************************************/     /*第一題*/	
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
    return 0;
}
/**************************************************/     /*第二題*/	

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
	printf("|    a.畫出直角三角形       |\n");
    printf("|    b.顯示乘法表           |\n");
	printf("|    c.結束                 |\n");
	printf(" ---------------------------\n\n"); 
return;
} 

void casea(void)                          //題目3 
{
    char input2;
    system("cls");    
    while (1) 
    {
        printf("請輸入一個a~n的字元：");
        
        fflush(stdin);  // 清空緩衝區
        scanf("%c", &input2);

        if (input2 >= 'a' && input2 <= 'n')
        {
            int i, j, n = 97;  // n 是 'a' 的 ASCII 值

            
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
            printf("無效輸入，請重新輸入。\n");
            system("cls"); 
            fflush(stdin);  
        }
    }
    system("pause"); 
}








void caseb(void) {                          //題目4 

    int input3, i, j;
    system("cls");
    while (1) {    
        printf("請輸入一個1~9的數字: ");
        fflush(stdin);  
        scanf("%d", &input3);
        
        if (input3 >= 1 && input3 <= 9) {
            printf("\n乘法表：\n");

            
            for (i = 1; i <= input3; i++)  /* 外層迴圈 */
            {
               for (j = 1; j <= input3; j++)  /* 內層迴圈 */
               {
               printf("%d*%d=%2d ", i, j, i * j);
               }
            printf("\n");  
            }
            break; 
        } else {
            printf("輸入不在1~9之間，請重新輸入。\n");
            fflush(stdin);  
        }
    }
}

void casec(void)                           //題目5 
{
 
 printf("Continue?(y/n):");
 fflush(stdin);  
   
}
