#include "Player.h"
#include "Monster.h"

// Player에서 Player 생성자는 몬스터의 주소를 매개변수에 받아 이러한 로직을 가진다
// m_Monster에 몬스터의 주소를 담는다
Player::Player(Monster* _Monster)
{
	m_Monster = _Monster;
}

void Player::MainFunc()
{

}