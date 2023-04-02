#pragma once
class Player
{
public:
	// Player 객체를 생성할 때, NewMonster의 주소를 인자값으로 받았다.
	Player(Monster* _Monster);

	void MainFunc();

private:
	// public에서 NewPlayer를 알게 되어 Player클래스는 
	// Monster의 정보를 알 준비가 되어 있다.
	Monster* m_Monster;

	int Hp = 50;
	int Att = 10;

};

