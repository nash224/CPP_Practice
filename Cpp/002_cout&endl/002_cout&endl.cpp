
#include <iostream>

int main()
{
	int sum = 0;

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << i << std::endl;
	}

	for (size_t i = 0; i < 10; i++)
	{
		sum += i;
	}
	std::cout << "합은 : " << sum << std::endl;

	int Lucky_Number = 3;

	int User_Input;

	while (true)
	{
		std::cout << "입력 : ";
		std::cin >> User_Input;
		if (User_Input == Lucky_Number)
		{
			std::cout << "행운의 숫자를 맞췄습니다!!!" << std::endl;
			break;
		}
		else
		{
			std::cout << "다시 생각해보세요." << std::endl;
		}
	}

	std::cout << "궁금한 점이 있다면 해당 숫자를 입력해보세요." << std::endl;
	std::cout << "1 : 이름" << std::endl;
	std::cout << "2 : 성별" << std::endl;
	std::cout << "3 : 나이" << std::endl;
	std::cout << "4 : 나가기" << std::endl;


	while (true)
	{
		std::cin >> User_Input;

		switch (User_Input)
		{
		case 1:
			std::cout << "김태훈" << std::endl;
			break;
		case 2:
			std::cout << "남성" << std::endl;
			break;
		case 3:
			std::cout << "27" << std::endl;
			break;
		default:
			std::cout << "더 이상 저에 대한 궁금한 점이 없으시군요..." << std::endl;
			break;
		}

		if (User_Input == 4)
		{
			break;
		}
	}

	int a = 0;
}