//������ my_strcat() �Լ� ���� ���α׷�.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100	//���ڿ� �迭�� ũ��

char * my_strcat(char *target, const char *src, const int len) {
	int i = strlen(target);	//target ���ڿ� ����
	int j = strlen(src);	//src ���ڿ� ����
	int k = 0;
	//���ڿ� ������ ����� ��쿡�� strcat(dest, src)�� �״�� ����Ͽ� ���ڿ��� �����Ѵ�.
	if (i+j < len)
		strcat(target, src);
	//���ڿ� ������ ������� �ʴٸ� ������ ũ�⸸ŭ�� �߷��� ���ڿ��� �����Ѵ�.
	else {
		printf("��� : ���ڿ� ������ �ʰ��Ͽ� �Ϻ� �߸� ���ڿ��� ����մϴ�.\n");
		while (i+k < len-1) {
			target[i+k++] = src[k];	//�ش� �������� �����Ѵ�.
		}
		target[i+k] = NULL;			//���ڿ� �迭�� ������ �ڸ����� NULL�� ������ �Է��� ��ģ��.
	}
}

int main(void){
	char str1[SIZE], str2[SIZE];
 
	while(1) {
		//ù���� ���ڿ� �Է�(q�� �ԷµǸ� ����)
		printf("Enter string1:");
		gets(str1);
		if (str1[0] == 'q')
			return 0;

		//�ι�° ���ڿ� �Է�
		printf("Enter string2:");
		gets(str2);
		//���ڿ� �����ϰ� ����
		my_strcat(str1, str2, SIZE);
		//����� ���ڿ� ���
		printf("result:%s\n", str1);
	}
	return 0;
}