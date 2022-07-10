//
// Created by iorda on 7/1/2022.
//

#include "cover.h"

Cover::Cover(const std::string &nume_, const double durata_, const int radio_plays_, const int critic_rating_,
             const Trupa& trupa_originala_) : Piesa(nume_, durata_, radio_plays_, critic_rating_),
                                                                                     trupa_originala(trupa_originala_.clone()) {}
Cover::Cover(const Cover &other) : Piesa(other), trupa_originala(other.trupa_originala->clone()) {}

void swap(Cover &c1, Cover &c2) {
    using std::swap;
    swap(c1.trupa_originala, c2.trupa_originala);
    swap(c1.nume, c2.nume);
    swap(c1.durata, c2.durata);
}

Cover &Cover::operator=(const Cover &other) {
    auto temp{other};
    swap(*this, temp);
    return *this;
}

int Cover::CalcRating() const {
    return std::min(100, (45 * critic_rating + 55 * radio_plays / 1000) / 100 - 15); //depunctare 15% pentru neoriginalitate
}

void Cover::AfisarePiesa(std::ostream &os) const {
    os << "Numele trupei originale: " << trupa_originala->GetNume() << "\n";
    Piesa::AfisarePiesa(os);
}

/*const std::shared_ptr<Trupa>& Cover::getTrupaOriginala() const {
    return trupa_originala;
}*/

std::shared_ptr<Piesa> Cover::clone() const {
    return std::make_shared<Cover>(*this);
}






