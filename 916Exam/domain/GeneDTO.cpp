//
// Created by peacegabi on 06.04.2021.
//

#include "GeneDTO.h"

GeneDTO::GeneDTO(const Gene &g, int l,int m, int r):_g{g},length_left{l},length_right{r},length_middle{m} {

}

std::ostream &operator<<(std::ostream &os, const GeneDTO &gdto) {
    os<<gdto._g.get_organism();
    for (int i=0;i<gdto.length_left;i++){
        os<<" ";
    }
    os<<"|"<<gdto._g.get_name();
    for (int i=0;i<gdto.length_middle;i++){
        os<<" ";
    }
    os<<"|";
    for (int i=0;i<gdto.length_right;i++){
        os<<" ";
    }
    os<<gdto._g.get_sequence();

    return os;
}

const Gene &GeneDTO::get_gene() const {
    return this->_g;
}
