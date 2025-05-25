#include <stdio.h>        // Header file declarations 
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_ID 10


typedef struct {
    char name[MAX_NAME];
    char id[MAX_ID];
    float math, physics, english;
    float average;
} Student;

void casebegin(void);
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
    
    printf("請輸入密碼(密碼為2025):");  
    scanf("%d", &password);    // Input password

	// Password attempts (n=1,2,3; exit on n=4)
	for (n=1;n<=3;n++) { 
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

	if(n==4) {   // Password failed 3 times, exit program
		printf("已錯誤3次，程式結束\a");   
		system("pause");
		return 0;
	}
	
/*********************************************************************/

while(1) {   // Main menu: a, b, c, d choices
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
        scanf("%d", &n);
        if (n >= 5 && n <= 10) break;
        printf("錯誤：人數需為 5~10，請重新輸入：");
    }

    for (i = 0; i < n; i++) {
        printf("\n第 %d 位學生：\n", i + 1);
        printf("姓名：");
        scanf("%s", students[student_count].name);
        while (1) {
            printf("學號（6 位數字）：");
            scanf("%s", students[student_count].id);
            if (strlen(students[student_count].id) == 6) {
                valid = 1;
                for (j = 0; j < 6; j++) {
                    if (!isdigit(students[student_count].id[j])) {
                        valid = 0; break;
                    }
                }
                if (valid) break;
            }
            printf("格式錯誤，請重新輸入。\n");
        }

        float *scores[] = { &students[student_count].math, &students[student_count].physics, &students[student_count].english };
        const char *subjects[] = { "數學", "物理", "英文" };

        for (j = 0; j < 3; j++) {
            while (1) {
                printf("%s成績（0~100）：", subjects[j]);
                scanf("%f", scores[j]);
                if (*scores[j] >= 0 && *scores[j] <= 100) break;
                printf("輸入錯誤，請重新輸入。\n");
            }
        }

        students[student_count].average = (*scores[0] + *scores[1] + *scores[2]) / 3;
        student_count++;
    }
    system("pause"); 
}

/*********************************************************************/       //題目四(選項b)    
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
        if (strcmp(students[i].name, target) == 0) {
            printf("姓名：%s\t學號：%s\n", students[i].name, students[i].id);
            printf("數學：%.1f\t物理：%.1f\t英文：%.1f\t平均：%.1f\n",
                   students[i].math, students[i].physics, students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("查無此學生資料。\n");
    }
    system("pause"); 
}

/*********************************************************************/       //題目六(選項d) 

int compare_avg(const void *a, const void *b) {
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
