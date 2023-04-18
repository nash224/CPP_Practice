// STL.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>


class Point
{
private:
    int value1 = 0;
    int value2 = 0;

public:
    Point()
    {

    }

    Point(int _value1, int _value2)
        : value1(_value1), value2(_value2)
    {

    }
};

class PointOperatorPoint
{
private:
    int X = 0;
    int Y = 0;

public:
    PointOperatorPoint()
    {

    }


    PointOperatorPoint(int _X, int _Y)
        : X(_X), Y(_Y)
    {

    }

    void Print() const
    {
        std::cout << X << "," << Y << std::endl;
    }

    void operator+(const PointOperatorPoint& _arg)
    {
        std::cout << " operator+() 함수 호출" << std::endl;
    }
};

class PointOperator
{
private:
    int X = 0;
    int Y = 0;

public:
    PointOperator()
    {

    }


    PointOperator(int _X, int _Y)
        : X(_X), Y(_Y)
    {

    }

    bool operator==(const PointOperator& _Other) const
    {
        return X == _Other.X && Y == _Other.Y ? true : false;
    }

    bool operator!=(const PointOperator& _Other) const
    {
        return !(*this == _Other);
    }

    // 첫번째 const는 인자값을 변경하지 않는다는 것이고,
    // 두번째 const는 this의 값을 변경하지 않는다는 것이다.

    PointOperator operator+(const PointOperator& _arg) const
    {
        PointOperator arg;
        arg.X = this->X + _arg.X;
        arg.Y = this->Y + _arg.Y;

        return arg;
    }

    PointOperator operator-(const PointOperator& _arg) const
    {
        PointOperator arg;
        arg.X = this->X - _arg.X;
        arg.Y = this->Y - _arg.Y;

        return arg;
    }

    //void operator++()
    //{
    //    ++X;
    //    ++Y;
    //}

    PointOperator& operator++()
    {
        ++X;
        ++Y;
        return *this;
    }

    PointOperator& operator++(int)
    {
        PointOperator temp(*this);
        ++X;
        ++Y;
        return temp;
    }

    PointOperator& operator--()
    {
        --X;
        --Y;

        return *this;
    }

    PointOperator& operator--(int)
    {
        PointOperator Decrease(*this);
        --X;
        --Y;

        return Decrease;
    }

    // const 멤버 함수는 멤버 함수 내에서 객체의 멤버 변수를 변경하지 않는다는 것을 보장하는 함수이다.
    // const 객체는 const 멤버 함수만 호출할 수 있다.

    void Print() const
    {
        std::cout << X << "," << Y << std::endl;
    }

    int GetX() const // const 함수 
    {
        return X;
    }

    int GetY() // 비 const 함수
    {
        return Y;
    }

    void SetX(const int _X) // 비 const 함수: 멤버 변경
    {
        X = _X;
    }

};




#include <iostream>

int main()
{
    {
        Point p1(1, 2);
        Point p2(2, 4);

        // Error Code : E0349
        //Point SumTwoValue = p1 + p2;// 이러한 피연산자와 일치하는 '+' 연산자가 없습니다. 

        // 컴파일러는 주석에 쓴 것처럼 해석한다.
        //p1 + p2; // p1.operator+(p2);
        //p1 * p2; // p1.operator*(p2);
        //p1 / p2; // p1.operator/(p2);
        //p1 == p2; // p1.operator==(p2);
    }

    {
        PointOperatorPoint p1(3, 4);
        PointOperatorPoint p2(5, 6);

        // p1객체를 기준으로 멤버 함수 operator+()를 호출하고 함수의 인자로 p2를 전달한다.
        p1 + p2; // " operator+() 함수 호출" 이라고 출력된다.
        p1.operator+(p2); // " operator+() 함수 호출" 이라고 출력된다.
    }

    {
        PointOperator p1(3, 2);
        PointOperator p2(3, 1);
        PointOperator p3;
        PointOperator p4(3, 1);
        PointOperator Minus;

        // p3 = p1.operator+(p2); 가 실행되고, p1은 this의 객체이고, p2는 _arg의 객체이다
        p3 = p1 + p2;
        Minus = p1 - p2;

        bool boolean1 = p1 == p2;
        bool boolean2 = p4 == p2;

        bool boolean3 = p1 != p2;
        bool booleanTest = p1.operator!=(p2);
        bool boolean4 = p4 != p2;

        int a = 0;
    }

    {
        const PointOperator p5(0, 0); // const 객체 : 모든 멤버 변경 불가
        PointOperator p6(2, 3); // 비 const 객체

        //p5 = p6; // 컴파일은 되지만, p5 값이 바뀌지 않음

        // const객체는 const 함수만 불러올 수 있다.
        
        // Error Code : E1086 => 객체에 멤버 함수 "PointerOperator::SetX" 와 호환되지 않는 한정자가 있습니다.
        //p5.SetX(5); 
        //p5.GetY();

        p6.SetX(7);

        int a = 0;
    }

    {
        PointOperator TestPrefix(4, 3), TestPostFix(4,3);
        PointOperator Result;

        //TestPrefix.operator++();
        //++TestPrefix;

        Result = TestPrefix.operator--();
        Result = --TestPrefix;
        TestPrefix.Print();
        Result.Print();

        Result = TestPostFix.operator--(0);
        Result = TestPostFix--;
        TestPostFix.Print();
        Result.Print();

    }
}
