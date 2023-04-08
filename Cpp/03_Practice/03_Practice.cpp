// 03_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cmath>

class Point
{
public:
    int X = 0;
    int Y = 0;

    Point(int _X, int _Y)
        : X(_X)
        , Y(_Y)
    {

    }
private:
    Point()
    {

    }

    // 이니셜라이저 리스트는 객체를 생성할 때, 멤버 변수를 초기화 할 수 있다.
};

class Geomtry
{
public:

    Geomtry();

    Geomtry(Point** Point_Array)
    {
        for (int i = 0; i < 100; i++) {
            PointArray[i] = Point_Array[i];
        }
    }

    inline Point GetPos(Point& _Point) const
    {
        return _Point;
    }

    void AddPoint(const Point& _Point);

    void PrintDistance();

    void PrintNumMeets();

    inline void DeleteMemory();


private:
    // Geomtry는 포인트의 배열을 알 준비가 되어있어.
    Point* PointArray[100] = {nullptr};
    int NumberPoints = 0;
    int Dist = 0;
    int sqrt = 0;
    int sqrt_value = 0;

};

int main()
{
    Point Pos0(3, 2), Pos1(3, 1), Pos2(6, 4), Pos3(2, 3);
    Point* PointArray[4] = { &Pos0, &Pos1, &Pos2, &Pos3 };
    Geomtry Main;
    Main.AddPoint(Pos0);
    Main.AddPoint(Pos1);
    Main.AddPoint(Pos2);
    Main.AddPoint(Pos3);

    Main.PrintDistance();
    

    Main.DeleteMemory();
}

// 
void Geomtry::AddPoint(const Point& _Pos)
{
    PointArray[NumberPoints++] = new Point(_Pos.X, _Pos.Y);
}

void Geomtry::PrintDistance()
{
    for (size_t ArrayIndex_i = 0; ArrayIndex_i < NumberPoints; ArrayIndex_i++)
    {
        for (size_t ArrayIndex_j = ArrayIndex_i + 1; ArrayIndex_j < NumberPoints; ArrayIndex_j++)
        {
            if (ArrayIndex_i == ArrayIndex_j)
            {
                continue;
            }

            std::cout << ArrayIndex_i + 1 << "번째 점과" << ArrayIndex_j + 1 << "번째 점의 사이의 거리는 ";

            Dist = pow(PointArray[ArrayIndex_i]->X - PointArray[ArrayIndex_j]->X, 2)
                + pow(PointArray[ArrayIndex_i]->Y - PointArray[ArrayIndex_j]->Y, 2);
            sqrt_value = sqrt*(Dist);

            std::cout << sqrt_value << "입니다." << std::endl;
        }
    }
}

void Geomtry::PrintNumMeets()
{

}

inline void Geomtry::DeleteMemory()
{
    for (size_t ArrayIndex = 0; ArrayIndex < NumberPoints; ArrayIndex++)
    {
        delete PointArray[ArrayIndex];
    }
}