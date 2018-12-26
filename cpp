// 출력 테스트
#include<iostream>
using namespace std;

int main() {
	cout << "이름을 입력하세요>>";

	char name[11];//한글은 5개 글자, 영문은 10까지 저장할 수 있다.
	cin >> name;//키보드로부터 문자열을 읽는다.

	cout << "이름은" << name << "입니다\n";//이름을 출력한다.
}


// 사각형 면접 구하기
#include<iostream>
using namespace std;

int main() {
	cout << "너비를 입력하세요>>";
	int width;
	cin >> width;//키보드로부터 너비를 읽어 width 변수에 저장
	cout << "높이를 입력하세요>>";
	int height;
	cin >> height;//키보드로부터 높이를 읽어 height 변수에 저장
	int area = width * height;// 사각형의 면적 계산
	cout << "면적은" << area << "\n";//면적을 출력하고 다음 줄로 넘어감

}


// 패스워드 테스트
#include "pch.h"
#include<iostream>
#include <cstring>
using namespace std;

int main() {
	char password[11];
	cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
	while (true) {
		cout << "암호>>";
		cin >> password;
		if (strcmp(password, "C++test") == 0) {
			cout << "프로그램을 정상 종료합니다." << endl;
			break;
		}
		else
			cout << "암호가 틀립니다~~" << endl;
	}
}


// 가수이름 맞추기
#include<iostream>
#include<string>//string 클래스를 사용하기 위한 헤더 파일
using namespace std;

int main() {
	string song("Falling in love with you");//문자열 song
	string elvis("Elvis Presley");//문장열 elvis
	string singer;//문자열 singer

	cout << song + "를 부른 가수는";//+로 문자열 연결
	cout << "(힌트:첫글자는" << elvis[0] << ")?";//[]연산자 사용

	getline(cin, singer);//문자열 입력, getline()은 string 타입의 문자열을 입력받기 위해 제공되는 전역함수, 빈칸을 포함하는 문자열 입력 가능
	if (singer == elvis)//문자열 비교
		cout << "맞았습니다.";
	else
		cout << "틀렸습니다." + elvis + "입니다." << endl;//+로 문자열 연결
}




// 회원가입시 암호 두 번 입력
#include<iostream>
#include <cstring>
using namespace std;

int main() {
	char password1[100];
	char password2[100];
	cout << "새 암호를 입력하세요>>";
	cin >> password1;
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> password2;

	if (strcmp(password1, password2) == 0)
		cout << "같습니다";
	else
		cout << "같지 않습니다";
	cout << endl;

}



// 동적 할당 된 배열에 데이터를 입출력
#include<iostream>
using namespace std;
void main() {
	int *ptr;
	int size;

	cout << "동적 할당 할 크기를 입력하시오:";
	cin >> size;
	ptr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> *(ptr + i);
		cout << ptr[i] << endl;
	}
	delete[]ptr;

}


// 문자열 길이 출력
#include<iostream>
using namespace std;
void main() {
    char str[100];

    cout << "문자열 입력" << endl;
    cin.getline(str, 100);

    for (int i = 0; strlen(str) > i; i++)
        cout << str[i];
    cout << endl << endl;
    cout << "str의 길이:" << strlen(str) << endl;

}

// 점수 합계
#include<iostream>
using namespace std;

typedef struct jumsu{
int kor,eng,math;
}jum;
int sum(jum st){
int sum;
sum=st.kor+st.eng+st.math;
return sum;
}
void main(){
jum st ={95, 80, 20};
cout <<"총점="<<<sum(st)<<endl;
}


접근 권한

Private
- 클래스 내부에서만 접근이 가능
Public
- 클래스 내부, 외부 모두 접근이 가능하다
Protected
- 일반적인 경우에는 Private와 동일하게 클래스 내부에서만 접근이 가능하지 동작하지만 상속 시에만 자식클래스에서도 접근이 가능하다

// 생성자의 인자가 2개일 경우 작은 수부터 큰 수까지의 합
#include<iostream>
using namespace std;
class SUM {
private:
	int x, y;
public:
	SUM() { x = 1; y = 10; }
	SUM(int i) { x = 1; y = i; }
	SUM(int i, int z) { x = i; y = z; }
	int sumf() {
		int i, sum = 0;
		if (x < y)
			for (i = x; i <= y; i++)
				sum += i;
		else
			for (i = y; i <= x; i++)
				sum += i;
		return sum;
	}
	void print() {
		cout << x << " ~ " << y << "까지의 합은 : " << sumf() << endl;
	}
};
void main() {
	SUM a;
	a.print();
	int x;
	cin >> x;
	SUM aa(x);
	aa.print();
	int p1, p2;
	cin >> p1 >> p2;
	SUM aaa(p1, p2);
	aaa.print();
}


