#include <stdio.h>
 
void shakerSort(int num[],int list_len);
void swap(int num[], int a, int b);
void show_list(int list[], int list_len, int comparison_count);

int main(){
    int list[] = {1, 7, 2, 4, 6, 9, 3, 12, 11, 10};
    int list_len = sizeof(list)/sizeof(int);
	printf("before bubble sorting: [ ");
	for (int i=0; i<list_len; i++){
		printf("%d ", list[i]);
	}
	printf("]\n");
    shakerSort(list,list_len);
	printf("after bubble sorting: [ ");
	for (int i=0; i<list_len; i++){
		printf("%d ", list[i]);
	}
	printf("]\n");

	return 0;
}

void shakerSort(int list[], int list_len) {
	int left = 0;
	int right = list_len - 1;
	int last = right;
	int comparison_count = 0;

	while (left < right) {
		for (int j = right; j > left; j--) {
			if (list[j - 1] > list[j]) {
				swap(list, j - 1, j);
				comparison_count++;
				show_list(list, list_len, comparison_count);
				last = j;
			}
		}
		left = last;

		for (int j = left; j < right; j++) {
			if (list[j] > list[j + 1]) {
				swap(list, j, j + 1);
				comparison_count++;
				show_list(list, list_len, comparison_count);
				last = j;
			}
		}
		right = last;
	}
	printf("총 비교 횟수 : %d\n", comparison_count);
}

void swap(int list[], int a, int b){
	int temp = 0;
	temp = list[a];
	list[a] = list[b];
	list[b] = temp;
	printf("I changed %d and %d\n", list[a], list[b]);
	return;
}

void show_list(int list[], int list_len, int comparison_count){
  printf("현재의 번호 : %d, list 상태 : [", comparison_count);
  for (int i = 0; i < list_len; i++){
    printf("%d ", list[i]);
  }
  printf("]\n");
}