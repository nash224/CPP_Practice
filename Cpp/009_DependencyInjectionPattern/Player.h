#pragma once
class Player
{
public:
	// Player ��ü�� ������ ��, NewMonster�� �ּҸ� ���ڰ����� �޾Ҵ�.
	Player(Monster* _Monster);

	void MainFunc();

private:
	// public���� NewPlayer�� �˰� �Ǿ� PlayerŬ������ 
	// Monster�� ������ �� �غ� �Ǿ� �ִ�.
	Monster* m_Monster;

	int Hp = 50;
	int Att = 10;

};

