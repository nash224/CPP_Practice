// 002_StaticOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <LeakCheck/Leak.h>


class Point
{
private:
	int x = 0;
	int y = 0;

public:
	Point()
	{

	}

	explicit Point(int _x, int _y)
		: x(_x), y(_y)
	{

	}

	void operator=(int _value)
	{
		x = _value;
	}

	operator int() const
	{
		return x;
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

class Pointer
{
private:
	Point* Ptr;

public:
	Pointer(Point* _Ptr)
		: Ptr(_Ptr)
	{

	}

	~Pointer()
	{
		delete Ptr;
	}

	Point* operator->() const
	{
		return Ptr;
	}

	Point& operator*() const
	{
		return *Ptr;
	}
};

class Array
{
private:
	int* Arr = nullptr;
	int size = 0;
	int capacity = 0;

public:
	Array(int _cap = 100)
		: Arr(0), size(0), capacity(_cap)
	{
		Arr = new int[capacity];
	}

	~Array()
	{
		delete[] Arr;
		Arr = nullptr;
	}

	void Add(int _data)
	{
		if (size < capacity)
		{
			Arr[size++] = _data;
		}
	}

	int Size() const
	{
		return size;
	}

	int& operator[] (int _index)
	{
		return Arr[_index];
	}
};

class String
{
private:
	const char* str = nullptr;

public:
	String(const char* _String)
	{
		str = _String;
	}

	void operator=(const char* _String)
	{
		str = _String;
	}

	operator const char* () const
	{
		return str;
	}


};

int main()
{
	Base::LeckCheck();

	{
		Point Pt(5, 8);

		Pt.Print();
		int value1 = Pt.operator[](0);

		std::cout << Pt[0] << ',' << Pt[1] << std::endl;


		Point* pt1 = new Point(3, 9);
		Point* pt2 = new Point(32, 532);

		pt1->Print();
		pt2->Print();

		delete pt1;
		delete pt2;

	}

	{
		system("cls");
		
		Point p1; // 암시적 생성자 호출
		p1 = 200;

		// p1.operator int() const의 연산자 멤버 함수로 의해 p1.x의 값을 받음 
		int n = p1;


		Pointer Ptr1 = new Point(5, 3); // 명시적 생성자 호출
		Pointer Ptr2 = new Point(1, 8);

		// ptr2 내부에 있는 실제 포인터를 반환받고 이 포인터를 이용해 실제에 접근할 수 있다.
		Ptr1->Print();
		Ptr2.operator->()->Print();

		// Ptr1 내부가 가리키는 값으로 실제의 함수에 접근할 수 있다.
		(*Ptr1).Print();
		Ptr2.operator*().Print();

	}


	{
		Array Test(10);

		Test.Add(10);
		Test.Add(20);
		Test.Add(30);

		for (int i = 0; i < Test.Size(); i++)
		{
			std::cout << Test[i] << std::endl;
		}

		Test[1];

		Array& Test2 = Test; // 얕은 복사 => 주소 값만 복사
		Test2[1] = 200;

		std::cout << Test2[1] << std::endl;

	}
	
	{
		String s("Hello!!");
		const char* sz = "Hi!!!";
		s = sz;

		const char* sa = s;
	}
}
