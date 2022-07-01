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

void Piesa::AfisarePiesa(std::ostream &os) const {
    os << "Numele piesei: " << nume << ", Durata piesei: ";
    os << (int)durata << " minute si " << (int) 100 * (durata - (int)durata) << " secunde\n";
}

std::ostream &operator<<(std::ostream &os, const Piesa &p) {
    p.AfisarePiesa(os);
    return os;
}

[[maybe_unused]] std::shared_ptr<Piesa> Piesa::clone() const{
    return std::make_shared<Piesa>(*this);
}

const std::string &Piesa::GetNume() const {
    return nume;
}

double Piesa::GetDurata() const {
    return durata;
}