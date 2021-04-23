//
// Created by peacegabi on 06.04.2021.
//

#include "GeneService.h"
#include <algorithm>

GeneService::GeneService(Repo<Gene> &repo):_repo{repo} {

}

int GeneService::size() const {
    return this->_repo.size();
}

void GeneService::add_gene(const std::string &organism, const std::string &name, const std::string &sequence) {
    Gene g{organism,name,sequence};
    this->_repo.add(g);

}

std::vector<GeneDTO> GeneService::get_all_sorted() const {
    std::vector<Gene> all = this->_repo.get_elems();
    std::sort(all.begin(),all.end());

    return  this->turn_to_dtos(all);
}

std::vector<GeneDTO> GeneService::get_all_containing(const std::string& str) const {
    std::vector<Gene> filtered;
    std::copy_if(this->_repo.get_elems().begin(),this->_repo.get_elems().end(),std::back_inserter(filtered),[&str](const auto& x){return x.get_sequence().find(str) != std::string::npos;});
    return this->turn_to_dtos(filtered);
}

std::string GeneService::longest_common_subseq(const std::string&organism0,const std::string&name0,const std::string&organism1,const std::string&name1) const {
    Gene key0{organism0,name0,""};
    Gene key1{organism1,name1,""};
    Gene gene0 = this->_repo.search(key0);
    Gene gene1 = this->_repo.search(key1);
    int start_pos_i=-1;
    int start_pos_j=-1;
    int pos_i;
    int pos_j;
    int max_start_pos_i=-1;
    int max_pos_i=-1;

    int max_len=-1;
    int i_size = gene0.get_sequence().size();
    int j_size = gene1.get_sequence().size();
    for (int i=0;i<i_size;i++){
        for (int j=0;j<j_size;j++){
            start_pos_i = i;
            start_pos_j = j;
            pos_i = i;
            pos_j = j;
            while(pos_i<i_size&&pos_j<j_size&&gene0.get_sequence()[pos_i]==gene1.get_sequence()[pos_j]){
                pos_i++;
                pos_j++;
            }
            if(pos_i-start_pos_i>max_len){
                max_start_pos_i = start_pos_i;
                max_pos_i = pos_i;
                max_len = max_pos_i-max_start_pos_i;
            }

        }
    }
    return gene0.get_sequence().substr(max_start_pos_i,max_len);
}

std::vector<GeneDTO> GeneService::turn_to_dtos(const std::vector<Gene> &all) const {
    int max_left=-1;
    int max_middle=-1;
    int max_right=-1;
    int l;
    int m;
    int r;
    std::for_each(all.begin(),all.end(),[&l,&m,&r,&max_left,&max_middle,&max_right](const auto& x){
        l = x.get_organism().size();
        m = x.get_name().size();
        r = x.get_sequence().size();
        if (l>max_left){
            max_left = l;
        }
        if (m>max_middle){
            max_middle = m;
        }
        if (r>max_right){
            max_right = r;
        }
    });
    std::vector<GeneDTO> rez;
    std::for_each(all.begin(),all.end(),[&max_left,&max_middle,&max_right,&rez](const auto& x){
        GeneDTO g_dto{x,max_left-x.get_organism().size(),max_middle-x.get_name().size(),max_right- x.get_sequence().size()};
        rez.push_back(g_dto);
    });
    return rez;
}
