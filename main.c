#include "manager.h"
// #define DEBUG //DEBUG 매크로 정읜

int main(void){

    Product *p1[100];
#ifdef DEBUG
    printf("DEBUGMODE => Hello World!!\n");
#endif
    int curcount = 0, menu=0, count=0;
    int no = 0;
    count = loadData(*p1);
    while (1){
        menu = selectMenu();
        if (menu == 0)break;
        if (menu == 1){
            if(count > 0)
			    listProduct(p1,curcount);}
        else if (menu == 2){
            p1[curcount] = (Product *)malloc(sizeof(Product));
            count += createProduct(p1[curcount]); curcount++;}
        else if (menu == 3){
             no = selectDataNo(p1, curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(p1[no-1]);
        }
        else if (menu == 4){
            no = selectDataNo(p1,curcount);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteOkProduct(p1[no-1])) curcount--;
            }
        }
        else if (menu == 5){
            saveData(p1, curcount);
        }
        else if(menu == 6){
            searchProduct(*p1, curcount);
        }
    }
    printf("종료됨!\n");
    return 0;
}
