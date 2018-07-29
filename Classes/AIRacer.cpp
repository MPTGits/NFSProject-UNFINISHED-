#include "stdafx.h"
#include "AIRacer.h"
#include <iostream>

void AIRacer::copy(const AIRacer & other)
{
	this->ownedCar = new Car;
	this->ownedCar = other.get_ownedCar();
}

AIRacer::AIRacer():AllTypeRacer()
{
	int lenOfName = rand() % 5+2;
	this->name = new char[lenOfName+1];
	for (int i = 0; i < lenOfName; ++i) {
		this->name[i] = (char)(rand() % 26 + 65);
	}
	this->ownedCar = new Car;
	this->name[lenOfName] = '\0';
	int ifHasNitro = (rand() > RAND_MAX / 2) ? 0 : 3;
	this->ownedCar->set_forceOfCar(rand() % 3 + 1);
	this->ownedCar->set_nitroCarBonus(ifHasNitro);
}

AIRacer::AIRacer(const AIRacer& other):AllTypeRacer(other) {
	copy(other);
}

AIRacer& AIRacer::operator=(const AIRacer& other) {
	if (this != &other) {
		AllTypeRacer::operator=(other);
		copy(other);
	}
	return *this;
}

void AIRacer::print() const
{
	std::cout << std::endl;
	AllTypeRacer::print();
	ownedCar->print();
}

bool AIRacer::isHuman() const
{
	return false;
}

void AIRacer::addANewCar(const Car & newCar)
{
}

void AIRacer::removingACar(int i)
{
}

void AIRacer::printCars() const
{
}

void AIRacer::nullCar(Car & nullThisCar)
{
}

void AIRacer::pickACar()
{
}

int AIRacer::get_Money() const
{
	return 0;
}

void AIRacer::set_Money(int money)
{
}

void AIRacer::customerToBuy() 
{
}

AIRacer::~AIRacer()
{
}
