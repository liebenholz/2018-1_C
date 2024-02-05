//단순하게 두 개의 문자열이 같은지 다른지만 판단하는 my_strcmp 함수
#include <stdio.h>

int my_strcmp(const char *str1, const char *str2);

int main(void) {
	char str1[100], str2[100];
	while (1) {
		printf("Enter two words (q for quit):");
		scanf("%s", str1);
		if (str1[0] == 'q') break;	//q가 입력되면 반복을 종료한다.
		scanf("%s", str2);
		if (my_strcmp(str1, str2)) printf("same\n");
		else printf("different\n");
	}
return 0;
}

int my_strcmp(const char *str1, const char *str2) {
	int i;
	int size1 = sizeof(str1)/sizeof(str1[0]);	//1번 문자열의 크기
	int size2 = sizeof(str1)/sizeof(str1[0]);	//2번 문자열의 크기

	if(size1 != size2) return 0;	//크기가 다르면 반드시 다른 문자열이므로 거짓
	for(i=0; i<size1; i++) {
		if (str1[i]!= str2[i])		//문자열 중에서 일부 다른 글자가 있다면 거짓
			return 0;
	}
	return 1;	//위에 저촉되지 않는 경우 두 문자열이 같으므로 참
}