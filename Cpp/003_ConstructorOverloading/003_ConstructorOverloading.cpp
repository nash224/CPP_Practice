// 003_ConstructorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class ConA
{
    
};

class ConB
{
public:
    ConB()
    {
        std::cout << "ConB() 생성자 호출" << std::endl;
    }

    ConB(ConA& _ConA)
    {
        std::cout << "ConB(ConA& _ConA) 생성자 호출" << std::endl;
    }

    ConB(int _n)
    {
        std::cout << "ConB(int _n) 생성자 호출" << std::endl;
    }

    ConB(double _D)
    {
        std::cout << "ConB(double _D) 생성자 호출" << std::endl;
    }

    operator ConA()
    {
        std::cout << "operator ConA() 호출" << std::endl;
        return ConA();
    }

    operator int()
    {
        std::cout << "operator int() 호출" << std::endl;
        return 10;
    }

    operator double()
    {
        std::cout << "operator double() 호출" << std::endl;
        return 10.4;
    }
};

int main()
{
    ConA ConstructorA;
    int n = 4;
    double D = 5.3;

    // 특정 타입을 인자로 받는 생성자는 생성자 호출을 통한 타입 변환이 가능한다.
    ConB B;
    ConB C_Constructor(ConstructorA);
    ConB D_int(n);
    ConB E_Double(D);

    system("cls");

    // B의 특정 연산자를 호출하여 타입 변환 멤버 함수를 호출한다.
    ConstructorA = B;
    n = B;
    D = B;
    

}
