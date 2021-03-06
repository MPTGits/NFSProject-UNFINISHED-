// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "AIRacer.h"
#include "Car.h"
#include "HumanRacer.h"
#include "ListOfCars.h"
#include "ShopForCars.h"
#include "MainGame.h"
using namespace std;

void race1vs1(AllTypeRacer * p1, AllTypeRacer * p2)
{	
	int p1nitroBonus = 0;
	int p2nitroBonus = 0;
	if (p1->get_NumOfRaces() % 3 == 0) p1nitroBonus = p1->get_ownedCar()->get_nitroCarBonus();
	if (p2->get_NumOfRaces() % 3 == 0) p1nitroBonus = p2->get_ownedCar()->get_nitroCarBonus();
	double koefP1 = (p1->get_Experience() + p1->get_ownedCar()->get_forceOfCar()+p1nitroBonus)*(100 + rand() % 21);
	double koefP2 = (p2->get_Experience() + p2->get_ownedCar()->get_forceOfCar()+p2nitroBonus)*(100 + rand() % 21);
	p1->set_NumOfRaces(p1->get_NumOfRaces() + 1);
	p2->set_NumOfRaces(p2->get_NumOfRaces() + 1);

	int priceStacke = rand() % 40;
	int expWon = rand() % 20;
	if (koefP1 > koefP2) {
		if (p1->isHuman()) {
			p1->set_Money(priceStacke);
			p1->set_Experience(expWon);
			std::cout << "+" << priceStacke << "$ for";
		}
		else {
			p1->set_Experience(expWon + rand() % 10);
		}
		std::cout << "(WON)" << p1->get_Name() << "  and now has " <<p1->get_Experience() << "exp"<<std::endl;
		if (p2->isHuman()) {
			p2->set_Money(-priceStacke);
			p2->set_Experience(expWon % 10);
			std::cout << "-" << priceStacke << "$ for";
			
		}
		else {
			p2->set_Experience(expWon % 2 + rand() % 10);
		}
		std::cout << "(LOST)" << p2->get_Name() << "  and now has " << p2->get_Experience() << "exp"<<std::endl;
		std::cout << std::endl;
		return;
	}
	else {
		if (p1->isHuman()) {
			p1->set_Money(-priceStacke);
			p1->set_Experience(expWon%10);
			std::cout << "-" << priceStacke << "$ for";
		}
		else {
			p1->set_Experience(expWon % 2 + rand()%10);
		}
			std::cout << "(LOST)"<<p1->get_Name() << " and now has " << p2->get_Experience() << "exp"<<std::endl;
			if (p2->isHuman()) {
				p2->set_Money(priceStacke);
				p2->set_Experience(expWon);
				std::cout << "+" << priceStacke << "$ for";
			}
			else {
				p2->set_Experience(expWon+rand()%10);
			}
			std::cout <<"(WON)" <<p2->get_Name() << " and now has " << p2->get_Experience() << "exp"<<std::endl;
			std::cout << std::endl;
			return ;
		}
	}


