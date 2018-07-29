#include "stdafx.h"
#include "Car.h"
#include <iostream>
#include  <cassert>


Car::Car(double forceOfCar, int nitroCarBonus,const char* carType)
{
	assert(forceOfCar >= 0 && nitroCarBonus >= 0);
	strcpy_s(this->carType, strlen(carType)+1, carType);
	this->forceOfCar = forceOfCar;
	this->nitroCarBonus = nitroCarBonus;
	this->priceOfCar = 0;
}
double Car::get_forceOfCar() const {
	return forceOfCar;
}
int Car::get_nitroCarBonus() const {
	return nitroCarBonus;
}
void Car::set_forceOfCar(double forceOfCar) {
	this->forceOfCar = forceOfCar;
}
void Car::set_nitroCarBonus(int nitroCarBonus) {
	this->nitroCarBonus = nitroCarBonus;
}

void Car::set_CarType(const char *carType)
{
	strcpy_s(this->carType, strlen(carType) + 1, carType);
}

void Car::print() const {
	std::cout << std::endl;
	std::cout << "Car type is:" << carType << std::endl;
	std::cout << "Car force is:" << forceOfCar << std::endl;
	std::cout << "Nitro bonus of this Car is:" << nitroCarBonus << std::endl;
	std::cout << "Car price is:" << priceOfCar << std::endl;
}

int Car::get_PriceOfCar() const
{
	return priceOfCar;
}

void Car::set_PriceOfCar(int priceOfCar)
{
	this->priceOfCar = priceOfCar;
}
