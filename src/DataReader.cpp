#include "DataReader.h"



DataReader::DataReader()
{
	readData();
}


void DataReader::readData()
{
	int a;
	int numberOfHumans, numberOfSickHumans, numberOfDoctors, turnDelay, humansHealth;
	std::cout << "Wpisz \n1.Wlasne dane do symulacji.\n2.Jedna z gotowych symulacji" << std::endl;
	std::cin >> a;
	if (a == 1)
	{
		system("cls");
		std::cout << "Podaj liczbe zdrowych osob: " << std::endl;
		std::cin >> numberOfHumans;
		std::cout << "Podaj liczbe chorych osob: " << std::endl;
		std::cin >> numberOfSickHumans;
		std::cout << "Podaj liczbe lekarzy: " << std::endl;
		std::cin >> numberOfDoctors;
		std::cout << "Podaj opoznienie tur: " << std::endl;
		std::cin >> turnDelay;
		std::cout << "Podaj dlugosc zycia ludzi: " << std::endl;
		std::cin >> humansHealth;
	}
	MapDrawer("europa.png", turnDelay, humansHealth, numberOfHumans, numberOfSickHumans, numberOfDoctors);
}