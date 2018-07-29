#pragma once
#include "AIRacer.h"
#include "HumanRacer.h"
#include "Car.h"
#include "ShopForCars.h"
#include "AllTypeRacer.h"
#include "ListOfCars.h"

class MainGame
{
private:
	int allCompetetors;
	int humanPlayers;
	int AIPlayers;
	AllTypeRacer** allRacers;
	void copy(const MainGame& other);
	void erase();
public:
	MainGame(int humanPlayers,int AIPlayers);
	MainGame(const MainGame& other);
	MainGame& operator=(const MainGame& other);
	void print()const;
	int get_humanPlayers() const;
	int get_AIPlayers() const;
	int get_allCompetetors() const;
	AllTypeRacer* get_Competetor(int i) const;
	void set_CarUser(AllTypeRacer* newRacer, int i);
	~MainGame();
};

