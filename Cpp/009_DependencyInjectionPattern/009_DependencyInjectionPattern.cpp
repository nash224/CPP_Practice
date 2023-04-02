
#include <iostream>
#include "Player.h"
#include "Monster.h"

// 의존성 주입 패턴은 객체를 생성할 때 
// 외부에서 Player의 정보를 담고있는 객체에 대한 포인터를 전달하고
// 생성자를 통해 객체를 생성할 때 
// 외부에서 필요한 객체의 포인터를 전달하는 것이다.

// 객체 간의 의존성을 줄이고 코드의 유연성과 재사용성을 높이기 위해 사용하는 디자인 패턴이다.



int main()
{
    // 몬스터 클래스는 NewMonster라는 객체를 생성한다
    Monster NewMonster;
    // 플레이어 클래스는 NewPlayer라는 객체를 생성하고
    // NewMonster 객체의 주소를 생성자에 전달해준다
    Player NewPlayer(&NewMonster);

}
