/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string const& name, std::string const& filename) noexcept :
    Toy{BUZZ, name, filename} {}

Buzz::Buzz(Buzz const& buzz) noexcept :
    Toy{buzz} {}