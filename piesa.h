//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_PIESA_H
#define OOP_PIESA_H
#include <string>
#include <iostream>
#include <memory>

class Piesa{
protected:
    std::string nume;
    double durata;
public:
    Piesa(const std::string &nume_ = "Nameless song", const double durata_ = 0);

    virtual void AfisarePiesa(std::ostream &os) const;

    friend std::istream& operator >> (std::istream &is, Piesa &p);

    friend std::ostream& operator << (std::ostream &os, const Piesa& p);

    const std::string& GetNume() const;

    double GetDurata() const;

    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<Piesa> clone() const;
    virtual ~Piesa() = default;
};


#endif //OOP_PIESA_H
