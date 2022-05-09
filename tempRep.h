#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef struct std {
	char name[10];
	int std_id;
	int room;
	int sex; // 0:man 1:woman
	int penalty;
}std;

typedef struct rep {
	int date;
	int index; //학생의 index
	int std_id[MAX];
	float temp[MAX];
	struct tm time[MAX];
}rep;

int create_std(std* p);
int create_rep(rep* r); //날짜 생성
int read_rep(rep* r); //show product / 날짜별 학생 이름, 온도 출력
int update_rep(rep* r); //update product // 학생추가. 학번, 온도 입력 
int delete_rep(rep* r, int* index); //delete product // index 한칸씩 땡기면 될 듯
int select_menu();
int edit_rep(rep* r);


int create_std(std* p) {
	printf("input name : ");
	fgets(p->name, sizeof(p->name), stdin);
	printf("\ninput std_id : ");
	scanf("%d", &p->std_id);
	printf("\ninput room number : ");
	scanf("%d", &p->room);
	printf("\ninput sex : ");
	scanf("%d", &p->sex);
	p->penalty = 0;

	return 0;
}

int create_rep(rep* r) {
	r->index++;
	printf("input date (yyyymmdd) : ");
	scanf("%d", &r->date);

	return 0;
}

int update_rep(rep* r) {
	rep temp;

	printf("input date (yyyymmdd) : ");
	//날짜로 레포트의 index 찾기

	

	printf("\ninput std_id : ");
	scanf("%d", &r->std_id);
	printf("\ninput temperature : ");
	scanf("%f", &r->temp);
	printf("\ninput sex : ");
	scanf("%d", &p->price);
	return 0;
}

int delete_rep(rep* r, int* index) {
	int temp_date;
	int temp_index;
	rep temp_r;

	printf("input date (yyyymmdd) : ");
	scanf("%d", &temp_date);

	for (int i; i < *index; i++) {
		if (r[i].std_id == temp_date) {
			temp_index = i;
			break;
		}
	}

	if (temp_index == *index) {
		*index--;
		return 0;
	}

	for (int i = temp_index; i < *index-1; i++) {
		r[i] = r[i+1];
	}
	*index--;
	return 0;
}

int selectMenu() {
	int menu;
	printf("\n*** PizzaYaho ***\n");
	printf("1. 학생 추가\n");
	printf("2. 레포트 추가\n");
	printf("2. 레포트 조회\n");
	printf("3. 레포트 수정\n");
	printf("4. 레포트 삭제\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	getchar();
	return menu;
}

