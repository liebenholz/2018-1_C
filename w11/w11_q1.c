#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

//�迭�� ���İ� �ε��� Ž�� ���α׷�
int binary_search(int list[], int n, int key);

int main ()
{
	int number [SIZE];
	int i, j, temp, least, in, result;

	srand( (unsigned) time( NULL ) );

	//���ۿ� ������ �迭�� �ʱ�ȭ�� �� ���
	printf("Array \t\t");
	for (i=0; i<SIZE; i++) {
		number[i] = 1+rand()%100;
		printf("%d\t", number[i]);
	}
	printf("\n\n");

	//�迭�� ������������ ����
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
	
	//���ĵ� �迭�� ���
	printf("Sorted Array \t");
	for (i=0; i < SIZE; i++) {
		printf("%d\t", number[i]);
	}
	printf("\n\n");

	//����ڿ��� ������ �Է¹ް� �ش� ���ڰ� ������ �� ��° �������� �˷��ش�
	//������ ������ �˷��ش�.
	printf("�ڿ����� �Է��ϼ���(1~100) : ");
	scanf("%d", &in);

	result = binary_search(number, SIZE, in);
	if (result >= 0) {
		printf("%d��° �����Դϴ�.\n", result+1);
	}
	else {
		printf("�������� �ʽ��ϴ�\n");
	}

	return 0;

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