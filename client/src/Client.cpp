//
// Client.cpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Tue Jun 20 16:10:12 2017 Nathan Scutari
// Last update Sat Jun 24 15:04:50 2017 Nathan Scutari
//

#include "Client.hpp"

zappy::Client::Client(std::string port, std::string team, std::string machine = localhost)
  :info(), mNet()
{
  mNet.connectToServer(machine, port, team);
}

zappy::Client::~Client()
{
  mNet.disconnect();
}
