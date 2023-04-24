// Practice_DanglingPointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <LeakCheck/Leak.h>

class Pointer
{
private:
    int X = 0;
    int Y = 0;

public:
    void Print()
    {
        std::cout << "Print() 호출" << std::endl;
    }

    int PrintInt()
    {
        std::cout << "PrintInt() 호출" << std::endl;
        return 1;
    }

    void PrintMalloc()
    {
        this->X = 100; // 예외가 throw됨
        std::cout << "PrintMalloc() 호출" << std::endl;
    }
};

int main()
{
    Base::LeckCheck();

    {

        // 컴파일 되는 이유
        // => 클래스는 사용자 정의 자료형으로서 멤버 함수 내부에서 this를 사용하는 연산을 했을 때,
        // 동적으로 할당받은 메모리에 접근하는 것이다.
        // 따라서 메모리를 해제해줬어도 멤버 변수를 사용하지 않는다면 컴파일이 된다.
        Pointer* Ptr = new Pointer();
        delete Ptr;
        Ptr = nullptr;
        Ptr->Print();
        Ptr->PrintInt();
        //Ptr->PrintMalloc();
    }

    {
        // 레퍼런스 카운트 방식으로 관리가 가능하다
        Pointer* BasicPtr = new Pointer();
        Pointer* SharedPtr = new Pointer();
        std::shared_ptr<Pointer> Ptr1 = std::shared_ptr<Pointer>(SharedPtr);
        Ptr1 = std::shared_ptr<Pointer>(BasicPtr);
        std::shared_ptr<Pointer> Ptr2 = std::shared_ptr<Pointer>(Ptr1);

        // 원본 데이터는 최초에 std::shared_ptr<T>에 들어가게 되면 레퍼런스 카운터가 1증가된다.
        // 이것은 use_count()라는 함수를 통해 확인할 수 있다.

        std::cout << Ptr1.use_count() << std::endl;

        int a = 0;
    }// std::shared_ptr<T>가 소멸될 때 레퍼런스 카운트는 0이 되면서 관리하는 포인터를
    // 스마트 포인터가 자동으로 delete하는 방식으로 동작한다.
}