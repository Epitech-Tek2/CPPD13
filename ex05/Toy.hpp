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
        /// Error
        ///
        /////////////////////////////////////////////////////////////////////////////
        class Error
        {
            public:
                enum ErrorType
                {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };

                ErrorType type;

                Error() noexcept;
                ~Error() = default;

                void setType(ErrorType type) noexcept;
                std::string what() const noexcept;
                std::string where() const noexcept;

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
        virtual bool speak_es(std::string const message) noexcept;

        /////////////////////////////////////////////////////////////////////////////
        ///
        /// Operator
        ///
        /////////////////////////////////////////////////////////////////////////////
        Toy& operator=(Toy const& toy) noexcept;
        Toy& operator<<(std::string const& ascii) noexcept;

        Error const& getLastError() const noexcept;

    protected:
        Picture _picture;
        std::string _name;
        ToyType _type;
        Error _error;
};

std::ostream& operator<<(std::ostream& stream, Toy const& toy) noexcept;