//
// testdelete.cpp for test in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Sat Jul  1 00:00:28 2017 vigner_g
// Last update Sat Jul  1 00:18:52 2017 vigner_g
//

#include <string>
#include <iostream>

std::string     retNext(std::string str, std::string tofind)
{
  size_t	pos;

  if ((pos = str.find(tofind)) != std::string::npos)
    str.erase(0, pos);
  if ((pos = str.find(" ")) != std::string::npos)
    str.erase(0, pos + 1);
  if ((pos = str.find(" ")) != std::string::npos)
    str.erase(pos, str.back());
  return(str);
}


int	main()
{
  std::string	tmp = "ta mere aime la bite!";

  std::cout << retNext(tmp, "la") << "==>" <<  retNext(tmp, "ta") << "==>" <<  retNext(tmp, "!") << std::endl;
}
