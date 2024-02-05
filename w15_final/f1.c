//�ܼ��ϰ� �� ���� ���ڿ��� ������ �ٸ����� �Ǵ��ϴ� my_strcmp �Լ�
#include <stdio.h>

int my_strcmp(const char *str1, const char *str2);

int main(void) {
	char str1[100], str2[100];
	while (1) {
		printf("Enter two words (q for quit):");
		scanf("%s", str1);
		if (str1[0] == 'q') break;	//q�� �ԷµǸ� �ݺ��� �����Ѵ�.
		scanf("%s", str2);
		if (my_strcmp(str1, str2)) printf("same\n");
		else printf("different\n");
	}
return 0;
}

int my_strcmp(const char *str1, const char *str2) {
	int i;
	int size1 = sizeof(str1)/sizeof(str1[0]);	//1�� ���ڿ��� ũ��
	int size2 = sizeof(str1)/sizeof(str1[0]);	//2�� ���ڿ��� ũ��

	if(size1 != size2) return 0;	//ũ�Ⱑ �ٸ��� �ݵ�� �ٸ� ���ڿ��̹Ƿ� ����
	for(i=0; i<size1; i++) {
		if (str1[i]!= str2[i])		//���ڿ� �߿��� �Ϻ� �ٸ� ���ڰ� �ִٸ� ����
			return 0;
	}
	return 1;	//���� ���˵��� �ʴ� ��� �� ���ڿ��� �����Ƿ� ��
}