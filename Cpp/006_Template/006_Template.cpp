// 006_Template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include "TemplateForEach1.h"

// 함수 오버로딩을 이용하면 매개변수 리스트가 다른 3 함수를 저으이할 수 있지만,
// 함수 오버로딩은 매개변수의 타입을 미리 알고 있는 전제로 만들어진다.
// 따라서 필요한 함수의 매개변수 타입에 맞춰 매번 함수를 정의해야하는 번거로움이 생긴다.
// 이러한 문제는 템플릿을 이용하면 문제를 간단히 해결할 수 있다.

// 템플릿은 함수 템플릿과 클래스 템플릿이 있다.
// 함수 템플릿은 여러 함수를 만들어내는 함수의 틀이다.
// 클래스 템플릿은 함수 템플릿과 마찬가지로 여러 클래스를 만들어내는 클래스의 틀이다.

// 템플릿 함수를 사용하면 클라이언트의 함수 호출 인자의 타입을 보고
// 클래스의 매개변수 타입을 결정하여 인스턴스 함수를 만들어 낸다.


// 템플릿을 이용하여 실수와 문자열을 출력하는 템플릿 함수를 선언한다
// Print 함수의 형식은 template<typename DataType> void Print(DataType _Arg);이다.
template<typename DataType>
void Print(DataType _Arg)
{
    std::cout << _Arg << std::endl;
}

template<typename DataType1, typename DataType2>
void Print(DataType1 _Arg1, DataType2 _Arg2)
{
    std::cout << _Arg1 << "," << _Arg2 << std::endl;
}

template<typename DataType1, size_t Size>
void PrintArray(DataType1* _Arg1)
{
    for (size_t i = 0; i < Size; i++)
    {
        std::cout << "[" << i << "]: " << _Arg1[i] << std::endl;
    }
}

typedef int INT;
#define ZERO        0
#define CAP         100
#define BUFF        buffer
#define SIZE        size
#define CAPACITY    capacity
#define VOID        void
#define CONST       const

// 디폴트 매개변수 값을 int로 지정
template <typename DataType = INT>
class Array
{
private:
    DataType* BUFF;
    INT SIZE;
    INT CAPACITY;

public:
    explicit Array()
        : BUFF(ZERO), SIZE(ZERO), CAPACITY(CAP)
    {
        BUFF = new DataType[CAPACITY];
    }

    ~Array()
    {
        delete[] BUFF;
        BUFF = nullptr;
    }

    DataType operator[](INT _index) CONST
    {
        return BUFF[_index];
    }

    VOID Add(DataType _Data)
    {
        BUFF[SIZE++] = _Data;
    }

    INT Getsize() CONST
    {
        return SIZE;
    }

};


template<typename Datatype>
class TemTest
{
private:
    Datatype Data;

public:
    TemTest(const Datatype& _Data)
        : Data(_Data)
    {

    }


    void Print()
    {
        std::cout << "타입 : " << typeid(Data).name() << std::endl;
        std::cout << "크기 : " << sizeof(Data) << std::endl;
        std::cout << "값 : " << Data << std::endl;
    }

};

int main()
{
    {
        char StringA[6] = "Hello";

        // Print함수는 실제로 3개의 인스턴스 함수를 만들어냄
        Print<float>(5.5); // 실수 5.5를 확인하고 DataType을 float로 결정하여 Print 인스턴스 함수를 생성
        Print<char*>(StringA);
        Print<const char*>("Hi");

        Print<char*, int>(StringA, 10);

        // 즉 클라이언트가 집적 타입을 명시적으로 지정하고 호출할 수 있다.
    }


    {
        int Arr1[5] = { 10, 20, 30, 40, 50 };
        PrintArray<int, 5>(Arr1);


        double Arr2[5] = { 10.4, 20.3, 30.7, 40.1, 50.2 };
        PrintArray<double, 5>(Arr2);
    }

    {
        // 템플릿 인자타입을 통해 클라이언트가 클래스에 사용될 타입을 정할 수 있다.
        // 클래스가 서버의 매개변수 타입을 '일반화'하면된다.

        // 예제로 클래스 템플릿을 이용해 실제 클래스를 3개 생성해봤다.

        // <>은 디폴트 매개변수를 사용하여 <INT>와 같다
        Array<> ArrInt;

        ArrInt.Add(10);
        ArrInt.Add(20);
        ArrInt.Add(30);

        for (INT i = 0; i < ArrInt.Getsize(); i++)
        {
            std::cout << ArrInt[i] << std::endl;
        }


        Array<double> ArrDouble;

        ArrDouble.Add(10.6);
        ArrDouble.Add(20.8);
        ArrDouble.Add(30.22);


        double value1 = ArrDouble[0];
        double value2 = ArrDouble[1];
        double value3 = ArrDouble[2];

        for (INT i = 0; i < ArrDouble.Getsize(); i++)
        {
            std::cout << ArrDouble[i] << std::endl;
        }


        Array<const char*> ArrString;

        ArrString.Add("Hello");
        ArrString.Add("Hi");
        ArrString.Add("Bye");

        for (INT i = 0; i < ArrString.Getsize(); i++)
        {
            std::cout << ArrString[i] << std::endl;
        }

    }

    {

        TemTest<int> TestInt(20);
        TestInt.Print();

        TemTest<double> TestDouble(20.3);
        TestDouble.Print();

        TemTest<std::string> TestString("HelloWorld");
        TestString.Print();
    }

    {
        system("cls");
        int Arr[5] = { 10, 20, 30, 40, 50 };
        ForEach<int*, void(*)(int)>(Arr, Arr + 5, PrintTemplate<int>);


        std::string ArrString[5] = { "Hi", "My", "is", "Kim", "Guter"};
        // 출력함수의 매개변수의 타입을 컴파일러가 유추할 수 없어서 
        // 명시적으로 매개변수 인자를 지정해야한다.
        ForEach/*<int*, void(*)(std::string)>*/(ArrString, ArrString + 5, PrintStruct<std::string>("*\n"));

}