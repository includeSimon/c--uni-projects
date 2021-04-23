//
// Created by peacegabi on 06.04.2021.
//

#include "RepoError.h"

RepoError::RepoError(const std::string &msg) :_msg{msg}, std::exception(){

}

const std::string &RepoError::get_msg() const {
    return this->_msg;
}
