//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_GENEDTO_H
#define INC_916EXAM_GENEDTO_H


#include "Gene.h"
#include <iostream>

class GeneDTO {
private:
   Gene _g;
   int length_left;
   int length_right;
   int length_middle;
public:
    GeneDTO(const Gene&,int,int,int);
    const Gene& get_gene() const;
    friend std::ostream&operator<<(std::ostream&,const GeneDTO&);
};


#endif //INC_916EXAM_GENEDTO_H
