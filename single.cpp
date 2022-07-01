//
// Created by iorda on 6/30/2022.
//

#include "single.h"

Single::Single(const std::string &nume_, const double durata_, const int vizualizari_, const Data& data_lansare_) : Piesa(nume_, durata_),
    vizualizari(vizualizari_),data_lansare(data_lansare_) {};

void Single::AfisarePiesa(std::ostream &os) const {
    Piesa::AfisarePiesa(os);
    os << "Numarul de vizualizari al single-ului: " << vizualizari << "\n";
    os << "Data lansarii single-ului: " << data_lansare;
}

int Single::GetVizualizari() const {
    return vizualizari;
}

std::ostream &operator<<(std::ostream &os, const Single &single) {
    single.AfisarePiesa(os);
    return os;
}

std::shared_ptr<Piesa> Single::clone() const {
    return std::make_shared<Single>(*this);
}




