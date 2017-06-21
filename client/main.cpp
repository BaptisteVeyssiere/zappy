//
// main.cpp for test in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Wed Jun 21 17:47:48 2017 vigner_g
// Last update Wed Jun 21 18:34:43 2017 vigner_g
//

#include <map>
#include <iostream>

int	main()
{
  std::map<std::string, int>	commonInventory;
  std::map<std::string, int>	Inventory;

  Inventory["linemate"] = 5;
  Inventory["deraumere"] = 3;
  Inventory["silbur"] = 2;
  Inventory["mendiane"] = 4;
  Inventory["phiras"] = 8;
  Inventory["thystame"] = 9;

  commonInventory = Inventory;

  for(std::map<std::string, int>::iterator it = commonInventory.begin();
      it != commonInventory.end(); it++)
    {
      std::cout << it->first << " => " << it->second << std::endl;
    }
  commonInventory.clear();
  std::cout << "size: " << commonInventory.size() << std::endl;
  commonInventory = Inventory;
  auto it = commonInventory.find("thystame");
  commonInventory.erase(it);
  //add 2 tableaux;
  for(auto it = Inventory.begin(); it != Inventory.end(); ++it)
    commonInventory[it->first] += it->second;
  //afficher un tableau
  for(auto it = commonInventory.begin(); it != commonInventory.end(); ++it)
    std::cout << it->first << " => " << it->second << std::endl;
}
