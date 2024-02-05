// ��ȭ����
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void reinforce_powder(int *item);		//��ȭ���� ���
void reinforce_stone(int *item);		//��ȭ�� ���
double success_probability(int *item);	//��ȭ Ȯ��

int main(void)
{
	int money = 2000;	//�ڱ�
	int item = 0;		//������ ��ȭ �ܰ� (���� -1�̸� �ı��� �����Ѵ�)
	int command = 0;	//��ȭ���� or ��ȭ�鼮 ����

	srand((int)time(NULL));

	printf("---��ȭ ����---\n\n");
	printf("---��ȭ ��� ����---\n");
	printf("  ��ȭ����    50\n");
	printf("   ��ȭ��     200\n\n");
	
	while(money > 0 && item >= 0) {
		printf("���� �ڱ� : %d\n",money);
		printf("����� ��ȭ ��Ḧ �����ϼ��� (1: ��ȭ����, 2: ��ȭ��) : ");
		scanf("%d",&command);

		switch(command) {
		//��ȭ ����
		case 1:
			money -= 50;
			reinforce_powder(&item);
			break;
		//��ȭ��
		case 2:
			money -= 200;
			reinforce_stone(&item);
			break;
		//�Է� ����
		default:
			printf("�߸��� ���ڸ� �Է¹޾ҽ��ϴ�.\n");
			break;
		}
		printf("\n");
	}
	printf("���� �ڱ� : %d\n", money);

	return 0;
}
	
void reinforce_powder(int *item) {\
	int num = 0;
	double prob = success_probability(item);
	prob *= pow(10.0, *item);
//	printf("%lf\n", prob);

	//������ ����
	//������ ���� ���� Ȯ������ ������ ����
	num = rand() % (int)pow(10.0, *item);

	if (num < prob) {
		//����
		printf("����!\n");
		(*item)++;
	}
	else {
		//����
		printf("����!\n");
		num = rand() % 2;
//		printf("%d",randNum);
		if (num == 0)
			(*item) = 0;
		else {
			printf("�ı��Ǿ����ϴ�!\n");
			(*item) = -1;
		}
	}
	if (*item >= 0)
		printf("���� ��ȭ ��ġ : +%d\n", *item);
	
}

void reinforce_stone(int *item) { 
	int num = 0;
	double prob = success_probability(item);
	prob *= pow(10.0, *item);
//	printf("%lf\n", prob);

	//������ ����
	//������ ���� ���� Ȯ������ ������ ����
	num = rand() % (int)pow(10.0, *item) + 0.1;

	if (num < prob) {
		//����
		printf("����!\n");
		(*item)++;
	}
	else {
		//����
		printf("����!\n");
		num = rand() % 2;
//		printf("%d",randNum);
		if (num == 0)
			(*item)--;
		else {
			printf("�ı��Ǿ����ϴ�!\n");
			(*item) = -1;
		}
	}
	if (*item >= 0)
		printf("���� ��ȭ ��ġ : +%d\n", *item);
}
	

double success_probability(int *item) {
	double p = pow(0.8, *item);		//��ȭ�ܰ迡 ���� ���� ��ȭ ���� Ȯ��
	return p;
}