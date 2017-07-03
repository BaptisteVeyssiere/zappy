//
// Exception.hpp for zappy in /home/scutar_n/rendu/PSU/PSU_2016_zappy/client
//
// Made by Nathan Scutari
// Login   <scutar_n@epitech.net>
//
// Started on  Wed Jun 21 17:59:14 2017 Nathan Scutari
// Last update Wed Jun 21 18:27:19 2017 Nathan Scutari
//

#ifndef __EXCEPTION_HPP__
# define __EXCEPTION_HPP__

#include <string>

namespace zappy
{
  class	client_exception : public std::exception
  {
  private:
    std::string	_msg;
    int		_line;
    std::string	_file;

  public:
    ~client_exception() noexcept {}
    client_exception(std::string const &msg, int line, std::string file)
      : _msg(msg), _line(line), _file(file)
    {
      _msg += "\n(in \"" + _file + "\"" + " at line " + std::to_string(_line) + ")";
    }

    const char* what() const noexcept
    {
      return (_msg.c_str());
    }
  };
}
#endif // !__EXCEPTION_HPP__
