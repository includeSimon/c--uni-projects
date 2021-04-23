//
// Created by peacegabi on 06.04.2021.
//

#include <iostream>
#include <cassert>
#include "Tests.h"
#include "../errors/GeneError.h"
#include "../persistence/Repo.h"
#include "../domain/Gene.h"
#include "../errors/RepoError.h"
#include "../business/GeneService.h"

void Tests::run_domain_tests() {
    std::cout<<"start domain tests...\n";
    Gene g{"E_Coli_K12", "yqgE", "ATGACATCATCATTG"};
    Gene gg{"E_Coli_K12", "yqgE", "ACATCATCATTG"};

    assert(g==gg);
    assert(g<gg);
    try{
        Gene bad{"E_Coli_K12", "yqgE", "ACATCATCATTZ"};
        assert(false);
    }catch(const GeneError& ge){
        assert(ge.get_msg()=="invalid sequence!");
    }
    std::cout<<"finish domain tests...\n";

}

void Tests::run_all_tests() {
    std::cout<<"start all tests...\n";
    this->run_domain_tests();
    this->run_repo_tests();
    this->run_service_tests();
    std::cout<<"finish all tests...\n";

}

void Tests::run_repo_tests() {
    std::cout<<"start repo tests...\n";
    Repo<Gene> repo;
    assert(repo.size()==0);
    Gene g{"E_Coli_K12", "yqgE", "ACATCATCATT"};
    repo.add(g);
    assert(repo.size()==1);
    try{
        repo.add(g);
    }catch(const RepoError& re){
        assert(re.get_msg()=="existing elem!");
    }
    std::cout<<"stop repo tests...\n";
}

void Tests::run_service_tests() {
    std::cout<<"start service tests...\n";
    Repo<Gene> repo;
    GeneService srv{repo};
    assert(srv.size()==0);
    srv.add_gene("E_Coli_K12", "yqgE", "ACATCATCATT");
    assert(srv.size()==1);
    try{
        srv.add_gene("E_Coli_K12", "yqgE", "ACATCATCATT");
    }catch(const RepoError& re) {
        assert(re.get_msg() == "existing elem!");
    }
    try{
        srv.add_gene("E_Coli_K12", "yqgE", "ACATCATCATTZ");
    }catch(const GeneError& ge){
        assert(ge.get_msg()=="invalid sequence!");
    }
    srv.add_gene("M_tuberculosis", "ppiA", "TCTTCATCATCATCGG");
    srv.add_gene("Mouse", "Col2a1", "TTAAAGCATGGCTCTGTG");
    srv.add_gene("E_Coli_ETEC", "yqgE", "GTGACAGCGCCCTTCTTTCCACG");
    srv.add_gene("E_Coli__K12", "yqgE", "ATG");
    srv.add_gene("E_Coli_K1", "yqgE", "ACATCATT");
    srv.add_gene("E_Coli_K", "yqgE", "ACATCATT");
    std::vector<GeneDTO> all_sorted = srv.get_all_sorted();
    assert(all_sorted.size()==7);
    assert(all_sorted[0].get_gene().get_organism()=="E_Coli_ETEC");
    std::vector<GeneDTO> filtered_sorted = srv.get_all_containing("CATC");
    std::string rez = srv.longest_common_subseq("M_tuberculosis", "ppiA","E_Coli_K12", "yqgE");
    assert(rez=="CATCATCAT");
    assert(filtered_sorted.size()==4);



std::cout<<"stop service tests...\n";
}
