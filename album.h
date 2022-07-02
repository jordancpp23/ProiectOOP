//
// Created by iorda on 6/28/2022.
//

#ifndef OOP_ALBUM_H
#define OOP_ALBUM_H
#include <string>
#include <memory>
#include "piesa.h"
#include <vector>

class Album{

    std::vector <std::shared_ptr<Piesa>> tracks;
    std::string nume;
    double durata;
    int an_aparitie;
public:
    explicit Album(std::vector<std::shared_ptr<Piesa>>& tracks_, const std::string &nume_ = "Nameless album", const double durata_ = 0,
                   const int an_aparitie_ = 0);

    Album (const Album& other);

    friend void swap(Album& a1, Album& a2);

    Album& operator = (const Album& other);

    double AdunaDurate(double x, double y);

    double ScadeDurate(double x, double y);

    int getAnAparitie() const;

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
