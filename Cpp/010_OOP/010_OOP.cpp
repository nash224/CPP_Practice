// 010_OOP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 추상화란 객체가 현실 세계에서의 존재하는 것을 나타내기 위한 용어이다.

// 나는 나를 알고 있다.
// 나에 대한 상태나 행동을 알고 있다.
// 자신의 상태를 알려주는 변수와 자신이 하는 행동을 수행하는 함수들로 이루어져 있음
class Animal
{
// public은 외부에서 마음대로 이용할 수 있다.
public: // public을 주석처리하면, 클래스의 접근 지정자의 기본값은 private이기 때문에
        // private 멤버에 엑세스 할 수 없다고 오류가 발생한다.
    // 클래스 내에 있는 함수를 멤버 함수라고 한다.

    // 함수 내부를 초기화하는 멤버 함수
    void SetAnimal(int _Hunger, int _Wieght);

    // 만복도를 올려주는 멤버 함수
    void Feed(int _Food);

    void PrintStatus();

    void Play() // 동물이 Play 한다는 로직
    {

    }

    void Sleep()  // 동물이 Sleep 한다는 내용
    {

    }

    int GetHunger() const
    {
        return Hunger;
    }

protected:



    
// 접근 지정자는 외부에서 멤버에 접근할 수 있냐 없냐를 지시해주는 것이다.
// private는 '이 아래에 쓰여져 있는 것은 모두 객체 내에서 보호되고 있다' 는 의미이다.
private:
    // 변수를 외부로부터 값을 변경하지 못하게 보호한다.
    // 변수를 바꿀려면 인스턴스 함수를 통해서만 가능하다.
    // 이를 멤버 변수라고 한다.
    int Health = 100;
    int Hunger;
    int Weight;
};

// 멤버 함수와 멤버 변수가 있다고 해서 실재 하는 것은 아니다.
// 인스턴스가 만들어져야 세상에 나타나는 것이다.


int main()
{
    // 객체를 만들면 자기 만의 변수를 나타내는 변수 인스턴스 변수가 있고
    // 이를 가지고 작업을하는 함수를 인스턴스 메소드라고 한다.

    // 이와 같이 외부에서 직접 인스턴스 변수의 값을 바꿀 수 없고 
    // 항상 인스턴스 메소드(함수)를 통해서 간접적으로 조절하는 것을 '캡슐화' 라고 한다.
    Animal Bird;

    Bird.SetAnimal(100, 100);

    Bird.Feed(100);

    int BirdHungerValue = Bird.GetHunger();

    Bird.PrintStatus();

    Bird.Play(); // 동물클래스의 객체인 새가 Play 한다
    Bird.Sleep(); // 동물클래스의 객체인 새가 Sleep 한다
}


void Animal::SetAnimal(int _Hunger, int _Wieght)
{
    Hunger = _Hunger;
    Weight = _Wieght;
}

void Animal::Feed(int _Food)
{
    Hunger += _Food;
}

void Animal::PrintStatus()
{
    std::cout << "이 동물의 Hunger : " << Hunger << std::endl;
    std::cout << "이 동물의 Weight : " << Weight << std::endl;
}