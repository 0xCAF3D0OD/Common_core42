//
// Created by Kevin Di nocera on 11/3/22.
//

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#define	BOLD_BLACK	"\033[1m\033[30m"
#define BOLD_RED	"\033[1m\033[31m"
#define BOLD_G		"\033[1m\033[32m"
#define	RESET   	"\033[0m"
#define BOLD_Y		"\033[1m\033[33m"
#define BOLD_W		"\033[1m\033[37m"
int main() {

	AAnimal	*list[100];

	for (int idx = 0; idx < 100; idx++)
	{
		std::cout << BOLD_Y  << std::endl << idx << ": " << RESET;
		if (idx < 50)
			list[idx] = new Dog();
		else if (idx < 100)
			list[idx] = new Cat();
	}
	for (int i = 0; i < 100; i++)
	{
		std::cout << std::endl << BOLD_G << i << ": " << RESET;
		delete list[i];
	}

	return 0;
}