#include "manager.h"

void saveData(student *p[], int count){
    FILE *fp;
    fp = fopen("temperature.txt", "wt");

    for(int i = 0; i<count; i++){
        if(p[i]->std_id == -1) continue;
        fprintf(fp,"%s %d %d %1f %d\n"
        ,p[i]->name,p[i]->std_id, p[i]->date, p[i]->temp, p[i]->room); 
    }
    fclose(fp);
    printf("=> 저장됨! ");
}


int createStudent(student *p){

	printf("이름은? ");
	scanf("%s", p->name);

	printf("학번은? ");
	scanf("%d", &p->std_id);

	printf("날짜는? ");
	scanf("%d", &p->date);

	printf("온도는? ");
	scanf("%f", &p->temp);

    printf("방 번호는? ");
    scanf("%d", &p->room);

    getchar();

	return 1;
}


void listStudent(student *p[], int count)
{
     printf("\nNo Name std_id date temp room \n");
     printf("=============================\n");
     for(int i =0; i<count; i++)
     {
         if(p[i]->std_id == -1 && p[i]->date == -1) continue;
         printf("%2d ", i+1);
         readStudent(*p[i]);
     }
     printf("\n");
}


void readStudent(student p){

    if(p.std_id == -1 && p.date == -1) return;
        printf("%8s\t%8d\t%8d\t%1f\t%8d\n", p.name, p.std_id, p.date, p.temp, p.room);
    
}


int updateStudent(student *p){
	printf("이름은? ");
	scanf("%s", p->name);

	printf("학번은? ");
	scanf("%d", &p->std_id);

	printf("날짜는? ");
	scanf("%d", &p->date);
	
	printf("온도는? ");
	scanf("%f", &p->temp);

    printf("방 호수는? ");
    scanf("%d", &p->room);

	printf("=> 수정됨!\n");

	return 1;
}

int selectDataNo(student *p[], int count){
    int no;
    listStudent(p, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

int deleteOkStudent(student **p, int* index){
	int temp_date;
	int temp_stdID;
	int temp_index;

	printf("날짜를 입력해주세요 : ");
	scanf("%d", &temp_date);
    printf("학번을 입력해주세요 : ");
	scanf("%d", &temp_stdID);

	for (int i=0; i < *index; i++) {
		if (p[i]->std_id == temp_stdID && p[i]->date == temp_date){
			temp_index = i;
            printf("\nfind index : %d\n", temp_index);
			break;
		}
	}

	if (temp_index == *index) {
        printf("\nlast index : %d\n", temp_index);
		return 0;
	}

	for (int i = temp_index; i < *index-1; i++) {
		p[i] = p[i+1];
	}
    printf("\nmiddle index : %d\n", temp_index);
	return 0;
}

int searchDate(student **p, int* index){
	int temp_date;

	printf("날짜를 입력해주세요 : ");
	scanf("%d", &temp_date);

	for (int i=0; i < *index; i++) {
		if (p[i]->date == temp_date){
			readStudent(*p[i]);
		}
	}

	return 0;
}

int searchTemp(student **p, int* index){
	int temp_Temp;

	printf("온도를 입력해주세요 : ");
	scanf("%d", &temp_Temp);

	for (int i=0; i < *index; i++) {
		if (p[i]->temp >= temp_Temp){
			readStudent(*p[i]);
		}
	}

	return 0;
}

int selectMenu(){
    int menu;
    printf("\n*** 온도측정 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 날짜로 검색\n");
    printf("8. 특정 온도 이상인 사람 검색\n");
    printf("9. 특정인물의 지난 3일간 쌓인 벌점은?\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int loadData(student *p) {
    int i = 0;
    FILE *fp;
    fp = fopen("temperature.txt", "rt");
    if(fp == NULL){
        printf("=> 파일없음");
        return 0;
    }
    for(; ; i++){
        fscanf(fp, "%s", p[i].name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &p[i].std_id);
        fscanf(fp, "%d", &p[i].date);
        fscanf(fp, "%f", &p[i].temp);
        fscanf(fp, "%d", &p[i].room);
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    return i;
}

int searchStudent(student *p, int count){
    char search[100];
    int scnt = 0;
    printf("검색할 이름? ");
    scanf("%s", search);

     for(int i =0; i<=count; i++)
     {
         if(p[i].std_id == -1) continue;
         if(strstr(p[i].name, search)) {
             printf("%2d ", i+1);
             readStudent(p[i]);
             scnt++;
         }
     }
     if(scnt == 0){
         printf("=> 검색된 데이터 없음!");
     }
     printf("\n");
     return 1;
}


int searchPenalty(student *p, int count){
    char search[20];
    int scnt = 0;
    int period = 0;
    int penalty = 0;
    printf("검색할 이름? ");
    scanf("%s", search);

     for(int i =0; i<=count; i++)
     {
         if(p[i].std_id == -1) continue;
         if(strstr(p[i].name, search)) {
             printf("%2d ", i+1);
             readStudent(p[i]);
             scnt++;
         }
     }
     if(scnt == 0){
         printf("=> 검색된 데이터 없음!");
     }
     printf("%d\n",scnt);
     penalty = 3 - scnt;
    printf("지난 3일 동안 쌓인 벌점은 %d점 입니다.\n", penalty);
     return 1;
}

