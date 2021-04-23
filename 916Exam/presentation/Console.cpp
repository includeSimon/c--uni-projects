//
// Created by peacegabi on 06.04.2021.
//

#include <string>
#include <iostream>
#include "Console.h"
#include "../errors/GeneError.h"

Console::Console(GeneService &srv):_srv{srv} {

}

void Console::run() {
    std::string command;
    while(true){
        std::cout<<">>>";
        std::cin>>command;
        if (command == "exit")
            return ;
        try{
            if (command=="add_gene"){
                this->ui_add_gene();
            }else if (command == "pretty_print"){
                this->ui_print_all();
            }else if (command == "filter"){
                this->ui_filter_genes();
            }else if (command == "longest"){
                this->ui_longest();
            }
            else{
                std::cout<<"invalid command!\n";
            }
        }catch (const GeneError& ge){
            std::cout<<ge.get_msg()<<"\n";
        }catch (const RepoError& re){
            std::cout<<re.get_msg()<<"\n";
        }

    }
}

void Console::ui_add_gene() {
    std::string organism;
    std::string name;
    std::string sequence;
    std::cin>>organism>>name>>sequence;
    this->_srv.add_gene(organism,name,sequence);
    std::cout<<"successfully added!\n";

}

void Console::ui_print_all() {
    std::vector<GeneDTO> all = this->_srv.get_all_sorted();
    std::for_each(all.begin(),all.end(),[](const auto& x){ std::cout<<x<<"\n";});
}

void Console::ui_filter_genes() {
    std::string str;
    std::cin>>str;
    std::vector<GeneDTO> all = this->_srv.get_all_containing(str);
    std::for_each(all.begin(),all.end(),[](const auto& x){ std::cout<<x<<"\n";});
}

void Console::ui_longest() {
    std::string organism0;
    std::string name0;
    std::string organism1;
    std::string name1;
    std::cin>>organism0>>name0>>organism1>>name1;
    std::string rez = this->_srv.longest_common_subseq(organism0,name0,organism1,name1);
    std::cout<<"The longest common subseq is: "<<rez<<"\n";
}
