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
void det(int x[3][3]) {
	int dd= x[0][0] * (x[1][1] * x[2][2] - x[2][1] * x[1][2])

		- x[0][1] * (x[1][0] * x[2][2] - x[1][2] * x[2][0])

		+ x[0][2] * (x[1][0] * x[2][1] - x[1][1] * x[2][0]);
	cout << dd;
}

int main() {
	char ta[3];
	int x[3][3];
	int y[3][3];
	int num = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			x[i][j] = uid(dre);
			cout << x[i][j];
		}cout << endl;
	}cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			y[i][j] = uid(dre);
			cout << y[i][j];
		}cout << endl;
	}cout << endl;

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
				det(x);
				cout << endl;

				det(y);
				cout << endl;
		
				continue;
			}
			//t: 전치 행렬(Transposed matrix)과 그 행렬식의 값을 입력한 2개의 행렬에 모두 적용한다.

			if (strcmp(ta, "t") == 0) {
				int r[3][3];
				int i, j;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						r[i][j] = x[j][i];
						cout << r[i][j];
					}
					cout << endl;
				}
				cout << endl;
				continue;
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
