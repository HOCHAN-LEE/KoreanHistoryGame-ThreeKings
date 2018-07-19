#pragma once
#include "main.h"

void bad_word(int i, int j)
{
	agr(j,i, -2);
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->id == i)
		{
			auto J = man.begin();
			for (; J != man.end();)
			{
				if (J->id == j)
				{
					J->prestige -= I->prestige / 100;
					I->prestige -= J->prestige / 100;

					if (I->traits["����"] && false)
					{
						auto K = man.begin();
						for (; K != man.end(); K++)
						{
							if (K->live)
							{
								if (I->id != K->id && J->id != K->id)
								{
									agr(K->id,J->id,-5);
								}
							}
						}
						I->traits["����"] = false;
					}

					break;
				}
				J++;
			}
			break;
		}
	}
	agr(i, j, -10);
}
void good_word(int i, int j)
{
	//agr(j, i, 2);
	auto I = man.begin();
	for (; I != man.end();I++)
	{
		if (I->id == i)
		{
			auto J = man.begin();
			for (; J != man.end();)
			{
				if (J->id == j)
				{
					J->prestige += I->prestige / 3000;
					I->prestige += J->prestige / 3000;
					break;
				}
				J++;
			}
			break;
		}
	}
	//agr(i, j, 10);
}



void speech(int id, int Prv, int pop)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == id)
		{
			I->charge -= 60;
			I->money -= 10;

			int eng = rand() % 9 + 2;

			if (I->traits["������ ����"])
			{
				I->traits["������ ����"] = false;
				eng += 10;
			}
			
			if (prv[Prv].pop[pop].fascist > I->fascist)
			{
				prv[Prv].pop[pop].fascist -= eng;
			}
			else if (prv[Prv].pop[pop].fascist < I->fascist)
			{
				prv[Prv].pop[pop].fascist += eng;
			}

			if (prv[Prv].pop[pop].liberty > I->liberty)
			{
				prv[Prv].pop[pop].liberty -= eng;
			}
			else if (prv[Prv].pop[pop].liberty < I->liberty)
			{
				prv[Prv].pop[pop].liberty += eng;
			}

			if (I->traits["������ ����"])
			{
				I->traits["������ ����"] = false;
				for (int r = 0; r < 3; r++)
				{
					pop = rand() % prv[Prv].pop.size();
					if (prv[Prv].pop[pop].fascist > I->fascist)
					{
						prv[Prv].pop[pop].fascist -= eng;
					}
					else if (prv[Prv].pop[pop].fascist < I->fascist)
					{
						prv[Prv].pop[pop].fascist += eng;
					}

					if (prv[Prv].pop[pop].liberty > I->liberty)
					{
						prv[Prv].pop[pop].liberty -= eng;
					}
					else if (prv[Prv].pop[pop].liberty < I->liberty)
					{
						prv[Prv].pop[pop].liberty += eng;
					}
				}
			}

			eng = rand() % 9 + 2;

			break;
		}
	}
}
void bribe(int i, int comp)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			int j = 0;
			auto o = company.begin();
			for (;o != company.end();o++,j++)
			{
				if (j == comp)
				{
					auto J = man.begin();
					for (; J != man.end(); J++)
					{
						if (J->id == o->owner)
						{
							int money = 0;
							for (int a = 0; a < 5; a++)
							{
								if (gr(I->id, J->id) > 30 + 30 * a)
								{
									money += 50;
								}
								else
								{
									break;
								}
							}
							if (I->id == play_id)
							{
								if (money == 0)
								{
									msg_push(J->id,"�˼������� �� �̾߱�� �����ɷ� �ϰڽ��ϴ�.");
								}
								else
								{
									msg_push(J->id, "�� ������ ������ �޾Ƶ��̰ڽ��ϴ�.\n�� �ڱ� "+std::to_string(money)+"�� ������ ���� �̴ϴ�.");
									J->money -= money;
									I->money += money;
								}
							}
							agr(I->id, J->id, -20);
						}

					}
					break;
				}
			}
			break;
		}
	}
}
void loby(int i, int comp)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			int j = 0;
			auto o = company.begin();
			for (; o != company.end(); o++, j++)
			{
				if (j == comp)
				{
					auto J = man.begin();
					for (; J != man.end(); J++)
					{
						if (J->live && J->id == o->owner)
						{
							int rel = 5;
							if (gr(I->id, J->id) > 30)
							{
								rel += 10;
							}

							I->prestige -= 15;
							o->power += 3;
							agr(I->id, J->id, rel);


							if (I->id == play_id)
							{
								if (rel == 5)
								{
									msg_push(J->id, "�� �����ϴ�.\n������ �̷� ���踦 ���� �ϱ� ����մϴ�.");
								}
								else
								{
									msg_push(J->id, "���� ȸ��� ���ϸ� �ſ� ����ϰ� �ֽ��ϴ�.\n������ �ʿ��ϸ� �����ֽʽÿ�. ����� ģ�� " + J->name);
								}
							}

						}
					}


					break;
				}
			}
			break;
		}
	}
}

void lobi(int i, int j)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			auto J = man.begin();
			for (; J != man.end(); J++)
			{
				if (J->id == j)
				{
					if (I->id == play_id)
					{
						if (gr(I->id, J->id) < 30)
						{
							msg_push(J->id, "�����ϴ�.\n�����ε� �̷� ���踦 ���� �ϱ� ���մϴ�.");
						}
						else
						{
							msg_push(J->id, "����� ������ �־� ū �����Դϴ�.\n��� ���п� ���õ� ���� ��Ȱ�մϴ�.");
							J->money += 50;
							I->money -= 50;
							agr(I->id, J->id, 10);
						}
					}
					agr(I->id, J->id, 20);
				}
			}
			break;
		}
	}
}



