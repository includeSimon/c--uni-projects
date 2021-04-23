//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_CONSOLE_H
#define INC_916EXAM_CONSOLE_H


#include "../business/GeneService.h"

class Console {
private:
    GeneService& _srv;
    void ui_add_gene();
    void ui_print_all();
    void ui_filter_genes();
    void ui_longest();
public:
    Console(GeneService&);


    void run();
};


#endif //INC_916EXAM_CONSOLE_H
