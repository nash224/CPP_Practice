// 005_FunctionPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <functional>


// 함수 객체는 함수처럼 행동하는 객체이다.
// 함수처럼 동작할려면 '()' 연산자를 정의해야한다. 이는 오버로딩한 객체이다.

void Print()
{
    std::cout << "전역 함수!" << std::endl;
}

struct Functor
{
    void operator()(int _value1, int _value2)
    {
        std::cout << " 함수객체: " << _value1 << "," << _value2 << std::endl;
    }
};

//Less는 템플릿 구조체이므로 호출할 때, 임시객체 Less<비교할 값의 타입>()으로 생성한다.
template<typename DataType>
struct Less
{
    bool operator() (DataType _value1, DataType _value2)
    {
        return _value1 < _value2;
    }
};

template<typename DataType>
struct Greater
{
    bool operator() (DataType _value1, DataType _value2)
    {
        return _value1 > _value2;
    }
};


// 정수를 누적하는 클래스
class Adder
{
private:
    int total = 0;

public:
    explicit Adder()
    {

    }

    explicit Adder(int _value1, int _value2)
    {
        total = _value1 + _value2;
    }

    int operator()(int _value)
    {
        return total += _value;
    }

    int GetTotal() const
    {
        return total;
    }
};

int main()
{
    {
        // Test는 객체이지만 (Test())철머 호출할 수 있다.
        Functor Test;

        Print();
        Test(3, 2);
        Test.operator()(3, 2);

        // 함수 객체는 일반 함수보다 복잡해 보이지만,
        // 함수 객체는 함수처럼 동작하는 객체이므로 멤버 변수와 멤버 함수를 가질 수 있다.
        // 그리고 함수 객체는 인라인될 수 있어 컴파일러가 쉽게 최적화할 수 있다.
    }

    {
        // 멤버 변수가 0으로 시작하는 객체를 operator함수를 사용하여 정수를 누적하도록 정의하고,
        //  암묵적으로 inline 함수가 된다.
        Adder Test;
        std::cout << Test(1000) << std::endl;
        std::cout << Test(300) << std::endl;
        std::cout << Test(60) << std::endl;
        std::cout << Test(7) << std::endl;
    }

    
    {
        system("cls");

        std::cout << Less<int>()(30, 20) << std::endl;
        std::cout << Less<int>()(70, 90) << std::endl;
        std::cout << Greater<int>()(40, 20) << std::endl;
        std::cout << Greater<int>()(30, 80) << std::endl;
        std::cout << std::endl;
    }

    {
        system("cls");

        Adder Add(20, 30);
        int sum = Add.GetTotal();

        int a = 0;

    }
}