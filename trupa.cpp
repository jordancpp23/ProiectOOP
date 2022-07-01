//
// Created by iorda on 6/28/2022.
//

#include "trupa.h"

Trupa::Trupa(const std::string &nume_, const std::string &genre_, const int an, const std::set<Album> &discografie_,
             const std::set<Concert> &concerte_, const std::vector<Artist> &membri_) : nume(nume_), genre(genre_),
                                                                                       an_infiintare(an), discografie(discografie_), concerte(concerte_), membri(membri_) {}
const std::string &Trupa::GetNume() const {
    return nume;
}

void Trupa::AdaugaAlbum(const Album &album) {
    if(discografie.find(album) != discografie.end())
        std::cout << "Albumul " << album.GetNume() << " se afla deja in discografie!\n";
    else
        discografie.insert(album);
}

bool Trupa::CautaPiesa(const Piesa &p) const {
    for (auto &a : discografie)
        if (a.VerificaPiesa(p))
            return true;
    return false;
}

void Trupa::ProgrameazaConcert(const Concert &concert) {
    for (auto &c : concerte)
        if (c.GetNume() == concert.GetNume() && c.GetData() == concert.GetData()) {
            std::cout << "Concertul " << concert.GetNume() << "la data de " << c.GetData() << " este deja programat!\n";
            return;
        }
        else if (c.GetData() == concert.GetData())
        {
            std::cout << "Trupa are un alt concert programat pe aceeasi data!\n";
            return;
        }
    concerte.insert(concert);
}

void Trupa::AdaugaMembru(const Artist &artist) {
    for (auto &a : membri)
        if (a.GetNume() == artist.GetNume()) {
            std::cout << "Artistul " << artist.GetNume() << " se afla deja in trupa!\n";
            return;
        }
    membri.push_back(artist);
}

void Trupa::StergeMembru(const Artist &artist) {
    unsigned pos = 2'000'000'000;
    for (unsigned i = 0; i < membri.size(); i++)
        if (membri[i].GetNume() == artist.GetNume())
            pos = i;
    if (pos == 2e9)
    {
        std::cout << "Artistul " << artist.GetNume() << " nu face parte din trupa!\n";
        return;
    }
    membri.erase(membri.begin() + pos);
}

void Trupa::AfisAlbume(std::ostream &os) const {
    os << "Numarul albumelor: " << discografie.size() << "\n";
    os << "Lista albumelor, in ordine cronologica:\n";
    int cnt = 1;
    for (auto &it : discografie)
        os << cnt << ". " << it, ++cnt;
}

void Trupa::AfisMembri(std::ostream &os) const {
    os << "Membrii trupei sunt: \n";
    for (auto &mem : membri)
        os << mem;
}

bool Trupa::IsSimilar(const Trupa &other) const {
    //2 trupe sunt similare daca au acelasi genre, cel putin un membru comun sau daca participa ambele la un concert
    if (genre == other.genre)
        return true;
    for (auto &mem : membri)
        for (auto &other_mem : other.membri)
            if (mem.GetNume() == other_mem.GetNume())
                return true;
    for (auto &c : concerte)
        if (other.concerte.find(c) != other.concerte.end())
            return true;
    return false;
}

void Trupa::CheckSimilarity(const Trupa &other) const {
    if (IsSimilar(other))
        std::cout << "Trupa " << nume << " este similara cu trupa " << other.nume << "\n";
    else
        std::cout << "Trupa " << nume << " nu este similara cu trupa " << other.nume << "\n";
}

void Trupa::AfisConcerte(std::ostream &os) const {
    os << "Concertele programate ale trupei " << nume << " sunt: \n";
    for (auto &conc : concerte)
        os << conc << "\n";
}

void Trupa::AfisDetalii(std::ostream &os) const {
    os << "Numele trupei: " << nume << ", Anul infiintarii: " << an_infiintare << ", Genul muzical: "
       << genre << "\n\n";
}

std::ostream &operator<<(std::ostream &os, const Trupa &band) {
    band.AfisDetalii(os);
    band.AfisMembri(os);
    os << "\n";
    band.AfisAlbume(os);
    return os;
}

