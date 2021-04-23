//
// Created by peacegabi on 06.04.2021.
//

#include "GeneError.h"

GeneError::GeneError(const std::string & msg):_msg{msg} {

}

const std::string &GeneError::get_msg() const {
    return this->_msg;
}
