#include <iostream>
#include "game_of_life.h"

using namespace std;

void GoL::start()
{
	char repeat = 0;
	this->rndDisplay();

	do {

		this->display();
		this->nextStep();
		this->copy();
		cout << "Continue? (y/n): ";
		cin >> repeat;
		system("cls");
	} while (repeat == 'y');
}

void GoL::rndDisplay()
{

	for (int i = 0; i < this->Row; ++i)
	{
		for (int l = 0; l < this->Colum; ++l)
		{
			this->current[i][l] = '-';
		}
	}

	for (int i = 0; i < this->Row; i += 2)
	{
		for (int l = 0; l < this->Colum; l++)
		{
			if (this->rndNum(4, 1) == 1) {
				this->current[i][l] = '*';
			}
		}
	}
}

int GoL::rndNum(int max, int min)
{
	return rand() % (max - min + 1) + min;
}

void GoL::display()
{

	for (int i = 0; i < this->Row; i++)
	{
		for (int l = 0; l < this->Colum; l++)
		{
			if (this->current[i][l] != '*')
				this->current[i][l] = '-';

			cout << this->current[i][l];
		}
		cout << endl;
	}
}

void GoL::nextStep()
{
	int neighbouri;

	for (int i = 0; i < this->Row; i++)
	{
		for (int l = 0; l < this->Colum; l++)
		{
			neighbouri = this->checkNeighbour(i, l);
			if (neighbouri == 3)
				this->next[i][l] = '*';
			else if (this->current[i][l] == '*' && neighbouri == 2)
				this->next[i][l] = '*';
			else
				next[i][l] = '-';
		}

	}
}

int GoL::checkNeighbour(int row, int colum)
{
	int neighbour = 0;

	if (this->current[row - 1][colum + 1] == '*')
		++neighbour;
	if (this->current[row - 1][colum - 1] == '*')
		++neighbour;
	if (this->current[row - 1][colum] == '*')
		++neighbour;
	if (this->current[row + 1][colum + 1] == '*')
		++neighbour;
	if (this->current[row + 1][colum - 1] == '*')
		++neighbour;
	if (this->current[row + 1][colum] == '*')
		++neighbour;
	if (this->current[row][colum + 1] == '*')
		++neighbour;
	if (this->current[row][colum - 1] == '*')
		++neighbour;

	return neighbour;
}

void GoL::copy()
{
	for (int i = 0; i < this->Row; i++)
	{
		for (int l = 0; l < this->Colum; l++)
		{
			this->current[i][l] = this->next[i][l];
		}
	}
}