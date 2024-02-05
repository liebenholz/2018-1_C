#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *A, int *B, int *C, int size);
int binary_search(int list[], int n, int key);

int main(void) {
	int numberA [5];
	int numberB [5];
	int numberC [10];
	int i, j, temp, least, in, result;

	srand((unsigned) time(NULL));

	//무작워 정수로 배열을 초기화한 후 출력
	printf("Array1 \t\t");
	for (i=0; i<5; i++) {
		numberA[i] = 1+rand()%100;
		printf("%d\t", numberA[i]);
	}
	printf("\n");
	printf("Array2 \t\t");
	for (i=0; i<5; i++) {
		numberB[i] = 1+rand()%100;
		printf("%d\t", numberB[i]);
	}
	printf("\n\n");
	
	//배열을 오름차순으로 정렬
	for (i=0; i<4; i++) {
		least = i;
		for (j=i+1; j<5; j++) {
			if (numberA[j] <= numberA[least])
				least = j;
		}
		temp = numberA[i];
		numberA[i] = numberA[least];
		numberA[least] = temp;
	}
	for (i=0; i<4; i++) {
		least = i;
		for (j=i+1; j<5; j++) {
			if (numberB[j] <= numberB[least])
				least = j;
		}
		temp = numberB[i];
		numberB[i] = numberB[least];
		numberB[least] = temp;
	}

	//정렬된 배열을 출력
	printf("Sorted Array1 \t");
	for (i=0; i < 5; i++) {
		printf("%d\t", numberA[i]);
	}
	printf("\n");
	printf("Sorted Array2 \t");
	for (i=0; i < 5; i++) {
		printf("%d\t", numberB[i]);
	}
	printf("\n\n");

	//두 배열 병합하여 출력하기
	merge(numberA, numberB, numberC, 5);
	printf("Merged Array \t");
	for (i=0; i < 10; i++) {
		printf("%d\t", numberC[i]);
	}
	printf("\n\n");

	//사용자에게 정수를 입력받고 해당 숫자가 있으면 몇 번째 숫자인지 알려준다
	//없으면 없음을 알려준다.
	printf("자연수를 입력하세요(1~100) : ");
	scanf("%d", &in);

	result = binary_search(numberC, 10, in);
	if (result >= 0) {
		printf("%d번째 숫자입니다.\n", result+1);
	}
	else {
		printf("존재하지 않습니다\n");
	}

	return 0;

}

//두 배열을 하나의 배열로 병합하는 함수
void merge(int *A, int *B, int *C, int size) {
	int a=0;
	int b=0;
	int c=0;
	int i;

	//두 배열의 원소를 비교하여 더 작은 값을 배열 C에 삽입 후 인덱스 증가
	while(a < size && b < size) {
		if (A[a] <= B[b]) {
			C[c++] = A[a++];
		}
		else {
			C[c++] = B[b++];
		}
	}

	//어느 하나가 모두 끝나게 되면 나머지는 이어붙이기
	for (i=b; i<size; i++) {
		C[c++] = B[b++];
	}
	for (i=a; i<size; i++) {
		C[c++] = A[a++];
	}


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