// TIp. 외부 변수든 내부 변수는 쪼잔해게 같은 변수명을 사용하지 말자 
// => 변수명은 확실히 구분하는 습관을 들이는게 좋다

#include <iostream>

// 정적 할당은 컴파일할 때, 메모리를 할당해서, 변수나 배열 등을 선언할 때, 
// 크기를 정하여 메모리에 할당한다.

// 동적할당은 프로그램 실행 중에 메모리를 할당할 수 있어,
// 실행되는 동안 필요한 만큼의 메모리를 할당할 수 있다.

// NULL 포인터 역참조 오류
void Memorycase1();

void Memorycase2();

void Memorycase3();

void Memorycase3();




int main()
{
    //Memorycase1();

    //Memorycase2();

    //Memorycase3();
}





// 역참조는 포인터로 선언된 포인터 변수의 주소에 저장된 값을 가져오는 것이다.
void Memorycase1()
{
    int* ptr;
    // nullptr은 실제로 메모리 공간을 할당받지 않은 상태이다
    ptr = nullptr;
    // 컴파일할 떄, 정적 할당에서 메모리 없는 공간에 메모리가 있는 것을 참조하는 것은 안된다.
    // 즉, 0에서 값을 찾는것과 같다.
    //*ptr = 10;
    //int value = *ptr;
}

void Memorycase2()
{
    int* ptr;   // 포인터 변수 선언
    ptr = nullptr; // 포인터 ptr에 nullptr로 초기화
    ptr = new int; // 메모리 공간을 할당받음
    *ptr = 10; // 포인터가 가리키는 메모리 공간에 값을 저장함


    // delete로 해제할 수 잇는 메모리 공간은 new를 통해서 할당된 공간만 가능하다.
    delete ptr; // 메모리 공간을 해제함
    
}

void Memorycase3()
{
    int* ptr;
    int value = 5;
    ptr = &value;

    int ptrvalue = *ptr;

    delete ptr;
}

void Memorycase3()
{
    int arr_size;
    std::cout << "array Size : " << std::endl;
    std::cin >> arr_size; 

    int* list = new int[arr_size];

    // 반복문을 사용하여 동적할당 선언된 배열에 값을 넣어줌
    for (size_t i = 0; i < arr_size; i++)
    {
        std::cin >> list[i];
    }

    // 각 배열의 값을 확인함
    for (size_t i = 0; i < arr_size; i++)
    {
        std::cout << i << "th element of list : " << list[i] << std::endl;
    }

    // 동적할당 받은 배열을 해제함
    delete[] list;
}