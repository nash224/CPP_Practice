// 011_Overloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 오버로드는 함수에 과부하가 걸려도 상관 없다는 것으로 
// 함수의 이름에 과부하가 걸려도 상괎 없다는 것이다.
// 오버로드는 자신과 최대한 근접해있는 함수를 찾게 된다.

void print(int x)
{
    std::cout << "int : " << x << std::endl;
}

void print(char x)
{
    std::cout << "char : " << x << std::endl;
}
//
//void print(double x)
//{
//    std::cout << "double : " << x << std::endl;
//}

int main()
{
    int a = 1;
    char b = 'c';
    double c = 3.2f;

    print(a);
    print(b);
    //print(c);
    
    // 인자의 타입이 다르고, 타입이 2개 이상이 변환될 수 있다면 
    // 모호하다고 판단하여 오류가 발생한다.

    // 함수의 이름이 같더라도 인자가 다르면 다른 함수로 판단한다.
}