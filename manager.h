#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100];
    int std_id;
    int date;
    float temp;
    int penalty;
    int room;
} student;


int createStudent(student *p); // 제품을 추가하는 함수
int updateStudent(student *p);
int deleteOkStudent(student *p);
void readStudent(student p); // 하나의 제품 출력 함수
void saveData(student *p[], int count);
int selectDataNo(student *p[], int count);
void listStudent(student *p[], int count); // 전체 등록된 제품 리스트 출력
int selectMenu();
int loadData(student *p);
int searchStudent(student *p, int count); // 제품이름 검색

