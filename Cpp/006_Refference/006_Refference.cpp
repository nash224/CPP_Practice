// 006_Refference.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 함수에서 메모리가 종료되면 안의 변수도 삭제되는데, 참조를 써봤자
// 이미 삭제된 메모리의 변수는 읽지 못한다.
int& function0()
{
    int a = 5;
    return a;
}

int function1(int& _d)
{
    _d = 50;
    return _d;
}

int function2()
{
    int a = 10;
    return a;
}



// 함수를 호출할 때마다 매번 새로운 레퍼런스 p가 호출 시 넘긴 인수로 바인딩된다.
// 즉 함수가 참조하고 삭제되면 참조한 p도 메모리에서 삭제되기 때문에 새로운 파라미터를 받을 수 있게된다.
int ChangeRef(int& p)
{
    p = 3;
    return p;
}

int main()
{
    // 
    int b = function0();
    int c = 0;

    int e = 18;

    //  function1은 아직 살아있는 변수 e를 계속 참조하고 있다.
    int f = function1(e);
    int g = 0;

    // 함수의 리턴값을 참조할 수 없다.
    // why?  => 함수는 실행이 끝나면 종료를 하게되는데 리턴값은 해당 문장이 끝나면 사라지기 때문이다.
    //int& h = function2();


    // 예외 법칙

    // 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값은 연장이된다.
    const int& Ref = function2();

    int va = 30;

    int Value = 50;

    std::cout << "Value의 값 :" << Value << std::endl;

    ChangeRef(Value);

    std::cout << "Value의 값 :" << Value << std::endl;

    ChangeRef(va);

    std::cout << "va의 값 :" << va << std::endl;


}