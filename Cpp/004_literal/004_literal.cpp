
#include <iostream>

// 리터럴은 소스 코드 상에서 고정된 값을 가르킨다.
// "로 묶은 것들을 문자열 리터럴일고 한다.
// 리터널은 읽기만 가능한다

int main()
{
    // 문자열 배열은 스택이라는 메모리 수정이 가능한 영역에 정의되므로 수정이 가능하다.
    char str[] = "Hello";   // { 'H' , 'e' , 'l' , 'l' , 'o' , '\0'};
    const char* pstr = "goodbye";   // goodbye의 시작 주소 값을 가져와서 pstr에 대입해라

    int Value0 = *pstr; // 'H'
    char Str_Value0 = (char)Value0;
    __int64 Address = (__int64)pstr;
    pstr += 1;
    int Value1 = *pstr; // 'e'
    char Str_Value1 = (char)Value1;
    pstr += 1;
    int Value2 = *pstr; // 'l'
    char Str_Value2 = (char)Value2;
    pstr += 1;
    int Value3 = *pstr; // 'l'
    char Str_Value3 = (char)Value3;


    str[2] = 'h';

    std::cout << str << std::endl;
    

    char str1[] = "abc";
    char str2[] = "edf";


    int a, b;

    // 주소 값이 존자하면 원소 또한 메모리에 존재한다.
    // 참조는 메모리를 차지하지 않는다.
    //int& arr[2] = { a,b };

    // 각 참조의 배열에 배열의 원소를 담는다.
    int arr4[3] = { 1,2,3 };                                                                                                                                                                                                                                                                                              
    int(&ref)[3] = arr4;



    //int Str_Sum_Value = str1 + str2; // 주소 값을 연산하는 것은 있을 수 없다.
}