//���ڿ� ġȯ �����ϴ� �Լ�
#include <stdio.h>
#include <string.h>
#define SIZE 100
char strn[SIZE];

char * strModify(char * str, char * currStr, char * newStr){

	// �ٲٷ��� ���ڿ��� ��ü ���ڿ� ���̺��� �� ��� ���� ���
	if (strlen(str) < strlen(currStr) || strlen(str) < strlen(newStr))	{
		printf("ġȯ�� ���ڿ��� ��ü ���ڿ����� ��ϴ�.\n");
	}

	// �����ϴ� ���ڿ��� ���� �ٸ��� ���� ���
	else if (strlen(currStr) < strlen(newStr))	{
		printf("���� ���ڿ��� ġȯ ��� ���ڿ����� ��ϴ�.\n");
	}
	else if (strlen(currStr) > strlen(newStr))	{
		printf("ġȯ ��� ���ڿ��� ���� ���ڿ����� ��ϴ�.\n");
	}

	// �����ϴ� ���ڿ��� ���� ���̰� ����(currStr�� ���� = newStr�� ����). 
	else if (strlen(currStr) == strlen(newStr)) {
		int i, j;
		for (i=0; i<strlen(str); i++)
			strn[i] = str[i];
		for (i=0; i<strlen(str); i++) {
			if (str[i] == currStr[0]) {
				for (j=0; j<strlen(currStr); j++) {
					// �Է��� ���ڿ��� ��ü ���ڿ� ���� �������� �ʴ´ٸ� ���� ���
					if (str[i+j] != currStr[j]) {
						printf("�Է��� ���ڿ��� ��� �������� �ʽ��ϴ�.\n");
						return strn;
					}
					else {
						str[i+j] = newStr[j];
					}
				}
			}
		}
	}
	return str;
}

int main(void) {
	char str[SIZE];
	char currStr[SIZE];
	char newStr[SIZE];
	char *rst;

	printf("���ڿ� �Է� : ");
	scanf_s("%s", str, SIZE);

	printf("���� : ");
	scanf_s("%s", currStr, SIZE);

	printf("���� : ");
	scanf_s("%s", newStr, SIZE);

	rst = strModify(str, currStr, newStr);

	printf("��� : %s\n", rst);

	return 0;
}
