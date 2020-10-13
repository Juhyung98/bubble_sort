#include <stdio.h>

void bubble_sort(int a[], int n);
void swap(int num[], int a, int b);
void show_list(int list[], int list_len);

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

void bubble_sort(int a[], int n) {
	int k = 0;
  int comparison_num;
     		
	while(k < n-1) {
		int last = n - 1;
    int j;

		for(j=n-1; j>k; j--) {
			if(a[j-1] > a[j]) {
        printf("k : %d, last : %d, j : %d\n", k, last, j);
				swap(a, j-1, j);
        show_list(a, n);
        comparison_num++;
				last = j;
        printf("k : %d, last : %d, j : %d\n", k, last, j);
			}
		}
		k = last;
    printf("k : %d, last : %d, j : %d\n", k, last, j);
	}
  printf("총 비교 횟수 : %d\n", comparison_num);
}

void swap(int list[], int a, int b){
	int temp = 0;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
  printf("I changed %d and %d\n\n", list[a], list[b]);
	return;
}

void show_list(int list[], int list_len){
  printf("현재의 list 상태 : [");
  for (int i = 0; i < list_len; i++){
    printf("%d ", list[i]);
  }
  printf("]\n");
}