// 년차에 따른 호봉 지급
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
class Pay{
    double total[10];
public:
    Pay(){
        for(int i=0; i<10;i++)
            total[i] = 0;
    }
    void set_total(int money);
    double get_total(int i){  return total[i];  }
    void display_pay();
};
void Pay::set_total(int money){
    srand(time(NULL));
        total[0] = money;
        if(money >= 3000)
            for(int i=1; i<10; i++)
                total[i] = total[i-1] * (1.0+(rand()%3+3)/100.0);
        else
            for(int i=1; i<10; i++)
                total[i] = total[i-1] * (1.0+(rand()%11+10)/100.0);
}
void Pay::display_pay(){
    int money;
    double don;
    cout <<"초봉을 입력 하세요(만원단위) : ";
    cin >> money;
    set_total(money);
    for(int i=0;i<10;i++){
        don=get_total(i);
        cout << i+1 <<"년차 : "<< don<<"만원"<<endl;
    }
}
void main(){
    Pay aa;
    aa.display_pay();
    system("pause");
}


// 배열 학생관리
#include<iostream>
#include<cstring>
#define max_len 100
using namespace std;
class Std {
	char name[50];
	int kor, eng, math, sum;
	double avg;
	int num;
public:
	Std();
	void set_name(Std *arr);
	void set_jumsu(Std * arr);
	void set_stdname(Std * arr);
	void set_sum(Std * arr);
	void set_avg(Std * arr);
	void display(Std * arr);
};
Std::Std() {
	for (int i = 0; i < max_len; i++) {
		kor = 0; eng = 0; math = 0; sum = 0; avg = 0; num = 0;
		for (int j = 0; j < 50; j++)
			name[j] = 0;
	}
}
void Std::set_name(Std * arr) {
	char name[50];
	cout << "이름 입력 : "; cin >> name;
	for (int i = 0; i < max_len; i++) {
		if (!strcmp(arr[i].name, name)) {
			cout << "같은 이름이 있습니다" << endl;
			return;
		}
	}
	for (int i = 0; i < max_len; i++) {
		if (!arr[i].num) {
			strcpy(arr[i].name, name);
			arr[i].num = 1;
			cout << "등록 되었습니다" << endl;
			return;
		}
	}
}
void Std::set_jumsu(Std * arr) {
	char name[50];
	cout << "이름 입력 : "; cin >> name;
	for (int i = 0; i < max_len; i++) {
		if (!strcmp(arr[i].name, name)) {
			cout << "국 , 영 , 수 입력" << endl;
			cin >> arr[i].kor >> arr[i].eng >> arr[i].math;
			arr[i].sum = arr[i].kor + arr[i].eng + arr[i].math;
			arr[i].avg = arr[i].sum / 3.0;
			cout << "입력 완료" << endl; return;
		}
	}
	cout << "등록 되어 있지 않습니다." << endl;
}
void Std::set_stdname(Std * arr) {
	for (int i = 0; i < max_len; i++) {
		if (arr[i].num == 1)
			cout << arr[i].name << endl;
	}
}
void Std::set_sum(Std * arr) {
	char name[50];
	cout << "이름 입력 : ";
	cin >> name;
	for (int i = 0; i < max_len; i++) {
		if (!strcmp(arr[i].name, name)) {
			cout << "3과목의 합 : " << arr[i].sum << endl;
			return;
		}
	}
	cout << "등록 되어 있지 않습니다." << endl;
}
void Std::set_avg(Std * arr) {
	char name[50];
	cout << "이름 입력 : ";
	cin >> name;
	for (int i = 0; i < max_len; i++) {
		if (!strcmp(arr[i].name, name)) {
			cout << "3과목 평균 : " << arr[i].avg << endl;
			return;
		}
	}
	cout << "등록 되어 있지 않습니다." << endl;
}
void Std::display(Std * arr) {
	int sel;
	while (true) {
		cout << "1.학생이름 입력" << endl;
		cout << "2.성적 3과목 입력" << endl;
		cout << "3.학생 이름 출력" << endl;
		cout << "4.합계 출력" << endl;
		cout << "5.평균 출력" << endl;
		cout << "0.종료" << endl;
		cin >> sel;
		switch (sel) {
		case 1:set_name(arr); break;
		case 2:set_jumsu(arr); break;
		case 3:set_stdname(arr); break;
		case 4:set_sum(arr); break;
		case 5:set_avg(arr); break;
		case 0:return;
		default:cout << "잘못 입력 " << endl;
		}
		system("pause"); system("cls");
	}
}
void main() {
	Std arr[max_len];
	arr[0].display(arr);
}

// 핸드폰번호를 - 를 넣어서 출력 예를 들면 01033747217 를 입력하면 010-3374-7217 이 출력됩니다.
#include <iostream>
using namespace std;
class Number{
    char * num;
public :
    ~Number(){
        cout<<"동적할당 해제 "<<endl;
        delete num;
    }
    void set_num(char * str);
    char * get_num(){  return num;    }
    void display_number();
};
void Number::set_num(char * str){
    int i, j=0;

    num = new char[strlen(str)+3];
    if(str[1]=='2'){
        for(i=0;i<strlen(str);i++){
            if(i==2||i==6){
                num[j]='-';    
                j++;
            }
            num[j]=str[i];
            j++;
        }
    }
    else{
        for(i=0; i<strlen(str); i++){
            if( i == 3 || i == 7){
                num[j] = '-';
                j++;
            }
            num[j]=str[i];
            j++;
        }
    }
    num[j] = '\0';
}
void Number::display_number(){
    char num[20]="\0";
    
    cout <<"핸드폰 번호를 입력 하세요 : ";
    cin >> num;
    set_num(num);
    cout<<get_num()<<endl;
}

void  main(){
    Number aa;
    aa.display_number();
}

