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
    Cover(const std::string &nume, const double durata_, std::shared_ptr<Trupa>& trupa_originala_);

    void AfisarePiesa(std::ostream &os) const override;

    //[[maybe_unused]] const std::shared_ptr<Trupa>& getTrupaOriginala() const;

    [[nodiscard]] std::shared_ptr<Piesa> clone() const override;

    ~Cover() override = default;
};


#endif //OOP_COVER_H
