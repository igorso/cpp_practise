/*  Igor Soares de Oliveira
Reference for Templates http://www.cprogramming.com/tutorial/templates.html  */

#include <vector>
#include "heap.h"
    
template <class T>
class min_heap : public heap<T> {
    public:
        min_heap () : heap<T> () {}
        min_heap (std::vector<T> elems) : heap<T> (elems) {}

    protected:
        int get_one_of_two_sons (int lson, int rson);
        bool compare_a_b (int a, int b);

};

template <class T>
int min_heap<T>::get_one_of_two_sons (int lson, int rson) {
    if (this->m_elements.at(lson) >= this->m_elements.at(rson)) {
        return rson;
    }
    else {
        return lson;
    }
}

template <class T>
bool min_heap<T>::compare_a_b (int a, int b) {
    return this->m_elements.at(a) < this->m_elements.at(b);
}
