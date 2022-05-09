#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[100];
    char explain[100];
    char weight[100];
    int price;
    int deliever;
} Product;


int createProduct(Product *p); // 제품을 추가하는 함수
int updateProduct(Product *p);
int deleteOkProduct(Product *p);
void readProduct(Product p); // 하나의 제품 출력 함수
void saveData(Product *p[], int count);
int selectDataNo(Product *p[], int count);
void listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력
int selectMenu();
int loadData(Product *p);
int searchProduct(Product *p, int count); // 제품이름 검색