void mainGameFunction() {
	char* userInput = new char[1000];
	std::cout << "Hello and welcome to the NFS game simulator!" << std::endl;
	int humanPlayers, NPCPlayers;
	std::cout << "Select the number of Human players,please:";
	cin >> humanPlayers;
	std::cout << std::endl;
	std::cout << "Select the number of NPC players,please:";
	cin >> NPCPlayers;
	std::cout << std::endl;
	MainGame mainGame(humanPlayers, NPCPlayers);
	do {
		std::cout << " Now you can type down what you want to do!" << std::endl;
		std::cout << "(1)Race" << std::endl;
		std::cout << "(2)Shop" << std::endl;
		std::cout << "(3)Exit" << std::endl;
		cin.getline(userInput, 1000);
		std::cout << std::endl;
		if ((strcmp(userInput, "Race") == 0)) {
			for (int i = 0; i < mainGame.get_humanPlayers(); ++i) {
				AllTypeRacer * tmp = new HumanRacer;
				tmp = mainGame.get_Competetor(i);
				std::cout << "Player " << tmp->get_Name() << " pick a car to race with!" << std::endl;
				tmp->pickACar();
				mainGame.set_CarUser(tmp, i);

			}

			mainGame.print();
			for (int i = 0; i < mainGame.get_humanPlayers(); ++i) {
				int userRacePicker;
				do {
					std::cout << std::endl;
					std::cout << "Now player " << mainGame.get_Competetor(i)->get_Name() << " pick someone to race!" << std::endl;
					cin >> userRacePicker;
				} while (userRacePicker >= mainGame.get_allCompetetors() || userRacePicker < 0 || userRacePicker == i);
				race1vs1(mainGame.get_Competetor(i), mainGame.get_Competetor(userRacePicker));
			}

		}
		else if ((strcmp(userInput, "Shop") == 0)) {
			for (int i = 0; i < mainGame.get_humanPlayers(); ++i) {
				std::cout << "Player " << mainGame.get_Competetor(i)->get_Name() << " turns to buy!" << std::endl;
				mainGame.get_Competetor(i)->customerToBuy();
			}
			continue;
		}
	} while (strcmp(userInput, "Exit") != 0);
	std::cout << "Thank you for playing your final stats are:" << std::endl;
	for (int i = 0; i < mainGame.get_humanPlayers(); ++i) {
		std::cout << "------------------" << std::endl;
		std::cout << "Number of races:" << mainGame.get_Competetor(i)->get_NumOfRaces()<<std::endl;
		mainGame.get_Competetor(i)->print();
		std::cout << std::endl;
		std::cout << "Owned Cars:" << std::endl;
		mainGame.get_Competetor(i)->printCars();

	}
}





int main()
{
	mainGameFunction();
	//Всичко от тук надолу са тестове(да не се гледа)
	//AllTypeRacer mario;
	//MainGame mario(4, 2);
	//mario.print();
	/*
	AllTypeRacer* Paul=new HumanRacer("Ivan");
	AIRacer* Frank=new AIRacer;
	AllTypeRacer* Paul2 = new HumanRacer("Petur");
	AIRacer* Frank2 = new AIRacer;
	AIRacer* Fran2 = new AIRacer;
	Fran2->set_Experience(0);
	std::cout << "robo" << std::endl;
	race1vs1(Frank2, Fran2);
	race1vs1(Frank2, Paul);
	race1vs1(Frank2, Paul);
	race1vs1(Frank2, Paul);
	race1vs1(Frank2, Paul2);
	race1vs1(Frank2, Frank);
	std::cout<<"robo" << std::endl;
	AllTypeRacer* Paul3 = new HumanRacer("Stoyan");
	AIRacer* Frank3 = new AIRacer;
	std::cout << "Stoyo" << std::endl;
	race1vs1(Paul3, Frank3);
	race1vs1(Paul3, Frank2);
	race1vs1(Paul3, Frank);
	std::cout << "Stoyo" << std::endl;
	//Frank2->print();
	Paul3->print();
	/*
	HumanRacer Ivan("Ivanov");
	Ivan.set_Money(210);
	ShopForCars shop;
	Ivan.customerToBuy();
	Ivan.printCars();
	std::cout << Ivan.get_Money();
	std::cout << std::endl;
	Ivan.print();
	*/
	/*
	AIRacer Pitty;
	Pitty.print();
	AIRacer Pitty2;
	Pitty2.print();
	HumanRacer Freddy2("Ivanov");
	Freddy2.print();
	HumanRacer Freddy1("Ivanov");
	Freddy1.printCars();
	std::cout << std::endl;
	Car BMW(20, 20);
	Freddy1.addANewCar(BMW);
	Freddy1.addANewCar(BMW);
	Freddy1.removingACar(1);
	Freddy1.addANewCar(BMW);
	Freddy1.printCars();
	//Freddy1.printCars();
	*/


    return 0;
}

