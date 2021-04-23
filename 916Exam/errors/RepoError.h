//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_REPOERROR_H
#define INC_916EXAM_REPOERROR_H


#include <exception>
#include <string>

class RepoError: public std::exception {
private:
    std::string _msg;
public:
    RepoError(const std::string&);
    const std::string& get_msg() const;
};



#endif //INC_916EXAM_REPOERROR_H
