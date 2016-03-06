#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 1000
#define DIRECTION_LEFT		0
#define DIRECTION_RIGHT 	1
#define DIRECTION_UP		2
#define DIRECTION_DOWN		3

char DATA[MAX][MAX] = {0,};
char BUF[MAX + 1];
int N;

char DIR[4][3] = {
	{DIRECTION_LEFT, DIRECTION_DOWN, DIRECTION_UP},
	{DIRECTION_RIGHT, DIRECTION_UP, DIRECTION_DOWN},
	{DIRECTION_UP, DIRECTION_RIGHT, DIRECTION_LEFT},
	{DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT}
};


void show_data() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", DATA[i][j]);
		}
		printf("\n");
	}
}

void clear_data() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DATA[i][j] = 0;
		}
	}
}


int solve() {
	int count = 0;

	int r = 0, c = 0;
	int direction = DIRECTION_RIGHT;

	while (r >= 0 && r < N && c >= 0 && c < N) {
		char type = DATA[r][c] % 10;

		if (type != 0) {
			if (DATA[r][c] < 10) {
				count++;
				DATA[r][c] += 10;
			}
		}

		direction = DIR[direction][type];
		switch (direction) {
		case DIRECTION_LEFT:
			c--;
			break;
		case DIRECTION_RIGHT:
			c++;
			break;
		case DIRECTION_UP:
			r--;
			break;
		case DIRECTION_DOWN:
			r++;
			break;
		}
	}

	return count;
}

int main(int argc, char** argv) {
	freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.

		scanf("%d", &N);
		for (int r =  0; r < N; r++) {
			scanf("%s", BUF);
			for (int c = 0; c < N; c++) {
				DATA[r][c] = BUF[c] - '0';
			}
		}

		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", solve());
		clear_data();
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}