// 008_VectorContainer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>


// vector는 임의의 타입의 객체를 보관할 수 있는 컨테이너다.
// 벡터의 시간복잡도는 bigO(1)에 수렵할 정도로 정말 빠른 자료구조에 속한다.


void PrintCapAndSize(std::vector<int>& _Vec)
{
    std::cout << "capacity : " << _Vec.capacity() << std::endl;
    std::cout << "size : " << _Vec.size() << std::endl;
}


void isEmpty(const char* _Name ,std::vector<int>& _Vec)
{
    PrintCapAndSize(_Vec);

    if (true == _Vec.empty())
    {
        std::cout << _Name << "는 원소를 포함하지 않고 있습니다." << std::endl;
    }

}

template<typename DataType>
void Print(DataType _Type)
{
    std::cout << _Type << std::endl;
}

int main()
{
    std::vector<int> VecA;
    std::vector<int> VecC;

    // size()는 벡터의 크기를 리턴하는 함수이다

    

    size_t sizevalue = 0;
    sizevalue = VecA.size();
    size_t capacityvalue = 0;
    capacityvalue = VecA.capacity();

    // 벡터는 맨 뒤에 원소를 추가하거나 제거하기 위해서는 push_back() 나 pop_back()함수를 사용하면된다.
    VecA.push_back(10);
    VecA.push_back(20);
    VecA.push_back(30);
    VecA.push_back(40);
    VecA.push_back(50);

    // 벡터의 미리 할당된 공간이 부족하면 할당된 공간을 파괴하고 새롭게 기존보다 큰 메모리를 만들어
    // 깊은복사를 수행하고 메모리를 저장할 수 있게 된다. 그래서 할당된 메모리를 추가할때 복잡도는 O(1)이 되며,
    // 메모리를 파괴하고 새로운 공간을 만들어 복사할때는 O(N)의 시간복잡도를 가진다.

    // 하지만 임의에 존재하는 메모리에 데이터를 추가하고 싶거나 삭제할 때는 시간복잡도가 O(N)만큼 걸리며,
    // 함수로는 insert() 또는 erase()가 있다.
    // 그렇다고 해서 벡터가 다른 자료구조보다 더 느리다는 것은 아니지만, 
    // 어떤 작업을 할때, 어떤 자료구조를 사용하며, 적절한 컨테이너를 고르는 것이 중요하다


    // capacity는 벡터에 메모리를 추가할 떄, size를 넘어버리면 파괴 후 재할당하게 되는데, 매우 비효율적이
    // 될 수 있다. 따라서 미리 메모리를 추가하여 메모리 생성에 걸리는 비용을 줄이기 위해  
    // capacity를 사용해 어느정도 복잡도를 줄일 수 있게 도와준다. 
    // 

    std::cout << typeid(std::vector<int>::size_type).name() << std::endl;
    std::cout << VecA.max_size() << std::endl;
    std::cout << VecA.capacity()<< std::endl;

    // reserve()함수를 사용하면 함수의 인자만큼 미리 메모리 크기를 할당할 수 있어 메모리를 재할당하는 문제를
    // 해결할 수 있다.

    // VecA의 메모리를 20으로 키운다
    VecA.reserve(20);

    PrintCapAndSize(VecA);


    // resize()를 사용하면 메모리가 초과하는 만큼 capacity도 늘어나지만 메모리 크기를 줄일 때는
    // capacity의 크기는 줄어들지 않는다.
    VecA.resize(30);

    PrintCapAndSize(VecA);


    VecA.resize(7);

    PrintCapAndSize(VecA);

    isEmpty("VecC", VecC);

    VecC.reserve(4);

    isEmpty("VecC", VecC);

    VecC.push_back(5);

    // clear는 벡터의 요소를 전부 삭제 하지만 메모리는 계속 남아 있게 된다. 
    VecC.clear();

    isEmpty("VecC", VecC);
   
    VecC.swap(VecA);
    
    isEmpty("VecC", VecC);


    // front()함수는 Vector의 가정 첫번째 원소를 참조한다.
    int Frontvalue = 0;
    Frontvalue = VecC.front();

    Print(VecC.front());

    Print(VecC.back()); // 이전의 벡터 VecA에서 resize를 해주었기 떄문에 0이 마지막 원소로 0이 반환된다.

    // 또는 back()을 사용하여 마지막 원소를 참조하여 값을 변경할 수도 있다.
    VecC.back() = 400;
    Print(VecC.back());
}