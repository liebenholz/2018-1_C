//�� ���� x, y�� �Է¹ް� �� ������ ���� �ٲٴ� ���α׷�
#include <stdio.h>
void swap (int *a, int *b);

int main () {

	int x;
	int y;	//�Է¹޴� �� ����

	//�� ���� �Է¹޴´�
	printf("�� ������ �Է��ϼ��� :");
	scanf_s("%d %d", &x, &y);
	printf("\n");

	//��ȯ ��
	printf("�� (x, y) = (%d, %d)\n", x, y);

	//��ȯ ��
	swap(&x, &y);
	printf("�� (x, y) = (%d, %d)\n", x, y);

	return 0;
}

// ������ ������ �ٲٴ� �Լ��� ������ ���� ȣ�� ���·� �ۼ���
void swap (int *a, int *b) {
	int temp;

	temp = *a;	//temp = x
	*a = *b;	//x = y
	*b = temp;	//y = temp
}