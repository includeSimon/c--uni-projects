//
// Created by peacegabi on 06.04.2021.
//

#include "Gene.h"
#include "../errors/GeneError.h"
#include <algorithm>
Gene::Gene():_organism{""},_name{""},_sequence{""} {

}

Gene::Gene(const std::string & organism, const std::string &name, const std::string &sequence):_organism{organism},_name{name},_sequence{sequence} {
 auto it = std::find_if(sequence.begin(),sequence.end(),[](const auto& x){return x!='A' && x!='C'&& x!='T'&& x!='G';});
 if(it != sequence.end())
     throw GeneError{"invalid sequence!"};
}

const std::string &Gene::get_organism() const {
    return this->_organism;
}

const std::string &Gene::get_name() const {
    return this->_name;
}

const std::string &Gene::get_sequence() const {
    return this->_sequence;
}

bool Gene::operator==(const Gene &g) const {
    return this->_name == g._name && this->_organism == g._organism;
}

bool Gene::operator<(const Gene &g) const {
    return this->_sequence.size()>g._sequence.size();
}
