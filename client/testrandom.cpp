//
// testrandom.cpp for random in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jul  1 01:43:25 2017 vigner_g
// Last update Sat Jul  1 15:36:23 2017 vigner_g
//

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>

int main()
{
  std::srand(std::time(0) + getpid());
  // use current time as seed for random generator
  int random_variable = std::rand() % 9999;
  std::cout << "Random value on [0 " << RAND_MAX << "]: "
	    << random_variable << '\n';
}
