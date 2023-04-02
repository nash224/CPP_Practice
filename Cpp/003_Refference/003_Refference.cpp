
#include <iostream>

void Change_pValue(int* _Value)  //  매개변수에 주소를 받음
{
    *_Value = 10;   //  (Number의 주소)의 값을 10에 대입
}

void Change_rValue(int& _Value) // 매개변수에 참조자 _Value를 받음 => _Value 에게  니 이름은 이제부터 Number3의 별명이여
{
    _Value = 20;    // 참조자 _Value에 20을 대입
}

int main()
{
    int Number0 = 5;

    std::cout << Number0 << std::endl;

    Change_pValue(&Number0);  //  인자로 Number의 주소값을 줌

    std::cout << Number0 << std::endl;

    // 레퍼런스는 포인터와 달리 반드시 누군가를 명시해야한다.
    // 레퍼런스는 한 번 어떤 변수의 참조자가 되면, 다른 변수를 참조할 수 없게 된다.
    // 레퍼런스는 일반적으로 메모리상에 존재하지 않는다.

    int Number1 = 7;
    int& another_Number1 = Number1; // another_Number1은 a의 또다른 이름이다 
    another_Number1 = 3;

	std::cout << another_Number1 << std::endl;

    std::cout << Number1 << std::endl;

    another_Number1 = Number0;


    int Number2 = 111;
    int* Ptr_Number2 = &Number2;

    // 포인터 타입 참조자
    int*& another_Ptr_Number2 = Ptr_Number2;

    *another_Ptr_Number2 = 150;


    std::cout << *another_Ptr_Number2 << std::endl;
    std::cout << another_Ptr_Number2 << std::endl;
    std::cout << Ptr_Number2 << std::endl;


    int Number3 = 15;

    Change_rValue(Number3);
    std::cout << Number3<< std::endl;


    int x = 0;
    int& y = x;
    int& z = y;

    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
    y = 5;
    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;
    z = 7;
    std::cout << "x : " << x << ", y : " << y << ", z : " << z << std::endl;

}
