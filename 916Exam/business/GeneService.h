//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_GENESERVICE_H
#define INC_916EXAM_GENESERVICE_H


#include "../domain/Gene.h"
#include "../persistence/Repo.h"
#include "../domain/GeneDTO.h"

class GeneService {
private:
    Repo<Gene>& _repo;
    std::vector<GeneDTO> turn_to_dtos(const std::vector<Gene>&) const;
public:
    GeneService(Repo<Gene>& repo);
    int size() const;
    void add_gene(const std::string&,const std::string&,const std::string&);
    std::vector<GeneDTO> get_all_sorted() const;
    std::vector<GeneDTO> get_all_containing(const std::string&) const;
    std::string longest_common_subseq(const std::string&,const std::string&,const std::string&,const std::string& ) const;

};


#endif //INC_916EXAM_GENESERVICE_H
