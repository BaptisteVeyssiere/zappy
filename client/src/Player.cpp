//
// Player.cpp for Player in /home/vigner_g/rendu/PSU_2016_zappy/client
//
// Made by vigner_g
// Login   <vigner_g@epitech.net>
//
// Started on  Tue Jun 20 17:04:08 2017 vigner_g
// Last update Mon Jul  3 18:17:47 2017 Nathan Scutari
//

#include <iostream>
#include <math.h>
#include "Inventory.hpp"
#include "Network.hpp"
#include "Player.hpp"
#include "Exception.hpp"
#include "C_broadcast.hpp"

zappy::Player::Player(World &world)
  : id(0), lvl(1), pos(), facing(0, 1), food(10), OwnInventory(),
    map(), teamNbPlayer(1), nbOfEgg(0), slot(0), onGoingAction(),
    toBroadcast(""), regroup(), leveling(false), mElevation(NULL),
    mJoin(NULL), start_elev(false), askList()
{
  OwnInventory.getInv()["food"] = 10;
  id = (std::rand() % 9999);
  map.setSize(world.width, world.height);
  slot = world.client_num;
}

zappy::Player::~Player()
{

}

void	zappy::Player::init(Elevation *instance, Join *join)
{
  mElevation = instance;
  mJoin = join;
}

void	zappy::Player::setFood(int nbr)
{
  food = nbr;
  OwnInventory.getInv()["food"] = nbr;
}

void	zappy::Player::SetTeamNbPlayer(int nb)
{
  this->teamNbPlayer = nb;
}

void	zappy::Player::SetId(int nb)
{
  this->id = nb;
}

void	zappy::Player::clearToBroadcast()
{
  std::cout << "clear" << std::endl;
  this->toBroadcast.clear();
}

void	zappy::Player::setToBroadcast(std::string msg)
{
  std::cout << "set " << msg << std::endl;
  this->toBroadcast.clear();
  this->toBroadcast = msg;
}

void	zappy::Player::AddALvl()
{
  this->lvl += 1;
}

zappy::Inventory &zappy::Player::getOwnInventory()
{
  return (this->OwnInventory);
}

t_position	&zappy::Player::getFacing()
{
  return (this->facing);
}

t_position	&zappy::Player::getPosition()
{
  return (this->pos);
}

int		&zappy::Player::getID()
{
  return (this->id);
}

int		zappy::Player::facingToAngle()
{
  static int		angle[] = {0, 90, 180, 270};
  static t_position	facing[] =
    {
      {0, -1},
      {1, 0},
      {0, 1},
      {-1, 0}
    };


  for (int i = 0 ; i < 4 ; ++i)
    {
      if (getFacing().x == facing[i].x &&
	  getFacing().y == facing[i].y)
	return (angle[i]);
    }
  throw client_exception("Unexpected facing values", __LINE__, __FILE__);
  return (0);
}

t_position	zappy::Player::getAbsolutePos(t_position &relative_pos)
{
  t_position	new_pos;
  int		angle;
  double	cosa;
  double	sina;

  angle = facingToAngle();
  cosa = cos(angle * M_PI / 180);
  sina = sin(angle * M_PI / 180);
  new_pos.x = round(relative_pos.x * cosa - relative_pos.y * sina);
  new_pos.y = round(relative_pos.x * sina + relative_pos.y * cosa);
  new_pos.x += getPosition().x;
  new_pos.y += getPosition().y;
  return (new_pos);
}

zappy::Map	&zappy::Player::getMap()
{
  return (this->map);
}

int		&zappy::Player::getLvl()
{
  return (this->lvl);
}

int		&zappy::Player::getSlot()
{
  return (this->slot);
}

int		&zappy::Player::getFood()
{
  return (food);
}

zappy::Regroup		&zappy::Player::getRegroup()
{
  return (this->regroup);
}

void		zappy::Player::setLeveling(bool val)
{
  leveling = val;
}

bool		&zappy::Player::getLeveling()
{
  return (leveling);
}

int		zappy::Player::getStoneValue(const std::string &stone) const
{
  return (mElevation->getStoneValue(stone));
}

std::string	&zappy::Player::getToBroadcast()
{
  std::cout << "get " << toBroadcast << std::endl;
  return (this->toBroadcast);
}

zappy::ICommand	*zappy::Player::elevation()
{
  ICommand	*choice;

  choice = new C_broadcast;
  choice->addArg("Elevation");
  choice->addArg(std::to_string(this->id));
  choice->addArg("LVL");
  choice->addArg(std::to_string(this->lvl));
  getRegroup().startElevating();
  return (choice);
}

zappy::ICommand	*zappy::Player::cancel()
{
  ICommand	*choice;

  choice = new C_broadcast;
  choice->addArg("Cancel");
  choice->addArg(std::to_string(this->id));
  getRegroup().resetIDS();
  getRegroup().stopElevating();
  return (choice);
}

zappy::ICommand	*zappy::Player::here()
{
  ICommand	*choice;

  choice = new C_broadcast;
  choice->addArg("Here");
  choice->addArg(std::to_string(getRegroup().getJoining()));
  choice->addArg("PlayerID");
  choice->addArg(std::to_string(this->id));
  return (choice);
}

zappy::ICommand	*zappy::Player::come()
{
  ICommand	*choice;

  choice = new C_broadcast;
  choice->addArg("Come");
  choice->addArg(std::to_string(this->id));
  for (int i = 0; i < getRegroup().getPlayerNbr() ; i ++)
    {
      choice->addArg("PlayerID" + std::to_string(i + 1));
      choice->addArg(std::to_string(getRegroup().getIDS()[i]));
    }
  return (choice);
}

void	zappy::Player::startElev()
{
  start_elev = true;
}

void	zappy::Player::stopElev()
{
  start_elev = false;
}

bool	zappy::Player::isElev()
{
  return (start_elev);
}

void	zappy::Player::addAsk(AskId &ask)
{
  askList.push_back(ask);
}

void	zappy::Player::refreshAskList()
{
  for (auto it = askList.begin() ; it != askList.end() ; ++it)
    {
      if (++(*it).timeout >= 150)
	{
	  it = askList.erase(it);
	  --it;
	}
    }
}

bool	zappy::Player::lowestId()
{
  for (auto it : askList)
    {
      if (it.id < id && it.lvl == lvl)
	return (false);
    }
  return (true);
}

zappy::Join	*zappy::Player::getJoin()
{
  return (mJoin);
}
