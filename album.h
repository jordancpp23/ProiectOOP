//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_ALBUM_H
#define OOP_ALBUM_H
#include <string>
#include "piesa.h"
#include <vector>

class Album{
    std::string nume;
    double durata;
    std::vector <Piesa> tracks;
    int an_aparitie;
public:
    explicit Album(const std::string &nume_ = "Untitled Unmastered", const std::vector<Piesa> &tracks_ = {}, double durata_ = 0, int an = 0);

    double AdunaDurate(double x, double y);

    double ScadeDurate(double x, double y);

    bool VerificaPiesa(const Piesa &p) const;

    void AdaugaPiesa(const Piesa &p);

    void ScoatePiesa(const Piesa &p);

    const std::string& GetNume() const;

    //double GetDurata() const;

    friend std::ostream &operator<<(std::ostream &os, const Album &album);

    bool operator<(const Album &other) const;

    ~Album() = default;
};


#endif //OOP_ALBUM_H
