# include <stdio.h>

void show_list(int list[], int list_len, int comparison_count){
  printf("현재의 번호 : %d, list 상태 : [", comparison_count);
  for (int i = 0; i < list_len; i++){
    printf("%d ", list[i]);
  }
  printf("]\n");
}

// This is the algorithm of original bubble sort
void bubble_sort(int list[], int list_len){
  int step, j, temp;
  int comparison_count = 0;
  int step_num;

  for(step=0; step<list_len-1; step++){
    printf("This is step %d\n", step);
    step_num = 0;
    for(j=0; j<list_len-1-step; j++){
      comparison_count++; // 총 비교 횟수를 누적
      step_num++;
      show_list(list, list_len, comparison_count);
      // j번째와 j+1번째의 요소가 크기 순이 아니면 교환
      if(list[j]>list[j+1]){
        temp = list[j];
        list[j] = list[j+1];
        list[j+1] = temp;
        printf("I changed %d and %d\n", list[j], list[j+1]);
      }
    }
    printf("This comparison num is %d\n\n", step_num);
  }
  printf("총 비교 횟수 : %d\n", comparison_count);
}



int main(){
  int i;
  int list[] = {1, 7, 2, 4, 6, 9, 3, 12, 11, 10};
  int list_len = sizeof(list)/sizeof(int);

  printf("before bubble sorting : [ ");

  for (i = 0; i < list_len; i++){
    printf("%d ", list[i]);
  }
  printf("]\n");

  // 버블 정렬 수행
  bubble_sort(list, list_len);

  printf("after bubble sorting : [ ");
  // 정렬 결과 출력
  for(i=0; i<list_len; i++){
    printf("%d ", list[i]);
  }
  printf("]\n");

  return 0;

}
