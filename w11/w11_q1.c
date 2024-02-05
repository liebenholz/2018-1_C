#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

//배열의 정렬과 인덱스 탐색 프로그램
int binary_search(int list[], int n, int key);

int main ()
{
	int number [SIZE];
	int i, j, temp, least, in, result;

	srand( (unsigned) time( NULL ) );

	//무작워 정수로 배열을 초기화한 후 출력
	printf("Array \t\t");
	for (i=0; i<SIZE; i++) {
		number[i] = 1+rand()%100;
		printf("%d\t", number[i]);
	}
	printf("\n\n");

	//배열을 오름차순으로 정렬
	for (i=0; i<SIZE; i++) {
		least = i;

		for (j=i; j<SIZE; j++) {
			if (number[j] <= number[least])
				least = j;
		}
		temp = number[i];
		number[i] = number[least];
		number[least] = temp;
	}
	
	//정렬된 배열을 출력
	printf("Sorted Array \t");
	for (i=0; i < SIZE; i++) {
		printf("%d\t", number[i]);
	}
	printf("\n\n");

	//사용자에게 정수를 입력받고 해당 숫자가 있으면 몇 번째 숫자인지 알려준다
	//없으면 없음을 알려준다.
	printf("자연수를 입력하세요(1~100) : ");
	scanf("%d", &in);

	result = binary_search(number, SIZE, in);
	if (result >= 0) {
		printf("%d번째 숫자입니다.\n", result+1);
	}
	else {
		printf("존재하지 않습니다\n");
	}

	return 0;

}

//이진탐색을 이용하여 사용자가 입력한 숫자가 몇번째인지 알려주는 함수
int binary_search(int list[], int n, int key) {
	int low, high, middle;

	low = 0;
	high = n-1;

	while (low <= high) {
		middle = (low + high)/2;
		if (key == list[middle]) {
			return middle;
		}
		else if (key > list[middle]) {
			low = middle +1;
		}
		else {
			high = middle -1;
		}
	}
	return -1;
}