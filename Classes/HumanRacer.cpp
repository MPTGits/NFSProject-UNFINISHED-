#include "stdafx.h"
#include "HumanRacer.h"
#include "ListOfCars.h"
#include "ShopForCars.h"
#include <cstring>
#include <iostream>
#include <cassert>

void HumanRacer::customerToBuy()
{
	printShopCars();
	int customerChoice;
	std::cout << "Car at which slot would you like to buy?(to exit shop input -1)" << std::endl;
	do {
		std::cout << std::endl;
		std::cout << "You have " << get_Money() << "$ select a car you can afford!" << std::endl;
		std::cin >> customerChoice;
		if (customerChoice == -1) return;
	} while (!((customerChoice >= 0 && customerChoice<=8)
		&& (get_Money() >= listOfCars[customerChoice].get_PriceOfCar())));

	std::cout << customerChoice << std::endl;
	addANewCar(listOfCars[customerChoice]);
	set_Money(get_Money() - listOfCars[customerChoice].get_PriceOfCar());
	std::cout << std::endl;
}


void HumanRacer::copy(const HumanRacer & other)
{
	this->currentCars = other.currentCars;
	this->carSlotSize = other.carSlotSize;
	this->ownedCar = new Car[carSlotSize];
	for (int i = 0; i < carSlotSize; ++i) {
		ownedCar[i] = other.ownedCar[i];
	}

}

HumanRacer::HumanRacer(const char* name):AllTypeRacer()
{
	this->currentCars = 1;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->money = 0;
	this->carSlotSize = 2;
	int ifHasNitro = (rand() > RAND_MAX / 2) ? 0 : 3;
	this->ownedCar = new Car[carSlotSize];
	ownedCar[0].set_forceOfCar(rand() % 5 + 1);
	ownedCar[0].set_nitroCarBonus(ifHasNitro);
}

HumanRacer::HumanRacer(const HumanRacer & other):AllTypeRacer(other)
{
	copy(other);
}

HumanRacer & HumanRacer::operator=(const HumanRacer & other)
{
	if (this != &other) {
		AllTypeRacer::operator=(other);
		copy(other);
	}
	return *this;
}

bool HumanRacer::isHuman() const
{
	return true;
}

int HumanRacer::get_Money() const
{
	return money;
}


void HumanRacer::set_Money(int money)
{
	if ((this->money + money) < 0) {
		this->money = 0;
		return;
	}
	this->money +=money;
}

void HumanRacer::addANewCar(const Car & newCar)
{
	if (currentCars == carSlotSize) {
		std::cout << "Sorry your car slot is full you can try removing a car!"<<std::endl;
		return;
	}
	ownedCar[currentCars] = newCar;
	++currentCars;
	std::cout << "Carr added succesfully!" << std::endl;
}

void HumanRacer::removingACar(int i)
{
	assert(i < currentCars);
	if (currentCars == 1) {
		std::cout << "Can't remove last Car" << std::endl;
		return;
	}
	Car tmp;
	this->nullCar(ownedCar[i]);
	tmp=ownedCar[i];
	ownedCar[i] = ownedCar[currentCars - 1];
	ownedCar[currentCars - 1] = tmp;
	--currentCars;

}


void HumanRacer::printCars() const
{
	std::cout << std::endl;
	for (int i=0; i < currentCars; ++i) {
		std::cout << "--Car on slot ¹" << i << std::endl;
		ownedCar[i].print();
	}
	std::cout << std::endl;
}

void HumanRacer::nullCar(Car& nullThisCar)
{
	nullThisCar.set_forceOfCar(0);
	nullThisCar.set_nitroCarBonus(0);

}

void HumanRacer::print() const
{
	AllTypeRacer::print();
	std::cout << "Money:" << money << std::endl;
	ownedCar[0].print();
}

void HumanRacer::pickACar()
{
	int i;
	printCars();
	do {
		std::cout << "Pick a car number to race with:" << std::endl;
		std::cin >> i;
	} while (i<0|| i>currentCars);
	Car tmp = ownedCar[0];
	ownedCar[0] = ownedCar[i];
	ownedCar[i] = tmp;
}


HumanRacer::~HumanRacer()
{
}
