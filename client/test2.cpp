//
// test2.cpp for test2 in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Thu Jun 29 15:29:46 2017 vigner_g
// Last update Thu Jun 29 15:40:30 2017 vigner_g
//

#include <iostream>
#include <map>

int	main()
{
  std::map<std::string, int>	inv;

  inv["banane"] = 12;
  inv["patate"] = 5;

    inv["tomate"] += 1;

  // auto it2 = inv.find("patate");
  // if (it2 != inv.end())
  //   inv[it2->first] += 1;
  // else
    inv["patate"] += 1;

  for(auto it3 = inv.begin(); it3 != inv.end(); it3++)
    std::cout << it3->first << " => " << it3->second << std::endl;
}
