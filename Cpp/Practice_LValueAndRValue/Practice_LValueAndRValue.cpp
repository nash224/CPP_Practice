// Practice_LValueAndRValue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int Func()
{
    return 0;
}

int main()
{
    int TestInt = 0;

    // LValue 레퍼런스 :
    // 메모리가 확실히 존재하고 위치를 식별할 수 있는 변수들만 대입이 가능
    int& LeftRef1 = TestInt;
    // 메모리가 명확하지 않은 Rvalue들의 참조가 불가능
    // 
    //int& LeftRef2 = Func(); // '비const 참조에 대한 초기 값은 lvalue여야 합니다.'


    // RValue 레퍼런스
    // lvalue레퍼런스와는 반대로 메모리 위치가 명확한 lvalue에 대한 참조가 불가능하다.
    //int&& RightRef1 = TestInt; // 'rvalue참조를 lvalue에 바인딩할 수 없습니다.'

    int&& RIghtRef2 = Func();
}
