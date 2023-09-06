#include <iostream>
#include <fstream> // 파일읽는 헤더파일 ifstream 사용가능
#include <string> 
using namespace std;

int main() { 
	string line;

	ifstream file("data.txt");   //열다
	
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}

	}
	
	
}