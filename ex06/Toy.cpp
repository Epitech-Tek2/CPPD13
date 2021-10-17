/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Toy
*/

#include "Toy.hpp"

/////////////////////////////////////////////////////////////////////////////
///
/// Constructor
///
/////////////////////////////////////////////////////////////////////////////

Toy::Toy() noexcept :
    _name{"toy"}, _type{BASIC_TOY} {}

Toy::Toy(ToyType type, std::string const& name, std::string const& ascii) noexcept :
    _picture{ascii}, _name{name}, _type{type} {}

Toy::Toy(Toy const& toy) noexcept :
    _picture(toy._picture), _name{toy._name}, _type{toy._type} {}

Toy::Error::Error() noexcept :
    type(UNKNOWN) {}

/////////////////////////////////////////////////////////////////////////////
///
/// Getter
///
/////////////////////////////////////////////////////////////////////////////

int Toy::getType() const noexcept
{
    return (_type);
}

std::string const& Toy::getName() const noexcept
{
    return (_name);
}

std::string const& Toy::getAscii() const noexcept
{
    return (_picture.data);

}

/////////////////////////////////////////////////////////////////////////////
///
/// Setter
///
/////////////////////////////////////////////////////////////////////////////

bool Toy::setAscii(std::string const& ascii) noexcept
{
    if (_picture.getPictureFromFile(ascii)) return (true);
    _error.setType(Error::PICTURE);
    return (false);
}

void Toy::setName(std::string const& name) noexcept
{
    _name = name;
}

/////////////////////////////////////////////////////////////////////////////
///
/// Speak
///
/////////////////////////////////////////////////////////////////////////////
bool Toy::speak(const std::string message) noexcept
{
    cOut(_name << " \"" << message << "\"");
    return (true);
}

bool Toy::speak_es(std::string const message __attribute__((unused))) noexcept
{
   if (getType() != 2) {
        _error.setType(Error::SPEAK);
        return (false);
    }
    std::cout << "BUZZ: " << _name << " senorita \"" << message << "\" senorita" << std::endl;
    return (true);
}

void Toy::Error::setType(ErrorType type) noexcept
{
    this->type = type;
}

/////////////////////////////////////////////////////////////////////////////
///
/// Operator
///
/////////////////////////////////////////////////////////////////////////////
Toy& Toy::operator=(Toy const& toy) noexcept
{
    _name = toy._name;
    _picture = toy._picture;
    _type = toy._type;
    return (*this);
}

Toy& Toy::operator<<(std::string const& ascii) noexcept
{
    _picture.data = ascii;
    return (*this);
}

std::ostream& operator<<(std::ostream& stream, Toy const& toy) noexcept
{
    return (stream << toy.getName() << std::endl << toy.getAscii() << std::endl);
}

std::string Toy::Error::where() const noexcept
{
    return (PICTURE == type) ? ("setAscii") :
    (type == SPEAK) ? ("speak_es") : "";
}

std::string Toy::Error::what() const noexcept
{
    return (PICTURE == type) ? ("bad new illustration") :
    (type == SPEAK) ? ("wrong mode") : "";
}

Toy::Error const& Toy::getLastError() const noexcept
{
    return (_error);
}