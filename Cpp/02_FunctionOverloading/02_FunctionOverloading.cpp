// 02_FunctionOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void swap(int* _num1, int* _num2)
{
    int temp = 0;
    temp = *_num1;
    *_num1 = *_num2;
    *_num2 = temp;
}

void swap(char* _ch1, char* _ch2)
{
    char temp = ' ';
    temp = *_ch1;
    *_ch1 = *_ch2;
    *_ch2 = temp;
}

void swap(double* _dbl1, double* _dbl2)
{
    double temp = 0;
    temp = *_dbl1;
    *_dbl1 = *_dbl2;
    *_dbl2 = temp;
}


int main()
{
    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout << num1 << ' ' << num2 << std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout << ch1 << ' ' << ch2 << std::endl;

    double dbl1 = 1.111, dbl2 = 2.555;
    swap(&dbl1, &dbl2);
    std::cout << dbl1 << ' ' << dbl2 << std::endl;

}
