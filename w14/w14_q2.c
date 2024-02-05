//문자열 치환 수행하는 함수
#include <stdio.h>
#include <string.h>
#define SIZE 100
char strn[SIZE];

char * strModify(char * str, char * currStr, char * newStr){

	// 바꾸려는 문자열이 전체 문자열 길이보다 긴 경우 오류 출력
	if (strlen(str) < strlen(currStr) || strlen(str) < strlen(newStr))	{
		printf("치환할 문자열이 전체 문자열보다 깁니다.\n");
	}

	// 변경하는 문자열이 서로 다르면 오류 출력
	else if (strlen(currStr) < strlen(newStr))	{
		printf("수정 문자열이 치환 대상 문자열보다 깁니다.\n");
	}
	else if (strlen(currStr) > strlen(newStr))	{
		printf("치환 대상 문자열이 수정 문자열보다 깁니다.\n");
	}

	// 변경하는 문자열은 서로 길이가 같음(currStr의 길이 = newStr의 길이). 
	else if (strlen(currStr) == strlen(newStr)) {
		int i, j;
		for (i=0; i<strlen(str); i++)
			strn[i] = str[i];
		for (i=0; i<strlen(str); i++) {
			if (str[i] == currStr[0]) {
				for (j=0; j<strlen(currStr); j++) {
					// 입력한 문자열이 전체 문자열 내에 존재하지 않는다면 오류 출력
					if (str[i+j] != currStr[j]) {
						printf("입력한 문자열이 대상에 존재하지 않습니다.\n");
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

	printf("문자열 입력 : ");
	scanf_s("%s", str, SIZE);

	printf("현재 : ");
	scanf_s("%s", currStr, SIZE);

	printf("수정 : ");
	scanf_s("%s", newStr, SIZE);

	rst = strModify(str, currStr, newStr);

	printf("결과 : %s\n", rst);

	return 0;
}
