
#include <iostream>
//#include <stdio.h>

class Animal
{
public:
    char name[30];
    int age;

    int health;
    int hunger;
    int clean;

    void Play(Animal* _Animal)
    {
        _Animal->health -= 20;
        _Animal->hunger -= 30;
        _Animal->clean -= 40;
    }
     

private:
};

// 싱글톤 패턴은 클래스에서 단 하나의 객체만 생성하도록 보장하는 패턴이다. 
// 싱글톤 패턴은 전역 변수를 사용하여 구현할 수 있지만, 
// 클래스 내부에 있는 정적 멤버 변수를 사용하는 편이 일반적이다.
class Manager
{
public:
    Manager();

    const int AnimalNumber = 30;


private:

};

void CreateAnimal(Animal* _Animal);

void Play(Animal* _Animal);

void OneDayPass(Animal* _Animal);


int main()
{
    Manager Main;

    const int AnimalNumber = 20;
    int AnimalIndex;
    Animal* ArrAnimal[AnimalNumber];
    
    for (;;)
    {
        std::cout << "1. 동물의 정보 생성" << std::endl;
        std::cout << "2. 놀기" << std::endl;
        std::cout << "3. 상태 보기" << std::endl;

        char Input = getchar();

        switch (Input)
        {
            int PlayWith;
        case 1: 
            *(ArrAnimal + AnimalIndex);
            CreateAnimal(ArrAnimal[AnimalIndex]);

            AnimalIndex++;
            break;
        case 2:
            std::cout << "누구랑 놀지? : ";
            std::cin >> PlayWith;

            if (PlayWith < AnimalNumber)
            {
                ArrAnimal[AnimalIndex]->Play(ArrAnimal[PlayWith]);
            }

            break;
        case 3:
            std::cout << "누구껄 보지? : ";
            std::cin >> PlayWith;

            if (PlayWith < AnimalNumber)
            {
                ShowStatus(ArrAnimal[PlayWith]);
            }
            break;
        default:
            break;
        }
    }

    for (size_t i = 0; i < AnimalNumber; i++)
    {
        delete ArrAnimal[i];
    }
}

void CreateAnimal(Animal* _Animal)
{
    std::cout << "동물의 이름?";
    std::cin >> _Animal->age;

    std::cout << "동물의 나이?";
    std::cin >> _Animal->age;

    _Animal->health = 100;
    _Animal->hunger = 100;
    _Animal->clean = 100;
}


void OneDayPass(Animal* _Animal)
{
    _Animal->health += 30;
    _Animal->hunger -= 40;
    _Animal->clean -= 10;
}

void ShowStatus(Animal* _Animal)
{
    std::cout << _Animal->name << "의 상태" << std::endl;
    std::cout << "체력 :" << _Animal->health << std::endl;
    std::cout << "배고픔 :" << _Animal->hunger << std::endl;
    std::cout << "청결도 :" << _Animal->clean << std::endl;
}