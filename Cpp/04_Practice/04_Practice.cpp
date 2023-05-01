// 04_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <LeakCheck/Leak.h>

template<typename DataType>
void Copy(DataType& _Arr2, DataType& _Arr1, size_t _Count)
{
    for (size_t i = 0; i < _Count; i++)
    {
        _Arr2[i] = _Arr1[i];
        std::cout << _Arr2[i] << std::endl;
    }
    std::cout << std::endl;
}


template<typename DataType>
class Stack
{
public:
    Stack()
        : Size(0), Arr(nullptr)
    {

    }

    ~Stack()
    {
        delete[] Arr;
        Arr = nullptr;
    }

    DataType Push(const DataType& _value)
    {
        *Arr[Size] = new DataType(_value);
        Size++;
    }

    DataType Pop()
    {
        delete *Arr[Size];
        Size--;
    }

    bool Empty()
    {
        if (0 == Size)
        {
            return true;
        }
        return false;
    }


private:
    DataType** Arr;
    size_t Size;
    

};


int main()
{
    Base::LeakCheck();
    {

        int Arr1[5] = { 10, 20, 30, 40, 50 };
        int Arr2[5];

        Copy(Arr2, Arr1, 5);

    }

    {
        Stack<int> st;

        st.Push(10);
        st.Push(20);
        st.Push(30);

        if (!st.Empty())
        {
            std::cout << st.Pop() << std::endl;
        }
        if (!st.Empty())
        {
            std::cout << st.Pop() << std::endl;
        }
        if (!st.Empty())
        {
            std::cout << st.Pop() << std::endl;
        }
    }


}