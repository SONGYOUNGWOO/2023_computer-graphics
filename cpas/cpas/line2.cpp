#include <iostream>
#include <fstream> // �����д� ������� ifstream ��밡��
#include <string> 
using namespace std;

int main() { 
	string line;

	ifstream file("data.txt");   //����
	
	if (file.is_open()) {
		while (getline(file, line)) {
			cout << line << endl;
		}

	}
	
	
}