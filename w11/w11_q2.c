#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_board (char board[][8]);
int get_knight_move (char board[8][8]);
void disp_board (char board[][8]);
int x_position, y_position;

int main ()
{
	char board [8][8];
	int quit = 0;
	int i, j;

	srand( (unsigned) time( NULL ) );

	//�ʱ��� ����Ʈ�� ��ġ�� ������ ������ �����ش�.
	x_position = rand()%8;
	y_position = rand()%8;

	do {
		//ü������ �ʱ�ȭ�ϰ� ����Ʈ�� ��ġ�� �迭�� ǥ���Ѵ�.
		init_board(board);
		board[x_position][y_position] = 'A';
		
		//����Ʈ�� ������ �� �ִ� ��ġ�� ǥ���Ѵ�.
		for (i=0; i<8; i++) {
		for (j=0; j<8; j++) {
			if (x_position - i == 1 && y_position -j ==2 ) 
				board[i][j] = '0';
			if (x_position - i == 2 && y_position -j ==1 ) 
				board[i][j] = '0';
			if (x_position - i == -1 && y_position -j ==2 ) 
				board[i][j] = '0';
			if (x_position - i == -2 && y_position -j ==1) 
				board[i][j] = '0';
			if (x_position - i == 1 && y_position -j ==-2 ) 
				board[i][j] = '0';
			if (x_position - i == 2 && y_position -j ==-1 ) 
				board[i][j] = '0';
			if (x_position - i == -1 && y_position -j ==-2 ) 
				board[i][j] = '0';
			if (x_position - i == -2 && y_position -j ==-1 ) 
				board[i][j] = '0';
			}
		}
		disp_board(board);
		quit = get_knight_move(board);
	} while(quit == 0);

	return 0;

}

//ü������ �ʱ�ȭ�Ѵ�.
void init_board(char board[][8])
{
	int x, y;
	for (x=0; x<8; x++) {
		for (y=0; y<8; y++) {
			board[x][y] = ' ';
		}
	}
}

//����ڰ� ��� ��ġ�� �̵��� �� �Է¹޴´�.
int get_knight_move (char board[8][8]) {
	int x, y, done = 0;
	int i, j;
	while(done != 1) {
		printf("����Ʈ�� ������ ��ǥ�� �Է��ϼ���\n");
		printf("0~7 ���� ���� ���� �Է��ϸ� �����մϴ� : ");
		scanf("%d %d", &x, &y);
		if (x<0 || x>7 || y<0 || y>7) {
			printf("�����մϴ�\n");
			return 1;
		}
		if (board[x][y] == '0') {
			x_position = x;
			y_position = y;
			return 0;
		}
		else {
			printf("������ �� ���� ��ǥ�Դϴ�.\n\n");
		}
	}
	return 0;
}

//����Ʈ�� ��ġ�� ����Ʈ�� ���� �̵��� �� �ִ��� ǥ�õ� ü������ ����Ѵ�.
void disp_board(char board[8][8])
{
	int i, j;
	for (i=0; i<8; i++) {
		printf("|---|---|---|---|---|---|---|---|\n");
		for (j=0; j<8; j++) {
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
	}
	printf("|---|---|---|---|---|---|---|---|\n");
}