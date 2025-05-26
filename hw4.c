#include <stdio.h>        //���Y��
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_ID 10


typedef struct {                         //�w�q���c 
    char name[MAX_NAME];
    char id[MAX_ID];
    float math, physics, english;
    float average;
} Student;

void casebegin(void);                    //�w�q��� �D�e����ﶵe 
void casea(void);
void caseb(void);
void casec(void);
void cased(void);
void casee(void);

Student students[MAX_STUDENTS];            
int student_count = 0;





int main(void)
{
	
/*********************************************************************/ 	// �D�ؤ@ 

	int password=0,n,row, col,i, j;     // Variable declarations
	char userinput,y;
	
	printf("�o�OE5A60���ĥ|���{���@�~\n");                                        
	printf("EEEEEE    55555        AAA          66666     00000\n");
    printf("E        5            A   A        6          0   0\n");
    printf("EEEEE     55555      AAAAAAA        66666     0   0\n");
    printf("E              5    A       A      6     6    0   0\n");
    printf("EEEEE     55555    A         A      66666     00000\n");
	
	system("pause");
    system("cls");
    
    printf("�п�J�K�X(�K�X��2025):");      //��J�K�X 
    scanf("%d", &password);                //�K�X�s��password
	 

	
	for (n=1;n<=3;n++) {                                     //�j��3��  �ˬd�K�X  �p�G��K�W��J���T�A�w��   �p�G���n�D���s��J  3��������j�� 
		system("cls");
		if(password==2025) {    // Password check
			printf("��J���T�A�w��!!\n");
			system("pause");
			system("cls");
			break;
		}
		else {
			printf("�K�X���~(�w���~%d��)�A�Э��s��J�K�X(�K�X��2025):",n);  
			scanf("%d", &password);  	 
		}
	} 

	if(n==4) {                                                  //3���j���A�����O�_�O��3�������j��A�p�G�O�����{�� 
		printf("�w���~3���A�{������\a");   
		system("pause");
		return 0;
	}
	
/*********************************************************************/

while(1) {                                                              //�L���j��A��Ja,b,c,d,e���O�����U��� case a~e 
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




/*********************************************************************/  //�D�ؤG(�D�e��) 

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

/*********************************************************************/       //�D�ؤT(�ﶵa)  



void casea() {
    system("cls");
    int n, i, j, valid;                                  
    printf("�п�J�ǥͤH�ơ]5~10�^�G");          
    while (1) {                     
        scanf("%d", &n);                                         //�ǥͤH�Ʀs���ܼ�n�A�B�����ǥͤH�ƭn�b5~10�H���A�p�G���A�o�ӽd��n�D���s��J 
        if (n >= 5 && n <= 10) break;
        printf("���~�G�H�ƻݬ� 5~10�A�Э��s��J�G");
    }

    for (i = 0; i < n; i++) {                                            
        printf("\n�� %d ��ǥ͡G\n", i + 1);                      
        printf("�m�W�G");
        scanf("%s", students[student_count].name);                    //i�|�H�ۦ^��W�[ 0,1,2,3...  ��J�ǥ�1,2,3...���W�l  
        while (1) {
            printf("�Ǹ��]6 ��Ʀr�^�G");
            scanf("%s", students[student_count].id);                   //��J�Ǹ� 
            if (strlen(students[student_count].id) == 6) {             //������J���ǥ;Ǹ��O�_�O6��ơA�p�G�O�Avalid�]�w��1 
                valid = 1;
                for (j = 0; j < 6; j++) {
                    if (!isdigit(students[student_count].id[j])) {          //����6�Ӧr���O�_�����Ʀr 
                        valid = 0; break;                                   //�p�G�����Ʀr�A valid�]�w��1�A�����j�� �A�p�G���O�Avalid�]�w��0�N�|�ϵ{���n�D�ϥΪ̭��s��J�A���~��j�� 
                    }
                }
                if (valid) break;
            }
            printf("�榡���~�A�Э��s��J�C\n");
        }

        float *scores[] = { &students[student_count].math, &students[student_count].physics, &students[student_count].english };       //�w�q�@��float ���а}�Cscores�s �ƾ� ���z �^�� ���Z 
        const char *subjects[] = { "�ƾ�", "���z", "�^��" };                                                                            //�w�q�@��char  ���а}�Csubjects �]�t �ƾ� ���z �^�� 
    
        for (j = 0; j < 3; j++) {
            while (1) {
                printf("%s���Z�]0~100�^�G", subjects[j]);
                scanf("%f", scores[j]);
                if (*scores[j] >= 0 && *scores[j] <= 100) break;          //�������ƬO�_�b0~100 ���Ľd�� 
                printf("��J���~�A�Э��s��J�C\n");
            }
        }

        students[student_count].average = (*scores[0] + *scores[1] + *scores[2]) / 3;          //�⥭�� 
        student_count++;
    }
    system("pause"); 
}

/*********************************************************************/       //�D�إ|(�ﶵb)     �K�X�Ҧ��ǥͪ��m�W �Ǹ� �U�즨�Z ���� 
void caseb() {
    int i;
	system("cls");
    printf("%-10s %-10s %-6s %-6s %-6s %-6s\n", "�m�W", "�Ǹ�", "�ƾ�", "���z", "�^��", "����");     
    for ( i = 0; i < student_count; i++) {
        printf("%-10s %-10s %-6.1f %-6.1f %-6.1f %-6.1f\n",students[i].name,students[i].id,students[i].math,students[i].physics,students[i].english,students[i].average);
    }
    system("pause"); 
}
  
/*********************************************************************/       //�D�ؤ�(�ﶵc)    

void casec() {
	int i;
    system("cls");
    char target[MAX_NAME];
    int found = 0;
    printf("�п�J�n�d�ߪ��ǥͩm�W�G");
    scanf("%s", target);

    for ( i = 0; i < student_count; i++) {
        if (strcmp(students[i].name, target) == 0) {                                //  strcmp ��  students[i].name ��   target ����� �ݬO�_�@�� �p�G�@�˴N�|�^��0    �]���p�G�@�����}�j�� 
            printf("�m�W�G%s\t�Ǹ��G%s\n", students[i].name, students[i].id);
            printf("�ƾǡG%.1f\t���z�G%.1f\t�^��G%.1f\t�����G%.1f\n",
                   students[i].math, students[i].physics, students[i].english, students[i].average);
            found = 1;
            break;
        }
    }
    if (!found) {                                                            //�p�G students[i].name ��   target  ���@��  found �h�|�@�ˬO0 ,  !0=1  �N�|����o�q �L�X �d�L���ǥ͸�� 
        printf("�d�L���ǥ͸�ơC\n");
    }
    system("pause"); 
}

/*********************************************************************/       //�D�ؤ�(�ﶵd) 

int compare_avg(const void *a, const void *b) {                               //������Ƥj�p �A�Ѱ��ܧC��                               
    Student *s1 = (Student *)a;
    Student *s2 = (Student *)b;  
    return (s2->average > s1->average) - (s2->average < s1->average);            
}

void grade_ranking() {
    int i;
	system("cls");
    qsort(students, student_count, sizeof(Student), compare_avg);
    printf("%-10s %-10s %-6s\n", "�m�W", "�Ǹ�", "����");
    for ( i = 0; i < student_count; i++) {
        printf("%-10s %-10s %-6.1f\n", students[i].name, students[i].id, students[i].average);
    }
    system("pause"); 
}




void cased() {
    int i;
	system("cls");
    qsort(students, student_count, sizeof(Student), compare_avg);
    printf("%-10s %-10s %-6s\n", "�m�W", "�Ǹ�", "����");
    for ( i = 0; i < student_count; i++) {
        printf("%-10s %-10s %-6.1f\n", students[i].name, students[i].id, students[i].average);
    }
    system("pause"); 
}

/*********************************************************************/       //�D�ؤC(�ﶵe) 

void casee(void)
{
	printf("Continue?(y/n):");
	fflush(stdin);  // Clear input buffer
}
