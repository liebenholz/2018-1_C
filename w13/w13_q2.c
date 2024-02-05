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

	//���ۿ� ������ �迭�� �ʱ�ȭ�� �� ���
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
	
	//�迭�� ������������ ����
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

	//���ĵ� �迭�� ���
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

	//�� �迭 �����Ͽ� ����ϱ�
	merge(numberA, numberB, numberC, 5);
	printf("Merged Array \t");
	for (i=0; i < 10; i++) {
		printf("%d\t", numberC[i]);
	}
	printf("\n\n");

	//����ڿ��� ������ �Է¹ް� �ش� ���ڰ� ������ �� ��° �������� �˷��ش�
	//������ ������ �˷��ش�.
	printf("�ڿ����� �Է��ϼ���(1~100) : ");
	scanf("%d", &in);

	result = binary_search(numberC, 10, in);
	if (result >= 0) {
		printf("%d��° �����Դϴ�.\n", result+1);
	}
	else {
		printf("�������� �ʽ��ϴ�\n");
	}

	return 0;

}

//�� �迭�� �ϳ��� �迭�� �����ϴ� �Լ�
void merge(int *A, int *B, int *C, int size) {
	int a=0;
	int b=0;
	int c=0;
	int i;

	//�� �迭�� ���Ҹ� ���Ͽ� �� ���� ���� �迭 C�� ���� �� �ε��� ����
	while(a < size && b < size) {
		if (A[a] <= B[b]) {
			C[c++] = A[a++];
		}
		else {
			C[c++] = B[b++];
		}
	}

	//��� �ϳ��� ��� ������ �Ǹ� �������� �̾���̱�
	for (i=b; i<size; i++) {
		C[c++] = B[b++];
	}
	for (i=a; i<size; i++) {
		C[c++] = A[a++];
	}


}

//����Ž���� �̿��Ͽ� ����ڰ� �Է��� ���ڰ� ���°���� �˷��ִ� �Լ�
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