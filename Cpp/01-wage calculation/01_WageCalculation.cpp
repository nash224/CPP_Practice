// 01-wage calculation.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    int input = 0;
    
    int WageCalculation = 0;

    while (true) 
    {
        std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
        std::cin >> input;

        if (input == -1)
        {
            std::cout << "프로그램을 종료합니다." << std::endl;

            break;
        }


        WageCalculation = 50 + input * 0.12;

        std::cout << "이번 달 급여: " << WageCalculation << "만원" << std::endl;
    }

}