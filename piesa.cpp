//
// Created by iorda on 6/28/2022.
//

#include "piesa.h"

Piesa::Piesa(const std::string &nume_, double durata_) : nume(nume_), durata(durata_) {}

std::istream &operator>>(std::istream &is, Piesa &p) {
    getline(is, p.nume);
    is >> p.durata;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Piesa &p) {
    os << "Numele piesei: " << p.nume << ", Durata piesei: ";
    os << (int)p.durata << " minute si " << (int) 100 * (p.durata - (int)p.durata) << " secunde\n";
    return os;
}

const std::string &Piesa::GetNume() const {
    return nume;
}

double Piesa::GetDurata() const {
    return durata;
}