void mafia(int i, int frc)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			auto o = force.begin();
			int j = 0;
			for (; o != force.end(); o++, j++)
			{
				if (j == frc)
				{
					auto J = man.begin();
					for (; J != man.end(); J++)
					{
						if (J->id == o->owner)
						{
							if (I->traits["������ ����"])
							{
								agr(I->id, J->id, 20);
							}
							else if (gr(I->id, J->id) < 30)
							{

							}
							else
							{
								I->traits["������ ����"] == true;
							}
							if (I->id == play_id)
							{
								if (I->traits["������ ����"])
								{
									msg_push(J->id, "����� �̹� �ٸ� ���� ������ �ް� �ֽ��ϴ�.\n�� ���� ������ �׶� �ٽ� �˷��ֽʽÿ�.");
								}
								else if (gr(I->id, J->id) < 30)
								{
									msg_push(J->id, "�츮�� �츮�� ���� �ൿ�Ұ̴ϴ�.\n�̷� ������ �ϱ����� �츮�� ���踦\n�����غ��ÿ�");
								}
								else
								{
									msg_push(J->id, "�����ϴ�.\n����� ���� �����ϴ� �������� Ȱ���� �����ϰڽ��ϴ�.");
								}
							}
							agr(I->id, J->id, -20);
						}
					}
				}
			}
			break;
		}
	}
}

void booking(int i, int edu)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			auto o = education.begin();
			int j = 0;
			for (; o != education.end(); o++, j++)
			{
				if (j == edu)
				{
					auto J = man.begin();
					for (; J != man.end(); J++)
					{
						if (J->id == o->owner)
						{
							if (I->traits["������ ����"])
							{
								agr(I->id, J->id, 20);
							}
							else if (gr(I->id, J->id) < 30)
							{

							}
							else
							{
								I->traits["������ ����"] == true;
							}
							if (I->id == play_id)
							{
								if (I->traits["������ ����"])
								{
									msg_push(J->id, "������ �̹� �ٸ� ������� ���� ���� �ް� �ֽ��ϴ�.\n�� ���� ����ģ�ڿ� �ٽ� ������ �ֽÿ�.");
								}
								else if (gr(I->id, J->id) < 30)
								{
									msg_push(J->id, "�츮�� �츮�� ���� �ൿ�Ұ̴ϴ�.\n�̷� ������ �ϱ����� �츮�� ���踦\n�����غ��ÿ�");
								}
								else
								{
									msg_push(J->id, "���� ������\n������ ��� ���� �Ͻðڽ��ϴ�.\n�׸��� ã�ƺ˱�� ����.");
								}
							}
							agr(I->id, J->id, -20);
						}
					}
				}
			}
			break;
		}
	}
}

void jirassi(int i, int med)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			auto o = education.begin();
			int j = 0;
			for (; o != education.end(); o++, j++)
			{
				if (j == med)
				{
					auto J = man.begin();
					for (; J != man.end(); J++)
					{
						if (J->id == o->owner)
						{
							if (I->traits["����"])
							{
								agr(I->id, J->id, 20);
							}
							else if (gr(I->id, J->id) < 30)
							{

							}
							else
							{
								I->traits["����"] == true;
							}
							if (I->id == play_id)
							{
								if (I->traits["����"])
								{
									msg_push(J->id, "�۽���ô�.\n�̹� ����� �̽��� �߽ɿ� �־\n���õ� ��縦 ���� ��ƽ��ϴ�.");
								}
								else if (gr(I->id, J->id) < 30)
								{
									msg_push(J->id, "�츮�� �츮�� ���� �ൿ�Ұ̴ϴ�.\n�̷� ������ �ϱ����� �츮�� ���踦\n�����غ��ÿ�");
								}
								else
								{
									msg_push(J->id, "���� ������\n����� ���Ͻø� ���� �׸� ���� ���ϰڽ��ϴ�.");
								}
							}
							agr(I->id, J->id, -20);
						}
					}
				}
			}
			break;
		}
	}
}
void impress(int i, int med)
{
	auto I = man.begin();
	for (; I != man.end(); I++)
	{
		if (I->live && I->id == i)
		{
			auto o = education.begin();
			int j = 0;
			for (; o != education.end(); o++, j++)
			{
				if (j == med)
				{
					auto J = man.begin();
					for (; J != man.end(); J++)
					{
						if (J->id == o->owner)
						{
							if (gr(I->id, J->id) < 30)
							{

							}
							else
							{
								I->prestige+= 50;
							}
							if (I->id == play_id)
							{
								if (gr(I->id, J->id) < 30)
								{
									msg_push(J->id, "�츮�� �츮�� ���� �ൿ�Ұ̴ϴ�.\n�̷� ������ �ϱ����� �츮�� ���踦\n�����غ��ÿ�");
								}
								else
								{
									msg_push(J->id, "���� ������\n�� ����� ������ Ī���ϴ� ��翡 ���ؼ� �ۼ��ϰڽ��ϴ�.");
								}
							}
							agr(I->id, J->id, -20);
						}
					}
				}
			}
			break;
		}
	}
}