// ������ ����ϰ� ¦��, Ȧ���� ������ Ƚ���� �ִ밪 ����ϱ�
// ����Լ��� ����� ��
#include <stdio.h>

void sequence(int n, int odd, int even, int max);

int main(void)
{
	int in;			//����ڰ� �Է��ϴ� ����
	int odd = 0;	//Ȧ�� ����
	int even = 0;	//¦�� ����
	int max = 1;	//�ִ밪

	printf(">> ");
	scanf("%d", &in);	//�� �Է�
	
	//������ ����ϰ� ¦�� ����, Ȧ�� ����, �ִ밪�� ����ϴ� �Լ�
	sequence(in, odd, even, max);

	return 0;
}

void sequence(int n, int odd, int even, int max)
{		

	printf("%d ", n);
	if (n==1) {   //���� ���ǰ� ����
		odd++;
		printf("\n");
		printf("¦�� %dȸ\n", even);
		printf("Ȧ�� %dȸ\n", odd);
		printf("max : %d\n", max);
	}
	else {
	    if (n>max) {
			max = n;	//�ִ밪 �����ϱ�
		}
		if(n%2 == 1) {  //Ȧ���� ��
			n = n*3 +1;
			odd++;
			return sequence(n, odd, even, max);
		}
		else {          //¦���� ��
			n= n/2;
			even++;
			return sequence(n, odd, even, max);
		}
	}

}