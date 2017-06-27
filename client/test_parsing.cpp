//
// test_parsing.cpp for testpasrsing in /home/vigner_g/rendu/PSU_2016_zappy
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Mon Jun 26 17:05:06 2017 vigner_g
// Last update Tue Jun 27 15:24:03 2017 vigner_g
//

#include <string>
#include <iostream>

std::string	getSubString(std::string &phrase, std::string delimiter)
{
  std::string	ret;
  size_t	pos;

  if ((pos = phrase.find(delimiter)) == std::string::npos)
    {
      ret = phrase.substr(0, std::string::npos);
      phrase.erase(0, std::string::npos);
      return (ret);
    }
  ret = phrase.substr(0, pos);
  phrase.erase(0, pos + delimiter.length());
  return (ret);
}

int    main()
{
  std::string ret =
    "[player food,,,thystame food linemate demaumere,,food linemate,,,,,thystame food,,,,,,slt]";
  std::string	sub;
  std::string	sub2;
  int		a;

  ret.erase(0, 1);
  ret.erase(ret.size() - 1 ,ret.size());
  std::cout << ret << std::endl << "============================================================" << std::endl;
  while ((sub = getSubString(ret, ",")) != "*end*" && ret.size() > 0)
    {
      while ((sub2 = getSubString(sub, " ")) != "*end*" && sub2.size() > 0)
	{
	  std::cout << sub2 << "+";
	}
      std::cout << sub2;
      std::cout << std::endl;
    }
  std::cout << sub << std::endl;
}
