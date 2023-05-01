// 009_STLIterator.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#define PRINT FPtr

template<typename DataType>
void Print(DataType _Data)
{
    std::cout << _Data << std::endl;
}

typedef int INT;

int main()
{
    std::vector<INT> VecA;

    void (*FPtr)(int);
    PRINT = Print;

    VecA.push_back(10);
    VecA.push_back(20);
    VecA.push_back(30);
    VecA.push_back(40);
    VecA.push_back(50);

    // 벡터의 각 요소들은 반복자를 사용하여 원소의 값을 반환할 수 있다.
    // 예를들어 begin함수와 vector의 끝 또는 nullptr을 가리키는 end()함수를 사용하여
    // 순차적으로 돌며 자료를 순회하는 알고리즘이다. 

    // StartIter이라는 반복자 객체를 생성하여 반복문에서 순회를 돈다
    for (std::vector<int>::const_iterator StartIter = VecA.begin(); StartIter != VecA.end(); StartIter++)
    {
        PRINT(*StartIter);
    }
    std::cout << std::endl;

    // 반복자에 상수를 더하여 참조할 수도 있다.
    // 그리고 상수 반복자를 사용할 떄는 일반적으로 상수 반복자를 사용할 때는 컴파일러가 에러를
    // 발생하기 때문에 읽기 전용으로 접근해야한다.
    std::vector<int>::const_iterator StartIterB = VecA.begin();

    StartIterB += 1;
    
    PRINT(*StartIterB);
    //*StartIterB = *StartIterB + 2;
    //PRINT(*StartIterB);


    StartIterB += 1;
    std::vector<int>::const_iterator StartIterC = VecA.insert(StartIterB, 3, 100);
    PRINT(*StartIterC);


    for (; StartIterC != VecA.end(); StartIterC++)
    {
        PRINT(*StartIterC);
    }

    system("cls");

    std::cout << "Hello World!\n";
}
