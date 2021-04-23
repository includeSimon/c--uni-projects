//
// Created by peacegabi on 06.04.2021.
//

#ifndef INC_916EXAM_REPO_H
#define INC_916EXAM_REPO_H
#include <vector>
#include <algorithm>
#include "../errors/RepoError.h"

template <class TElem>
class Repo {
private:
    std::vector<TElem> elems;
public:
    Repo();
    void add(const TElem&);
    const std::vector<TElem>& get_elems() const;
    const TElem& search(const TElem&) const;
    int size() const;
};

template<class TElem>
Repo<TElem>::Repo() {

}

template<class TElem>
void Repo<TElem>::add(const TElem &e) {
    auto it = std::find(this->elems.begin(),this->elems.end(),e);
    if (it != this->elems.end())
        throw RepoError{"existing elem!"};
    this->elems.push_back(e);

}

template<class TElem>
const std::vector<TElem> &Repo<TElem>::get_elems() const {
    return this->elems;
}

template<class TElem>
int Repo<TElem>::size() const {
    return this->elems.size();
}

template<class TElem>
const TElem &Repo<TElem>::search(const TElem &e) const {
    auto it = std::find(this->elems.begin(),this->elems.end(),e);
    if (it == this->elems.end())
        throw RepoError{"inexisting elem!"};
    return *it;
}


#endif //INC_916EXAM_REPO_H
