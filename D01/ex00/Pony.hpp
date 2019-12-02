#ifndef PONY_HPP
#define PONY_HPP
#include <string>

class Pony
{
    private:
            std::string name;
            std::string breed;
            std::string suit;
            std::string food;
    public:
            Pony(std::string name, std::string breed, std::string suit, std::string food);
            ~Pony();

            void    feedPony(void);
            void    lookAtPony(void);
};

#endif //CPP_GIT_PONY_HPP
