/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Buzz
*/

#pragma once

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        Buzz(std::string const& name, std::string const& filename = "buzz.txt") noexcept;
        Buzz(Buzz const& buzz) noexcept;
        virtual ~Buzz() = default;

        virtual bool speak(std::string const message) const noexcept;
};