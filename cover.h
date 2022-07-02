//
// Created by iorda on 7/1/2022.
//

#ifndef OOP_COVER_H
#define OOP_COVER_H
#include "piesa.h"
#include "trupa.h"
#include <memory>

class Cover : public Piesa{
    std::shared_ptr<Trupa> trupa_originala;
public:
    Cover(const std::string &nume_, const double durata_, const int radio_plays_, const int critic_rating_, std::shared_ptr<Trupa>& trupa_originala_);

    Cover (const Cover& other);

    friend void swap(Cover& c1, Cover& c2);

    Cover& operator = (const Cover& other);

    int CalcRating() const override;

    void AfisarePiesa(std::ostream &os) const override;

    //[[maybe_unused]] const std::shared_ptr<Trupa>& getTrupaOriginala() const;

    [[nodiscard]] std::shared_ptr<Piesa> clone() const override;

    ~Cover() override = default;
};


#endif //OOP_COVER_H
