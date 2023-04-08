// 02_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Date
{
public:
    // Constructor
    // 생성자는 객체 생성시 자동으로 호출되는 함수라고 한다.
    // 생성자는 객체를 초기화하는 역할을 하기 떄문에 반환값이 없다.
    
    // 생성자는 정의하지 않아도 디폴트 생성자가 호출된다.

    Date()
    {
        std::cout << "기본 생성자 호출" << std::endl;
        Year = 2042;
        Month = 4;
        Day = 3;
    }


    Date(int _year, int _month, int _day)
    {
        std::cout << "인자 3개 개인 생성자 호출" << std::endl;
        Year = _year;
        Month = _month;
        Day = _day;
    }

    void SetDate(int _year, int _month, int _date);
    void AddDay(int _Day);
    void AddMonth(int _Month);
    void AddYear(int _Year);

    int GetCurrentMonthTotalDays(int _year, int _month);

    int GetMonthDay(int _month) const
    {
        return MonthDay[_month - 1];
    }


    void ShowDate();

private:
    static int MonthDay[12];
    int Year;
    int Month;
    int Day;
};

int Date::MonthDay[12] = { 31, 28, 31, 30, 31, 30 , 31, 31, 30 , 31 , 30 , 31 };

int main()
{
    //Date NewDate = Date(2022, 2, 2);
    Date NewDate(2022, 2, 2); // 명시적 방법의 축약형이다.
    NewDate.ShowDate();

    //
    Date NewDate2;
    NewDate2.ShowDate();

    NewDate.SetDate(2023, 12, 6);
    NewDate.ShowDate();


    NewDate.AddDay(400);
    NewDate.ShowDate();

    NewDate.AddMonth(1);
    NewDate.ShowDate();

    NewDate.AddYear(20);
    NewDate.ShowDate();

    NewDate.SetDate(2023, 4, 2);
    NewDate.AddDay(7000);
    NewDate.ShowDate();
}

// Date:: 는 Date 클래스의 정의된 함수라는 의미이다.
void Date::SetDate(int _year, int _month, int _date)
{
    Year = _year;
    Month = _month;
    Day = _date;
}

void Date::AddDay(int _Day)
{
    while (true)
    {
        int CurrentMonthTotalDays = GetCurrentMonthTotalDays(Year, Month);

        if (Day + _Day <= CurrentMonthTotalDays)
        {
            Day += _Day;
            return;
        }
        else
        {  
            _Day -= (CurrentMonthTotalDays - Day + 1);
            Day = 1;
            AddMonth(1);
        }
    }
}

void Date::AddMonth(int _Month)
{
    if (Month + _Month < 13)
    {
        Month += _Month;
    }
    else
    {
        Month += _Month - 12;
        Year += 1;
    }
}

void Date::AddYear(int _Year)
{
    Year += _Year;
}

int Date::GetCurrentMonthTotalDays(int _year, int _month)
{
    if (Month != 2)
    {
        return MonthDay[_month -1];
    }
    else if (_year % 4 == 0 && _year % 100 != 0)
    {
        return 29;
    }
    else
    {
        return 28;
    }
}

void Date::ShowDate()
{
    std::cout << "예측한 날짜는 : " << Year << "년 " << Month << "월 " << Day << "일 입니다." << std::endl;
}