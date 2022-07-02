//
// Created by iorda on 6/30/2022.
//

#include "single.h"

Single::Single(const std::string &nume_, const double durata_, const int radio_plays_,
               const int critic_rating_, const int vizualizari_, const Data& data_lansare_) : Piesa(nume_, durata_, radio_plays_, critic_rating_),
                                vizualizari(vizualizari_),data_lansare(data_lansare_) {}

void Single::AfisarePiesa(std::ostream &os) const {
    Piesa::AfisarePiesa(os);
    os << "Numarul de vizualizari al single-ului: " << vizualizari << "\n";
    os << "Data lansarii single-ului: " << data_lansare;
}

/*int Single::GetVizualizari() const {
    return vizualizari;
}*/

int Single::CalcRating() const {
    return std::min(100, (vizualizari/10000 + 25 * critic_rating + 55 * radio_plays)/2);
}

const Data &Single::GetDataLansare() const {
    return data_lansare;
}

std::ostream &operator<<(std::ostream &os, const Single &single) {
    single.AfisarePiesa(os);
    return os;
}

std::shared_ptr<Piesa> Single::clone() const {
    return std::make_shared<Single>(*this);
}





