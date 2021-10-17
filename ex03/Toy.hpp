/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPD13-clement.muth
** File description:
** Toy
*/

#pragma once

#include <string>
#include <iostream>
#include "Picture.hpp"

#define cOut(message) std::cout << message << std::endl

class Toy
{
    public:
        enum ToyType
        {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Constructor
        ///
        /////////////////////////////////////////////////////////////////////////////
        Toy() noexcept;
        Toy(Toy const& toy) noexcept;
        Toy(ToyType type, std::string const& name, std::string const& ascii) noexcept;
        virtual ~Toy() = default;

        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Getter
        ///
        /////////////////////////////////////////////////////////////////////////////
        int getType() const noexcept;
        std::string const& getAscii() const noexcept;
        std::string const& getName() const noexcept;

        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Setter
        ///
        /////////////////////////////////////////////////////////////////////////////
        bool setAscii(std::string const& ascii) noexcept;
        void setName(std::string const& name) noexcept;

        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Speak
        ///
        /////////////////////////////////////////////////////////////////////////////
        virtual bool speak(std::string const message) const noexcept;

        Toy& operator=(Toy const& toy) noexcept;

    protected:
        Picture _picture;
        std::string _name;
        ToyType _type;
    private:
};