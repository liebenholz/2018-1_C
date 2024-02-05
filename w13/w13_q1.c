//(x0)^3 - 2(x0)^2 + 3^(x1)^2�� �� ������ ���� ��̺��� ���ϴ� ���α׷�
#include <stdio.h>

void partial_differentiation(float x0, float x1, float *dx0, float *dx1);

int main(void) {

	float x0;
	float x1;
	float dx0;	//x0�� ���� ��̺а��
	float dx1;	//x1�� ���� ��̺а��

	printf("�� �Ǽ��� �Է��ϼ��� : ");
	scanf("%f %f",&x0, &x1);

	partial_differentiation(x0, x1, &dx0, &dx1);

	printf("(%f, %f)���� x0�� ��̺� : %f\n", x0, x1, dx0);
	printf("(%f, %f)���� x1�� ��̺� : %f\n", x0, x1, dx1);

	return 0;
}

//�־��� ���׽��� �� ������ ���Ͽ� ��̺��ϴ� �Լ�
void partial_differentiation(float x0, float x1, float *dx0, float *dx1) {
	*dx0 = 3 * x0 * x0 - 4 * x0;	//x0�� ���� ��̺�
	*dx1 = 6 * x1;	//x1�� ���� ��̺�
}