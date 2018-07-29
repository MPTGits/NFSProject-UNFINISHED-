#pragma once
#include "Car.h"
class AllTypeRacer
{
private:
	void copy(const AllTypeRacer& other);
	void erase();
protected:
	int numOfRaces;
	int experience;
	char *name;
	Car * ownedCar;
public:
	AllTypeRacer();
	AllTypeRacer(const AllTypeRacer& ohter);
	AllTypeRacer& operator=(const AllTypeRacer& other);
	int get_NumOfRaces()const;
	void set_NumOfRaces(int races);
	virtual void print() const;
	void set_Experience(int experience);
	int get_Experience() const;
	void set_Name(const char* name);
	const char* get_Name()const;
	virtual void customerToBuy() = 0;
	virtual bool isHuman() const=0;
	virtual int get_Money() const=0;
	virtual void set_Money(int money)=0;
	virtual void addANewCar(const Car& newCar)=0;
	//Input int i =>and index that we want the car to be moved to the last index and 
	//all of its parameters made as 0
	Car* get_ownedCar() const;
	virtual void removingACar(int i)=0;
	virtual void printCars() const=0;
	virtual void nullCar(Car& nullThisCar)=0;
	virtual void pickACar()=0;
	virtual ~AllTypeRacer();
};

