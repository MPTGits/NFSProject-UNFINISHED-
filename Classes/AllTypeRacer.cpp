#include "stdafx.h"
#include "AllTypeRacer.h"
#include <cstring>
#include <iostream>


void AllTypeRacer::copy(const AllTypeRacer & other)
{
	this->experience = other.experience;
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
}
void AllTypeRacer::erase() {
	delete[] name;
	delete[] ownedCar;
}

AllTypeRacer::AllTypeRacer()
{
	this->experience = 0;
}

AllTypeRacer::AllTypeRacer(const AllTypeRacer& other) {
	copy(other);
}

AllTypeRacer& AllTypeRacer::operator=(const AllTypeRacer& other) {
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

int AllTypeRacer::get_NumOfRaces() const
{
	return numOfRaces;
}

void AllTypeRacer::set_NumOfRaces(int races)
{
	this->numOfRaces = races;
}

void AllTypeRacer::print() const
{
	std::cout << "Racer name is:" << name << std::endl;
	std::cout << "Experience:" << experience << std::endl;
}

void AllTypeRacer::set_Experience(int experience)
{
	this->experience += experience;
}

int AllTypeRacer::get_Experience() const
{
	return experience;
}

void AllTypeRacer::set_Name(const char * name)
{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
}

const char * AllTypeRacer::get_Name() const
{
	return name;
}


Car* AllTypeRacer::get_ownedCar() const
{
	return ownedCar;
}

AllTypeRacer::~AllTypeRacer()
{
	erase();
}

