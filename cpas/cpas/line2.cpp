#include <iostream>
#include <fstream> // �����д� ������� ifstream ��밡��
#include <string> //getline �Լ� ���

using namespace std;

int main() {
    ifstream file{ "data.txt" };   // ������ ���ÿ� ����.

    char c;
    file >> noskipws;               //���� ���� x, �޸��� �״��
    int word_count = 0;
    int number_count = 0;
    int upper_count = 0;

    //�� �پ� �б� , etline �Լ��� ���Ͽ��� ���๮�� (\n) �� ���� �� ���� �ִ� ������ ũ�� - 1 ��ŭ �аԵ˴ϴ�
    // EOF��� �Է��� ��ҵǰ� cin.eof()�� true�� ��ȯ�Ѵ�. 
    // �̸� �̿��Ͽ� ������ ����� ������ �Է��� �޴� �ڵ带 �ۼ��� �� �ִ�.

    int number;
    bool num = false; // �´� �ƴϴ�

    std::string str;

    // ���� ��ü�� �о� ���ڿ��� �����մϴ�.
    file.seekg(0, ios::beg);
    file.read(&str[0], str.capacity());
  

    while (file >> c) {
        cout << c;
        
 


        // �������� Ȯ�� , \n
        if (isspace(c)) {              //�ڰ� ���ڿ�����
            if (num == true) {
                number_count++;
                num = false;
                
            }
            //                        //�ڰ� ���ڿ�����
            else if (num == false) {
                word_count++;
                num = true;
            }
        }
        // ����
        else if(isdigit(c)){
            if (num == true) {}     // ���� �� ����
            else 
            {
                num = true;         // ���� �� ����
            }
        }
        // ����
        else if (isalpha(c)) {
          
            if (num == false) {}    // ���� �� ����
            else if (num == true) {  // ���� �� ����
                num = false;
            }
            else {
                num = false;        // ���� �� ����
            }
        }
        else if (isupper(c)) {
            upper_count++;
        }
        
        //Ư������ üũ
        else {
            num = false;
        }
         

       
    }

    cout << endl << endl;
    
    cout << "word count:: " << word_count << endl;
    cout << "number count: " << number_count << endl;
    cout << "Capital word: " << upper_count << endl;

}

       




	
	



   
   


