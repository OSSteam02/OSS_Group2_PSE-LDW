#include "manager.h"

void saveData(Product *p[], int count){
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i = 0; i<count; i++){
        if(p[i]->price == -1) continue;
        fprintf(fp,"%s %s %s %d %d\n"
        ,p[i]->name,p[i]->explain, p[i]->weight, p[i]->price, p[i]->deliever); 
    }
    fclose(fp);
    printf("=> 저장됨! ");
}


int createProduct(Product *p){

	printf("이름은? ");
	scanf("%s", p->name);

	printf("원산지는? ");
	scanf("%s", p->explain);

	printf("중량은? ");
	scanf("%s", p->weight);

	printf("판매가격은? ");
	scanf("%d", &p->price);

    printf("배송방법은? ");
    scanf("%d", &p->deliever);

    getchar();

	return 1;
}


void listProduct(Product *p[], int count)
{
     printf("\nNo Name explain weight price deliver \n");
     printf("=============================\n");
     for(int i =0; i<count; i++)
     {
         if(p[i]->price == -1 && p[i]->deliever == -1) continue;
         printf("%2d ", i+1);
         readProduct(*p[i]);
     }
     printf("\n");
}


void readProduct(Product p){

    if(p.price == -1 && p.deliever == -1) return;
        printf("%8s%8s%8s%8d%8d\n", p.name, p.explain, p.weight, p.price, p.deliever);
    
}

int updateProduct(Product *p){
	printf("이름은? ");
	scanf("%s", p->name);

	printf("원산지는? ");
	scanf("%s", p->explain);

	printf("중량은? ");
	scanf("%s", p->weight);
	
	printf("판매가격은? ");
	scanf("%d", &p->price);

    printf("배송방법은? ");
    scanf("%d", &p->deliever);

	printf("=> 수정됨!\n");

	return 1;
}

int selectDataNo(Product *p[], int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}

int deleteOkProduct(Product *p){
	printf("=> 삭제됨");
	*p->name = -1;
	*p->explain = -1;
	*p->weight = -1;
    p->price = -1;
    p->deliever = -1;

	return 0;
}

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}


int loadData(Product *p) {
    int i = 0;
    FILE *fp;
    fp = fopen("product.txt", "rt");
    if(fp == NULL){
        printf("=> 파일없음");
        return 0;
    }
    for(; ; i++){
        fscanf(fp, "%s", p[i].name);
        if(feof(fp)) break;
        fscanf(fp, "%s", p[i].weight);
        fscanf(fp, "%d", &p[i].price);
        fscanf(fp, "%d", &p[i].deliever);
    }
    fclose(fp);
    printf("=> 로딩성공!\n");
    return i;
}


int searchProduct(Product *p, int count){
    char search[20];
    int scnt = 0;
    printf("검색할 이름? ");
    scanf("%s", search);
    printf("No Name Kor Eng Math Sum Avg\n");
    printf("========================\n");
     for(int i =0; i<=count; i++)
     {
         if(p[i].price == -1) continue;
         if(strstr(p[i].name, search)) {
             printf("%2d ", i+1);
             readProduct(p[i]);
             scnt++;
         }
     }
     if(scnt == 0){
         printf("=> 검색된 데이터 없음!");
     }
     printf("\n");
     return 1;
}



