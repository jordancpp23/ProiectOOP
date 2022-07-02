//
// Created by iorda on 7/1/2022.
//

#include "cover.h"

Cover::Cover(const std::string &nume_, const double durata_, std::shared_ptr<Trupa>& trupa_originala_) : Piesa(nume_, durata_),
                                                                                     trupa_originala(std::move(trupa_originala_)) {}

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



