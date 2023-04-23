// 006_Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 함수 오버로딩을 이용하면 매개변수 리스트가 다른 3 함수를 저으이할 수 있지만,
// 함수 오버로딩은 매개변수의 타입을 미리 알고 있는 전제로 만들어진다.
// 따라서 필요한 함수의 매개변수 타입에 맞춰 매번 함수를 정의해야하는 번거로움이 생긴다.
// 이러한 문제는 템플릿을 이용하면 문제를 간단히 해결할 수 있다.

// 템플릿은 함수 템플릿과 클래스 템플릿이 있다.
// 함수 템플릿은 여러 함수를 만들어내는 함수의 틀이다.
// 클래스 템플릿은 함수 템플릿과 마찬가지로 여러 클래스를 만들어내는 클래스의 틀이다.

// 템플릿 함수를 사용하면 클라이언트의 함수 호출 인자의 타입을 보고
// 클래스의 매개변수 타입을 결정하여 인스턴스 함수를 만들어 낸다.


// 템플릿을 이용하여 실수와 문자열을 출력하는 템플릿 함수를 선언한다
// Print 함수의 형식은 template<typename DataType> void Print(DataType _Arg);이다.
template<typename DataType>
void Print(DataType _Arg)
{
    std::cout << _Arg << std::endl;
}

int main()
{
    char StringA[6] = "Hello";

    Print<float>(5.5);
    Print<char*>(StringA);
    Print("Hi");
}