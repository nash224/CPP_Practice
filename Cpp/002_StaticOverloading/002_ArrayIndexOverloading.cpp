// 002_StaticOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Point
{
private:
	int x;
	int y;

public:
	Point(int _x, int _y)
		: x(_x), y(_y)
	{

	}

	inline int operator[] (const int _index) const
	{
		if (_index == 0)
		{
			return x;
		}

		else if (_index == 1)
		{
			return y;
		}
		else
		{
			throw "뭘 참조하려고 했던거죠?";
		}
	}

	void Print() const
	{
		std::cout << x << "," << y << std::endl;
	}

};

int main()
{
	Point Pt(5, 8);

	Pt.Print();
	int value1 = Pt.operator[](0);

	std::cout << Pt[0] << ',' << Pt[1] << std::endl;
}
