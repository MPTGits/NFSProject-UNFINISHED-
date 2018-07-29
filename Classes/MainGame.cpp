#include "stdafx.h"
#include "MainGame.h"
#include <iostream>
#include <cassert>
#include <string>


void MainGame::copy(const MainGame & other)
{
	this->humanPlayers = other.humanPlayers;
	this->AIPlayers = other.AIPlayers;
	this->allCompetetors = allCompetetors;
	erase();
	this->allRacers = new AllTypeRacer*[allCompetetors];
		for (int i = 0; i < allCompetetors; ++i) {
			allRacers[i] = other.allRacers[i];
	}

}

void MainGame::erase()
{
	for (int i = 0; i < allCompetetors; ++i) {
		delete allRacers[i];
	}
	delete[] allRacers;
}

MainGame::MainGame(int humanPlayers,int AIPlayers)
{
	//assert(humanPlayers > 0 && AIPlayers >= 0);
	this->humanPlayers = humanPlayers;
	this->AIPlayers = AIPlayers;
	this->allCompetetors = humanPlayers + AIPlayers;
	this->allRacers = new AllTypeRacer*[allCompetetors];
	int counter = 0;
	char* nameInput=new char[100];
	for (counter; counter < humanPlayers; ++counter) {
			allRacers[counter] = new HumanRacer;
			std::cout << "Input racer ¹" << counter + 1 << " name!" << std::endl;
			if(counter==0) std::cin.ignore();
			std::cin.getline(nameInput,1000);
			allRacers[counter]->set_Name(nameInput);
			
	}
	for (counter; counter< allCompetetors; ++counter) {
		allRacers[counter] = new AIRacer;
	}
	//allRacers[counter - 2]->print();

}

MainGame::MainGame(const MainGame & other)
{
	copy(other);
}

MainGame & MainGame::operator=(const MainGame & other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}


void MainGame::print() const
{
	for (int i = 0; i < allCompetetors; ++i) {
		std::cout << "/////////////////////////////" << std::endl;
		std::cout <<"COMPETETOR AT SLOT "<<i<< std::endl;
		allRacers[i]->print();
		std::cout << "/////////////////////////////" << std::endl;
	}
}

int MainGame::get_humanPlayers() const
{
	return humanPlayers;
}

int MainGame::get_AIPlayers() const
{
	return AIPlayers;
}

int MainGame::get_allCompetetors() const
{
	return allCompetetors;
}

AllTypeRacer * MainGame::get_Competetor(int i) const
{
	return allRacers[i];
}

void MainGame::set_CarUser(AllTypeRacer * newRacer, int i)
{
	this->allRacers[i] = newRacer;
}

MainGame::~MainGame()
{
	erase();
}


