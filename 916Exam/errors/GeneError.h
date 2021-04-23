//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_GENEERROR_H
#define INC_916EXAM_GENEERROR_H
#include <exception>
#include <string>

class GeneError:public std::exception {
private:
    std::string _msg;
public:
    GeneError(const std::string&);
    const std::string& get_msg() const;
};


#endif //INC_916EXAM_GENEERROR_H
