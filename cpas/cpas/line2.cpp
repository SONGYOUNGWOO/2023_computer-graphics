#include <iostream>
#include <fstream> // 파일읽는 헤더파일 ifstream 사용가능
#include <string> //getline 함수 사용

using namespace std;

int main() {
    ifstream file{ "data.txt" };   // 생성과 동시에 연다.

    char c;
    file >> noskipws;               //공백 무시 x, 메모장 그대로
    int word_count = 0;
    int number_count = 0;
    int upper_count = 0;

    //한 줄씩 읽기 , etline 함수는 파일에서 개행문자 (\n) 이 나올 때 가지 최대 지정한 크기 - 1 만큼 읽게됩니다
    // EOF라면 입력이 취소되고 cin.eof()는 true를 반환한다. 
    // 이를 이용하여 파일이 종료될 때까지 입력을 받는 코드를 작성할 수 있다.

    int number;
    bool num = false; // 맞다 아니다

    std::string str;

    // 파일 전체를 읽어 문자열에 저장합니다.
    file.seekg(0, ios::beg);
    file.read(&str[0], str.capacity());
  

    while (file >> c) {
        cout << c;
        
 


        // 공백임을 확인 , \n
        if (isspace(c)) {              //뒤가 숫자였으면
            if (num == true) {
                number_count++;
                num = false;
                
            }
            //                        //뒤가 문자였으면
            else if (num == false) {
                word_count++;
                num = true;
            }
        }
        // 숫자
        else if(isdigit(c)){
            if (num == true) {}     // 숫자 뒤 숫자
            else 
            {
                num = true;         // 공백 뒤 숫자
            }
        }
        // 문자
        else if (isalpha(c)) {
          
            if (num == false) {}    // 문자 뒤 문자
            else if (num == true) {  // 공백 뒤 문자
                num = false;
            }
            else {
                num = false;        // 숫자 뒤 문자
            }
        }
        else if (isupper(c)) {
            upper_count++;
        }
        
        //특수문자 체크
        else {
            num = false;
        }
         

       
    }

    cout << endl << endl;
    
    cout << "word count:: " << word_count << endl;
    cout << "number count: " << number_count << endl;
    cout << "Capital word: " << upper_count << endl;

}

       




	
	



   
   


