//�߱� ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game (int record);

int main()
{
	char command = 'y';		//y/n �Է¹޴� ����
	int record = 100;		//�ְ���
	int previous;			//game�� ���� ���� ���

	printf("-----�߱�����-----\n");

	while (command != 'n') {
		previous = game(record);	//������ ����� ����
		if (previous < record) {    //��� ����
			record = previous;
		}
		
		printf("����Ͻðڽ��ϱ�?(Y/N) : ");
		scanf(" %c", &command);     //���� ����� ����

		if (command == 'n') {
			printf("�ְ��� : %dȸ\n", record);	//�ְ��� ��� �� ����
		}
		else if (command != 'y') {
			printf("�߸��� ���� �ԷµǾ����ϴ�.\n");	//y,n �̿��� ���ڴ� ����
		}

	}

}

int game (int record)
{
	int r1 = 0;	//1�� ��
	int r2 = 0;	//2�� ��
	int r3 = 0; //3�� ��
	int n1 = 0; //����� �Է� 1�� ��
	int n2 = 0; //����� �Է� 2�� ��
	int n3 = 0; //����� �Է� 3�� ��
	int ball = 0; //ball ����
	int strike = 0; //strike ��
	int count = 0; //�õ� Ƚ��

	srand( (unsigned) time( NULL ) );

	printf("���� ����!\n");
	//������ ���� 3���� �ߺ����� �ʵ��� �����Ѵ�.
	r1 = 1+rand()%9;
	while (r2 == 0 || r1 == r2)
		r2 = 1+rand()%9;
	while (r3 == 0 || r1 == r3 || r2 == r3)
		r3 = 1+rand()%9;

	printf("%d %d %d\n", r1, r2, r3);

	while (r1!=n1 || r2!=n2 || r3!=n3) {
		printf("�� ���ڸ� �Է��ϼ��� : ");  //����ڰ� ���ڸ� �Է��Ѵ�.
		scanf("%d %d %d", &n1, &n2, &n3);

		//ball, strike ���� ����
		if (n1 == r1) 
			strike++;
		else if (n1 == r2 || n1 ==r3)
			ball++;
		if (n2 == r2)
			strike++;
		else if (n2 == r1 || n2 ==r3)
			ball++;
		if (n3 == r3)
			strike++;
		else if (n3 == r1 || n3 ==r2)
			ball++;

		if (n1 <1 || n1>9 || n2 <1 || n2>9 || n3 <1 || n3 >9) 	// 1���� 9 ������ ���� �Էµ��� ���� ���
			printf("���� : ������ ���� ������ �Էµ��� ���� ���� �ֽ��ϴ�.\n");

		else if (n1 == n2 || n1 == n3 || n2 == n3)				// �Էµ� ���� �߿��� �ߺ��Ǵ� ���ڰ� �ִ� ���
			printf("���� : �Է��� ���� �߿� ���� �ߺ��Ǵ� ���� �ֽ��ϴ�.\n");

		else {   //�õ�Ƚ���� 1�� ���ϰ� ball, strike ������ ����Ѵ�.
			count++; 	
			if (ball != 0)
				printf("%d ball", ball);
			if (strike == 0)
				printf("!\n");

			if (strike != 0 && strike!=3) {
				if (ball != 0)
					printf(" ");
				printf("%d strike!\n", strike);
			}
		}

		//ball, strike �ʱ�ȭ
		ball = 0;
		strike = 0;
	}
	//������ �ԷµǸ�
	printf("�¸�!\n");
	printf("%dȸ!\n", count);
	printf("\n");

	//�õ�Ƚ���� ��ȯ�Ѵ�.
	return count;

}