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
/**************************************************/   /*宣告變數*/ 
	int password=0,n; 
	char userinput; 
	
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

if(n==3)
{
	printf("已錯誤3次，程式結束\a");
	system("pause");
    return 0;
}
/**************************************************/     /*第二題*/	

    printf(" ---------------------------\n");             
	printf("|    a.畫出直角三角形       |\n");
    printf("|    b.顯示乘法表           |\n");
	printf("|    c.結束                 |\n");
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
    printf("請輸入一個a~n的字元");
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
		 
            printf("無效輸入，請重新輸入");
            flush(stdin);
        }
    }
} 


