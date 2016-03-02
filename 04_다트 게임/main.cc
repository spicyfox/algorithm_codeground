#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;


int RADIUS[5];
int N;
int SCORE[] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10};

float get_degree(int x, int y) {
    return atan((float)x / (float)y) * 180 / M_PI;
}

inline int score_index(int degree) {
    return (((degree  + 9) % 360) / 18);
}

int get_score(int x, int y, int multiply) {
    int index;
    if (x == 0) {
        index = y > 0 ? 5 : 15;
    } else if (y == 0) {
        index = x > 0 ? 0 : 10;
    } else {
        float degree;
        if (x > 0) {
            degree = y > 0 ? get_degree(y, x) : get_degree(-x, y) + 270;
        } else {
            degree = y > 0 ? get_degree(-x, y) + 90 : get_degree(-y, -x) + 180;
        }
        index = score_index(degree);
    }

    return SCORE[index] * multiply;
}

int solve(int x, int y) {
    float radius = sqrt(x * x +  y * y);

    int score = 0;
    if (radius <= RADIUS[0]) { // bull
        score = 50;
        //printf("Bull board [%d, %d] => %d\n", x, y, score);
    } else if (radius > RADIUS[1] && radius < RADIUS[2]) { // triple
        score = get_score(x, y, 3);
        //printf("Triple [%d, %d] => %d\n", x, y, score);
    } else if (radius > RADIUS[3] && radius < RADIUS[4]) { // double
        score = get_score(x, y, 2);
        //printf("Double [%d, %d] => %d\n", x, y, score);
    } else if ((radius > RADIUS[0] && radius < RADIUS[1]) || radius > RADIUS[2] && radius < RADIUS[3]) { // single ?
        score = get_score(x, y, 1);
        //printf("Single [%d, %d]=> %d\n", x, y, score);
    } else { // out board
        //printf("Out board [%d, %d]\n", x, y);
    }

    return score;
}

int main(int argc, char** argv) {
    //freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);

    int TC;
    int test_case;

    scanf("%d", &TC);
    for (test_case = 1; test_case <= TC; test_case++) {
        for (int i = 0; i < 5; i++) {
            scanf("%d", &RADIUS[i]);
        }
        scanf("%d", &N);
        int total = 0;
        int x, y;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &x, &y);
            total += solve(x, y);
        }

        printf("Case #%d\n", test_case);
        printf("%d\n", total);

    }
    return 0;
}