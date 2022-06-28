//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_PIESA_H
#define OOP_PIESA_H
#include <string>
#include <iostream>

class Piesa{
    std::string nume;
    double durata;
public:
    Piesa(const std::string &nume_ = "Nameless song", double durata_ = 0);

    friend std::istream& operator >> (std::istream &is, Piesa &p);

    friend std::ostream& operator << (std::ostream &os, const Piesa& p);

    const std::string& GetNume() const;

    double GetDurata() const;

    ~Piesa() = default;
};


#endif //OOP_PIESA_H
