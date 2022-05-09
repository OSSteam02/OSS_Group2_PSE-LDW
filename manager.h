#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100];
    int std_id;
    int date;
    float tmep;
    int penalty;
    int room;
} student;


int createProduct(student *p); // 제품을 추가하는 함수
int updateProduct(student *p);
int deleteOkProduct(student *p);
void readProduct(student p); // 하나의 제품 출력 함수
void saveData(student *p[], int count);
int selectDataNo(student *p[], int count);
void listProduct(student *p[], int count); // 전체 등록된 제품 리스트 출력
int selectMenu();
int loadData(student *p);
int searchProduct(student *p, int count); // 제품이름 검색

