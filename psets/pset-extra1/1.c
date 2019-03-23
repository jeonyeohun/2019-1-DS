#include <stdio.h>
#include <stdlib.h>

typedef struct menus{
  char id[20];
  int birth_year;
}Menus;

void add(Menus ** arr, int cnt){
  printf("회원 아이디? ");
  scanf("%s", arr[cnt-1]->id);
  printf("회원생년은? ");
  scanf("%d", &(arr[cnt-1]->birth_year));
}

void print_list(Menus ** arr, int cnt){
  printf(" 2명이 검색되었습니다.\n");
  for (int i=0 ; i<cnt ; i++){
    printf("번호\t회원이름\t태어난해\t\n");
    printf("%d\t%s\t%d\t\n", i+1, arr[i]->id, arr[i]->birth_year);

  }
}

int main (){
  Menus ** arr;
  int cnt=0;
  int size = 5;
  arr = (Menus**)malloc(sizeof(Menus*)*size);
  for(int i=0 ; i<5 ; i++){
    arr[i] = (Menus*)malloc(sizeof(Menus));
  }
  int op;

  while(1){
    printf("원하는 메뉴는 >> ");
    scanf("%d", &op);
    if(op==3){break;}

    switch (op) {
      case 1:
        cnt++;
        size+=5;
        arr = (Menus**)realloc(arr, sizeof(Menus*)*size);
        if (cnt>=5){
          for (int i=cnt ; i<size ; i++){
            arr[i] = (Menus*)malloc(sizeof(Menus));
          }
        }
        add(arr, cnt);
        break;

      case 2:
        print_list(arr, cnt);
        break;
      }
  }

  printf("종료됨");
  free(arr);
  for (int i=0 ; i<size ; i++){
     free(arr[i]);
}
}
