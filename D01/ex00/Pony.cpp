//
// Created by Vitaliy Siveniuk on 12/2/19.
//

#include <iostream>
#include "Pony.hpp"

Pony::Pony(std::string name, std::string breed, std::string suit, std::string food) : name{name}, breed{breed}, suit{suit}, food{food}
{
    std::cout << this->name << " created" << std::endl;
}
Pony::~Pony()
{
    std::cout << "You decide to kill it" << std::endl;
    std::cout << this->name << " destroyed" << std::endl;
}

void Pony::lookAtPony(void) {
    std::cout << "This pony name is " << this->name << ", it is a breed of " << this->breed << " and has this magnificent " << this->suit << " suit" << std::endl;
    return ;
}

void Pony::feedPony(void) {
    std::cout << "You gave pony a some food..." << std::endl;
    std::cout << this->name << " devours " << food << std::endl;
    return ;
}
