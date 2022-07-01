//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_TRUPA_H
#define OOP_TRUPA_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "album.h"
#include "artist.h"
#include "concert.h"

class Trupa {
    std::string nume;
    std::string genre;
    int an_infiintare;
    std::set <Album> discografie;
    std::set <Concert> concerte;
    std::vector <Artist> membri;
public:
    Trupa(const std::string &nume_ = "Placeholder", const std::string &genre_ = "Pop", const int an = 0, const std::set<Album> &discografie_ = {},
          const std::set<Concert> &concerte_ = {}, const std::vector<Artist> &membri_ = {});

    const std::string& GetNume() const;

    void SetNume(const std::string &nume_) {
        nume = nume_;
    }

    void AdaugaAlbum(const Album &album);

    [[nodiscard]] bool CautaPiesa(const Piesa &p) const;

    void ProgrameazaConcert(const Concert &concert);

    void AdaugaMembru(const Artist &artist);

    void StergeMembru(const Artist &artist);

    void AfisAlbume(std::ostream &os) const;

    void AfisMembri (std::ostream &os) const;

    [[nodiscard]] bool IsSimilar(const Trupa &other) const;

    void CheckSimilarity(const Trupa &other) const;

    void AfisConcerte (std::ostream &os) const;

    void AfisDetalii (std::ostream &os) const;

    friend std::ostream& operator<< (std::ostream &os, const Trupa& band);

    ~Trupa() = default;
};


#endif //OOP_TRUPA_H
