//
// Created by iorda on 6/30/2022.
//

#ifndef OOP_SINGLE_H
#define OOP_SINGLE_H
#include "piesa.h"
#include "data.h"

class Single : public Piesa {
    int vizualizari;
    Data data_lansare;
public:
    Single(const std::string &nume_ = "Nameless song", const double durata_ = 0, const int vizualizari_ = 0,
           const Data& data_lansare_ = Data(30, 02, 1900));

    void AfisarePiesa(std::ostream &os) const override;

    [[maybe_unused]]int GetVizualizari() const;

    const Data& GetDataLansare() const;


    friend std::ostream& operator << (std::ostream &os, const Single &single);

    [[nodiscard]] std::shared_ptr<Piesa> clone() const override;

    ~Single() override = default;
};


#endif //OOP_SINGLE_H
