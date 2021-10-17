/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string const& name, std::string const& filename) noexcept :
    Toy{WOODY, name, filename} {}

Woody::Woody(Woody const& woody) noexcept :
    Toy{woody} {}

bool Woody::speak(std::string const message) noexcept
{
    std::cout << "WOODY: ";
    Toy::speak(message);
    return (true);
}