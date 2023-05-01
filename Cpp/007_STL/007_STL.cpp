// 007_STL.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>

// STL은 c++을 위한 라이브러리로서 컨테이너, 알고리즘, 반복자, 함수자를 제공한다.



int main()
{
    std::stack<int> TestStack;

    TestStack.push(10);
    TestStack.push(20);
    TestStack.push(30);
    TestStack.push(40);

    std::cout << TestStack.top() << std::endl;
    TestStack.pop();
    std::cout << TestStack.top() << std::endl;
    TestStack.pop();
    std::cout << TestStack.top() << std::endl;
    TestStack.pop();
    std::cout << TestStack.top() << std::endl;
    TestStack.pop();
    //std::cout << TestStack.top() << std::endl; // Error 반복자가 nullptr을 가리키고 있어서 터짐
}
