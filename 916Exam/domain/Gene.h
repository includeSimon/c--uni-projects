//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_GENE_H
#define INC_916EXAM_GENE_H


#include <string>

class Gene {
private:
    std::string _organism;
    std::string _name;
    std::string _sequence;

public:
    Gene();
    Gene(const std::string&,const std::string&,const std::string&);
    const std::string& get_organism() const;
    const std::string& get_name() const;
    const std::string& get_sequence() const;
    bool operator==(const Gene&) const;
    bool operator<(const Gene&) const;


};


#endif //INC_916EXAM_GENE_H
