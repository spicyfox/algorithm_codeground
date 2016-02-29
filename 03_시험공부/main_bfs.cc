// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a):(b))

int *DATA;
int N;
int S;

bool *VISITED;

int RESULT;

void solve(int depth, int sum) {

	if (depth == S) {
		if (RESULT < sum) {
			RESULT = sum;
		}
		return;
	}

	for(int i = 0; i < N && VISITED[i] == false; i++) {
		VISITED[i] = true;
		solve(depth + 1, sum + DATA[i]);
		VISITED[i] = false;
	}
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
	for(test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		scanf("%d %d", &N, &S);    
       	DATA = new int[N];
       	VISITED = new bool[N];
       	RESULT = 0;
       	for(int i = 0; i < N; i ++) {
       		VISITED[i] = false;
       	}

       	for(int i = 0; i < N; i++) {
       		scanf("%d", &DATA[i]);
       	}
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		solve(0, 0);
		printf("%d\n", RESULT);

		delete[] DATA;        
		delete[] VISITED;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}