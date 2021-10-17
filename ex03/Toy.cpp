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
bool Toy::speak(const std::string message) const noexcept
{
    cOut(_name << " \"" << message << "\"");
    return (true);
}

Toy& Toy::operator=(Toy const& toy) noexcept
{
    _name = toy._name;
    _picture = toy._picture;
    _type = toy._type;
    return (*this);
}