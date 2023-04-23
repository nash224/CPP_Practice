// 004_FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/////////////// 서버 ///////////////

// 서버는 어떤 기능이나 서비스를 제공하는 코드 측을 서버코드라고 한다.
// 클라이언트가 서버를 호출하면 콜(call)이라고 하고
// 서버가 클라이언트를 호출하면 콜백(callback)이라고 한다.
// 콜백 메커니즘은 클라이언트에서 유연하게 바꿀 수 있게 서버를 더 추상화할 수 있다.

// 함수의 전방선언
void Client();

void PrintHello()
{
    std::cout << "Hello!!" << std::endl;
    Client();
}


// 배열의 모든 원소에 반복적인 작업을 추상화함
// 인자를 배열, 배열, 함수를 가져와서 수행
void FromToPrint(int* begin, int* end, void (*PF)(int))
{
    while (begin != end)
    {
        PF(*begin++);
    }
}

void PrintArr(int _value)
{
    std::cout << _value << ' ';
}

void PrintSquareArr(int _value)
{
    std::cout << _value * _value << ' ';
}


void PrintStringArr(int _value)
{
    std::cout << "정수 : " << _value << std::endl;
}


// 함수는 정적 함수와 멤버 함수로 나뉜다.
// 정적 함수는 전역 함수, namespace 내의 전역 함수, static 멤버 함수가 있다.

// 멤버 함수는 객체와 주소로 각각 호출할 수 있어, 함수 호출은 세 가지가 있다.

// 1. 정적 함수 호출(정적 함수)
// 2. 객체로 멤버 함수 호출(멤버 함수)
// 3. 객체의 주소로 멤버 함수 호출(멤버 함수)

class Point
{
public:
    // 피호출자
    void Print()
    {
        std::cout << "Point 클래스의 멤버 함수 Print()" << std::endl;
    }

    static void StaticPrint(int _value)
    {
        std::cout << "Point 클래스의 정적 멤버 함수 Print() : " << _value << std::endl;
    }
};

class int2
{
private:
    int x;
    int y;

public:
    // explicit 키워드는 암시적인 형변환이 일어나지 않도록 제한하는 키워드이다.
    explicit int2(int _x, int _y)
        :x(_x), y(_y)
    {

    }

    void Print() const
    {
        std::cout << x << "," << y << std::endl;
    }

    void PrintInt(int _value)
    {
        std::cout << "value : " << _value << std::endl;
    }
};

namespace Name
{
    void StaticPrint(int _value)
    {
        std::cout << "namespace Name 전역 함수 : " << _value << std::endl;
    }
}


// 함수의 이름 == 함수가 시작하는 주소 : 03x5234
void Print(int _value)
{
    std::cout << "정수 : " << _value << std::endl;
}

void StaticPrint()
{
    std::cout << "정적 함수 Print()"  << std::endl;
}



/////////////// 클라이언트 ///////////////
int main()
{
    {
        // 정수형 변수 n : n의 값은 10 : n의 주소는 0x1234
        int n = 10;
        // 포인터형 변수 pn : pn의 값은 0x1234 : pn의 주소는 1x2354
        int* pn = &n;
    }

    {
        // 함수 포인터 == 함수의 주소를 저장하는 포인터 : 
        void (*pf) (int);

        // pf의 값 == 03x5234 
        pf = Print;

        int value = 30;

        // Print가 함수의 시작주소이므로 pf도 함수의 시작주소이다.
        // 그리고 Print() 서명은 void Print(int _value) 임으로
        // 함수 포인터 (*pf)(int)로 선언해야한다.
        // 함수 포인터는 메모리 접근 연선자(*)를 붙여도 함수 주소이다.
        // 그래서 pf와 *pf는 Print()함수의 주소이고 이 둘은 같은 문장이다.
        pf(20);
        pf(value);
        (*pf)(value);
        Print(value);

        std::cout << Print << std::endl;
        std::cout << pf << std::endl;
        std::cout << *pf << std::endl;
    }

    {
        Point Test;
        Point* Ptr = &Test;

        // 호출자
        StaticPrint(); // 정적 함수
        Test.Print(); // 멤버 함수(Test객체의 함수)
        Ptr->Print(); // 멤버 함수(Test를 가리키는 객체 포인터가 Test객체에서 함수를 호출)

    }

    {
        system("cls");
        
        void (*pf)(int);

        StaticPrint();
        Name::StaticPrint(29);
        Point::StaticPrint(20);

        // 정적 함수와 마찬가지로 namespace함수, 비정적 멤버 함수도
        // 포인터 함수를 사용할 수 있다.
        pf = Print;
        pf(10);
        pf = Name::StaticPrint;
        pf(20);
        pf = Point::StaticPrint;
        pf(50);

    }

    {
        int2 Test(3, 4);
        int2* Ptr = &Test;

        void (int2:: * PointerFunction1)() const; // 멤버 함수로 포인터 선언
        PointerFunction1 = &int2::Print;

        Test.Print();

        (Test.*PointerFunction1)();
        (Ptr->*PointerFunction1)();
    }

    {
        // 서버에서 클라이언트 측 코드인 Client()를 호출한다. 이를 콜백함수라고 한다.
        PrintHello();
    }

    {
        system("cls");

        int Arr[8] = { 10, 20, 30, 40, 50, 60, 70, 80 };

        // 클라이언트가 함수를 호출해서 클라이언트에 있는 Print 함수를 호출한다.
        FromToPrint(Arr, Arr + 7, PrintArr);
        std::cout << std::endl;
        FromToPrint(Arr, Arr + 7, PrintSquareArr);
        std::cout << std::endl;
        FromToPrint(Arr, Arr + 7, PrintStringArr);

    }
}


void Client()
{
    std::cout << "Client() 함수 호출" << std::endl;
}
