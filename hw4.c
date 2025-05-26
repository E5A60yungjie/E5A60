#include <stdio.h>        //標頭檔
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_ID 10


typedef struct {                         //定義結構 
    char name[MAX_NAME];
    char id[MAX_ID];
    float math, physics, english;
    float average;
} Student;

void casebegin(void);                    //定義函數 主畫面到選項e 
void casea(void);
void caseb(void);
void casec(void);
void cased(void);
void casee(void);

Student students[MAX_STUDENTS];            
int student_count = 0;





int main(void)
{
	
/*********************************************************************/ 	// 題目一 

	int password=0,n,row, col,i, j;     // Variable declarations
	char userinput,y;
	
	printf("這是E5A60的第四份程式作業\n");                                        
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("請輸入密碼(密碼為2025):");      //輸入密碼 
    scanf("%d", &password);                //密碼存於password
	 

	
	for (n=1;n<=3;n++) {                                     //迴圈3次  檢查密碼  如果對貼上輸入正確，歡迎   如果錯要求重新輸入  3次後跳離迴圈 
		system("cls");
		if(password==2025) {    // Password check
			printf("輸入正確，歡迎!!\n");
			system("pause");
			system("cls");
			break;
		}
		else {
			printf("密碼錯誤(已錯誤%d次)，請重新輸入密碼(密碼為2025):",n);  
			scanf("%d", &password);  	 
		}
	} 

	if(n==4) {                                                  //3次迴圈後，偵測是否是第3次跳離迴圈，如果是結束程式 
		printf("已錯誤3次，程式結束\a");   
		system("pause");
		return 0;
	}
	
/*********************************************************************/

while(1) {                                                              //無限迴圈，輸入a,b,c,d,e分別對應各函數 case a~e 
		casebegin(); 
		userinput=getch();
		
		if (userinput == 'A' || userinput == 'a') {
			casea();     
		}
		if (userinput == 'B' || userinput == 'b') {
			caseb();     
		}
		if (userinput == 'C' || userinput == 'c') {
			casec();     
		} 
		if (userinput == 'D' || userinput == 'd') {
			cased();          
		}
		if (userinput == 'E' || userinput == 'e') {
			casee();          
			scanf("%c",&y);
		if (y == 'Y' || y == 'y') { 
			system("pause"); 
			return 0; 
		}    
	}
} 

 
} 




/*********************************************************************/  //題目二(主畫面) 

void casebegin(void)
{
	system("cls");
	printf(" -----------------------------------\n");             
	printf("|    a.Enter student grades         |\n");
	printf("|    b.Display student grades       |\n");
	printf("|    c.Search for student grades    |\n");
	printf("|    d.Grade ranking                |\n");
	printf("|    e.Exit system                  |\n");
	printf(" -----------------------------------\n"); 
	return;
}

/*********************************************************************/       //題目三(選項a)  



void casea() {
    system("cls");
    int n, i, j, valid;                                  
    printf("請輸入學生人數（5~10）：");          
    while (1) {                     
        scanf("%d", &n);                                         //學生人數存於變數n，且偵測學生人數要在5~10以內，如果不再這個範圍要求重新輸入 
        if (n >= 5 && n <= 10) break;
        printf("錯誤：人數需為 5~10，請重新輸入：");
    }

    for (i = 0; i < n; i++) {                                            
        printf("\n第 %d 位學生：\n", i + 1);                      
        printf("姓名：");
        scanf("%s", students[student_count].name);                    //i會隨著回圈增加 0,1,2,3...  輸入學生1,2,3...的名子  
        while (1) {
            printf("學號（6 位數字）：");
            scanf("%s", students[student_count].id);                   //輸入學號 
            if (strlen(students[student_count].id) == 6) {             //偵測輸入的學生學號是否是6位數，如果是，valid設定為1 
                valid = 1;
                for (j = 0; j < 6; j++) {
                    if (!isdigit(students[student_count].id[j])) {          //偵測6個字母是否都為數字 
                        valid = 0; break;                                   //如果都為數字， valid設定為1，跳離迴圈 ，如果不是，valid設定為0就會使程式要求使用者重新輸入，並繼續迴圈 
                    }
                }
                if (valid) break;
            }
            printf("格式錯誤，請重新輸入。\n");
        }

        float *scores[] = { &students[student_count].math, &students[student_count].physics, &students[student_count].english };       //定義一個float 指標陣列scores存 數學 物理 英文 成績 
        const char *subjects[] = { "數學", "物理", "英文" };                                                                            //定義一個char  指標陣列subjects 包含 數學 物理 英文 
    
        for (j = 0; j < 3; j++) {
            while (1) {
                printf("%s成績（0~100）：", subjects[j]);
                scanf("%f", scores[j]);
                if (*scores[j] >= 0 && *scores[j] <= 100) break;          //偵測分數是否在0~100 有效範圍內 
                printf("輸入錯誤，請重新輸入。\n");
            }
        }

        students[student_count].average = (*scores[0] + *scores[1] + *scores[2]) / 3;          //算平均 
        student_count++;
    }
    system("pause"); 
}

/*********************************************************************/       //題目四(選項b)     貼出所有學生的姓名 學號 各科成績 平均 
void caseb() {
    int i;
	system("cls");
    printf("%-10s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");     
    for ( i = 0; i < student_count; i++) {
        printf("%-10s %-10s %-6.1f %-6.1f %-6.1f %-6.1f\n",students[i].name,students[i].id,students[i].math,students[i].physics,students[i].english,students[i].average);
    }
    system("pause"); 
}
  
/*********************************************************************/       //題目五(選項c)    

void casec() {
	int i;
    system("cls");
    char target[MAX_NAME];
    int found = 0;
    printf("請輸入要查詢的學生姓名：");
    scanf("%s", target);

    for ( i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, target) == 0) {                                //  strcmp 讓  students[i].name 跟   target 做比較 看是否一樣 如果一樣就會回傳0    因此如果一樣離開迴圈 
            printf("姓名：%s\t學號：%s\n", students[i].name, students[i].id);
            printf("數學：%.1f\t物理：%.1f\t英文：%.1f\t平均：%.1f\n",
                   students[i].math, students[i].physics, students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {                                                            //如果 students[i].name 跟   target  布一樣  found 則會一樣是0 ,  !0=1  就會執行這段 印出 查無此學生資料 
        printf("查無此學生資料。\n");
    }
    system("pause"); 
}

/*********************************************************************/       //題目六(選項d) 

int compare_avg(const void *a, const void *b) {                               //比較分數大小 ，由高至低排                               
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;  
    return (s2->average > s1->average) - (s2->average < s1->average);            
}

void grade_ranking() {
    int i;
	system("cls");
    qsort(students, student_count, sizeof(Student), compare_avg);
    printf("%-10s %-10s %-6s\n", "姓名", "學號", "平均");
    for ( i = 0; i < student_count; i++) {
        printf("%-10s %-10s %-6.1f\n", students[i].name, students[i].id, students[i].average);
    }
    system("pause"); 
}




void cased() {
    int i;
	system("cls");
    qsort(students, student_count, sizeof(Student), compare_avg);
    printf("%-10s %-10s %-6s\n", "姓名", "學號", "平均");
    for ( i = 0; i < student_count; i++) {
        printf("%-10s %-10s %-6.1f\n", students[i].name, students[i].id, students[i].average);
    }
    system("pause"); 
}

/*********************************************************************/       //題目七(選項e) 

void casee(void)
{
	printf("Continue?(y/n):");
	fflush(stdin);  // Clear input buffer
}
