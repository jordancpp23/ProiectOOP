//
// Created by iorda on 6/28/2022.
//

#include "piesa.h"


Piesa::Piesa(const std::string &nume_, const double durata_, const int radio_plays_, const int critic_rating_) :
    nume(nume_), durata(durata_), radio_plays(radio_plays_), critic_rating(critic_rating_) {}

std::istream &operator>>(std::istream &is, Piesa &p) {
    getline(is, p.nume);
    is >> p.durata;
    return is;
}

void Piesa::AfisarePiesa(std::ostream &os) const {
    os << "Numele piesei: " << nume << ", Durata piesei: ";
    os << (int)durata << " minute si " << (int) 100 * (durata - (int)durata) << " secunde\n";
}

int Piesa::CalcRating() const {
    return std::min(100, (critic_rating * 35 + radio_plays / 1000 * 65) / 100);
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

