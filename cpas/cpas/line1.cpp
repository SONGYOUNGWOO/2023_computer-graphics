#include <iostream>
#include <random>
#include <chrono>
#include <cstring>

using namespace std;
using std::cout;
unsigned seed = chrono::system_clock::now().time_since_epoch().count();

default_random_engine dre(seed);		//랜던값엔진 seed 따라 고정된다 랜던값이
uniform_int_distribution<int> uid(0, 2); //랜덤값범위

// cout printf
// det 행렬식 값 
void det_three (int x[3][3]) {
	int dd= x[0][0] * (x[1][1] * x[2][2] - x[2][1] * x[1][2])

		- x[0][1] * (x[1][0] * x[2][2] - x[1][2] * x[2][0])

		+ x[0][2] * (x[1][0] * x[2][1] - x[1][1] * x[2][0]);
	cout << dd << endl;
}
void det_four(int x[3][3]) {



}

void rand(int x[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			x[i][j] = uid(dre);
			cout << x[i][j];
		}cout << endl;
	}
	cout << endl;
}
void Transposed(int x[3][3]) {
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			cout << x[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void H(int x[3][3]) {
	int th[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			th[i][j] = x[i][j];
			if ((i == 3) || (j == 3)) {
				th[i][j] = 0;
			}
			if ((i == 3) && (j == 3)) {
				th[i][j] = 1;
			}
			cout << th[i][j];
		}cout << endl;
		cout << endl;
	}
}


int main() {
	char ta[3];
	int x[3][3];
	int y[3][3];
	
	//0,1,2 난수 배열
	rand(x);
	rand(y);

	while (true) {

		cin >> ta;
		int ee = ta[0] - '0';
		// cin >> num;
		//문자인지 숫자인지 구별

		if (isdigit(ta[0]) == 0) {

			//m: 행렬의 곱셈
			if (strcmp(ta, "m") == 109) {
				int r[3][3];
					int i, j;
					for (i = 0; i < 3; i++)
					{
						for (j = 0; j < 3; j++)
						{
							r[i][j] = x[i][0] * y[0][j] + x[i][1] * y[1][j] + x[i][2] * y[2][j];
								cout << r[i][j];
						}
						cout << endl;
					}
				cout << endl;
				continue;
			}

			//a: 행렬의 덧셈

			if (strcmp(ta, "a") == 0) {
				int r[3][3];
				int i, j;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						r[i][j] = x[i][j] + y[i][j];
						cout << r[i][j];
					}
					cout << endl;
				}
				cout << endl;
				continue;
			}
			//d: 행렬의 뺄셈

			if (strcmp(ta, "d") == 0) {
				int r[3][3];
				int i, j;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						r[i][j] = x[i][j] - y[i][j];
						cout << r[i][j];
					}
					cout << endl;
				}
				cout << endl;
				continue;
			}
			//r: 행렬식의 값 (Determinant) void det 
			if (strcmp(ta, "r") == 0) {
				det_three(x);
				det_three(y);
				continue;
			}
			//t: 전치 행렬(Transposed matrix)과 그 행렬식의 값을 입력한 2개의 행렬에 모두 적용한다.
			if (strcmp(ta, "t") == 0) {
				Transposed(x);
				det_three(x);
				Transposed(y);
				det_three(y);
				continue;
			}
			//h: 3X3 행렬을 4X4 행렬로 변환하고 행렬식의 값 (4행4열 행렬식 값) 출력
			if (strcmp(ta, "h") == 0) {
				H(x);
				H(y);
				continue;
			}
			//s: 행렬의 값을 새로 랜덤하게 설정한다.
			if (strcmp(ta, "s") == 0) {
				rand(x);
				rand(y);
				continue;
			}
			//q: 프로그램 종료
			if (strcmp(ta, "q") == 0) {
				return 0;
			}

		}//숫자면
		else {//숫자 (1~9): 입력한 숫자를 행렬에 곱한다.
			
				int r[3][3];
				int i, j;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						r[i][j] = x[i][j] * ee;
						cout << r[i][j];
					}
					cout << endl;
				}
				cout << endl;
				continue;

			}


	}

}
