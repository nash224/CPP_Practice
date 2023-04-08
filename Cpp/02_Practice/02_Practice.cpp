// 02_Practice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Date
{
public:
    void SetDate(int _year, int _month, int _date);
    void AddDay(int _Day);
    void AddMonth(int _Month);
    void AddYear(int _Year);
    void ShowDate();

private:
    int Year;
    int Month;
    int Day;
};

int main()
{
    int currentyear;
    int currentmonth;
    int currentday;

    Date NewDate;

    std::cout << "현재의 년도 : ";
    std::cin >> currentyear;
    std::cout << "현재의 몇 월 : ";
    std::cin >> currentmonth;
    std::cout << "현재의 몇 일 : ";
    std::cin >> currentday;


    NewDate.SetDate(currentyear, currentmonth, currentday);

    int Addyear;
    std::cout << "추가할 년도 : ";
    std::cin >> Addyear;
    NewDate.AddYear(Addyear);
    int Addmonth;
    std::cout << "추가할 개월 수 : ";
    std::cin >> Addmonth;
    NewDate.AddMonth(Addmonth);
    int Addday;
    std::cout << "추가할 일 수 : ";
    std::cin >> Addday;
    NewDate.AddDay(Addday);

    NewDate.ShowDate();
}


void Date::SetDate(int _year, int _month, int _date)
{
    Year = _year;
    Month = _month;
    Day = _date;
}

void Date::AddDay(int _Day)
{
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7
        || Month == 8 || Month == 10 || Month == 12)
    {
        if (Day + _Day < 32)
        {
            Day += _Day;
        }
        else
        {
            Day += _Day - 31;
            AddMonth(1);
        }
    }
    else if (Month == 2)
    {
        if (Day += _Day < 29)
        {
            Day += _Day;
        }
        else
        {
            Day += _Day - 28;
            Month += 1;
        }
    }
    else
    {
        if (Day + _Day < 31)
        {
            Day += _Day;
        }
        else
        {
            Day += _Day - 30;
            Month += 1;
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

void Date::ShowDate()
{
    std::cout << "예측한 날짜는 : " << Year << "년 " << Month << "월 " << Day << "일 입니다." << std::endl;
}