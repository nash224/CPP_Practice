// 012_Starcraft01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class int2
{
public:
    inline int2()
    {

    }

    int2(int _X, int _Y)
        : X(_X)
        , Y(_Y)
    {

    }

private:
    int X = 0;
    int Y = 0;
};

class Marine
{
public:
    Marine();

    Marine(int _X, int _Y);


    int Attack();
    void BeAttacked(int _Att);
    void ShowStatus();
    void Move(int _X, int _Y);

    inline int2 GetPos() const
    {
        return Pos;
    }

    inline void SetPos(const int2& _value)
    {
        Pos = _value;
    }

private:
    int2 Pos;
    int Hp;
    int Att;
    int coord_x;
    int coord_y;
    bool Death;
};

int main()
{
    Marine NewMarine1(3, 4);
    Marine NewMarine2(2, 1);

    NewMarine1.ShowStatus();
    NewMarine2.ShowStatus();

    NewMarine1.Attack();

    NewMarine2.BeAttacked(NewMarine1.Attack());

    NewMarine2.ShowStatus();

    NewMarine2.Move(5, 7);
    NewMarine2.ShowStatus();
}


Marine::Marine()
{
    Hp = 50;
    coord_x = 0;
    coord_y = 0;
    Att = 5;
    Death = false;
}

Marine::Marine(int _X, int _Y)
{
    Hp = 50;
    coord_x = _X;
    coord_y = _Y;
    Att = 5;
    Death = false;
}

void Marine::Move(int _X, int _Y)
{
    coord_x = _X;
    coord_y = _Y;
}


int Marine::Attack()
{
    return Att;
}

void Marine::BeAttacked(int _Att)
{
    Hp -= _Att;
    if (Hp <= 0)
    {
        Death = true;
    }
}

void Marine::ShowStatus()
{
    std::cout << "***Marine***" << std::endl;
    std::cout << " Location : ( " << coord_x << " , " << coord_y << " )" << std::endl;
    std::cout << " HP : " << Hp << std::endl;
}