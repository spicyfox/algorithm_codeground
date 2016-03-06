
#include <cstdio>
#include <iostream>
using namespace std;

int N, K;

#define ULLONG unsigned long long

ULLONG* LINE;


void init_line() {
	LINE[0] = 0;
	for (int i = 1; i < N * 2; i++) {
		if (i <= N) {
			LINE[i] = i + LINE[i - 1];
		} else {
			LINE[i] = N - (i % N) + LINE[i - 1];
		}
	}
}


ULLONG get_number(int line, int r, int c) {

	//printf("[%d] %d, %d\n", line, r, c);
	ULLONG num = 0;
	num = LINE[line - 1];
	if (line <= N) {
		if (line % 2 == 0) {
			num += line - c;
		} else {
			num += c + 1;
		}
	} else {	// line > N
		if (line % 2 == 0) {
			num +=  N - (line % N) - (c - (line % N));
		} else {
			num +=  c - ((line % N)) + 1;
		}
	}

	return num;
}


ULLONG get_number_legacy(int line, int r, int c) {

	//printf("[%d] %d, %d\n", line, r, c);
	ULLONG num = 0;
	if (line <= N) {

		for (int i = 1; i < line; i++) {
			num += i;
		}
		if (line % 2 == 0) {
			num += line - c;
		} else {
			num += c + 1;
		}
	} else {	// line > N
		int i = 1;
		for (; i <= N; i++) {
			num += i;
		}
		for (; i < line; i++) {
			num +=  N - (i % N);
		}
		if (line % 2 == 0) {
			num +=  N - (line % N) - (c - (line % N));
		} else {
			num +=  c - ((line % N)) + 1;
		}
	}

	return num;
}

ULLONG solve() {

	scanf("%d %d", &N, &K);

	LINE = new ULLONG[N * 2];
	init_line();

	char ch;
	int count = K;
	int r = 0, c = 0;
	int line = 1;
	ULLONG sum = 0l;
	while (count > 0) {
		scanf("%c", &ch);
		bool read = true;
		if (ch == 'R') {
			c++;
			line++;
		} else if (ch == 'L') {
			c--;
			line--;
		} else if (ch == 'U') {
			r--;
			line--;
		} else if (ch == 'D') {
			r++;
			line++;
		} else {
			read = false;
		}
		//intf("%c", ch);
		if (read) {
			count--;
			sum += get_number(line, r, c);
		}

	}
	delete[] LINE;

	//intf("\n");

	return (1 + sum);
}

int main(int argc, char** argv) {
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	   만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	   그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	   또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	   단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("sample_input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;


	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.


		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%llu\n", solve());

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}