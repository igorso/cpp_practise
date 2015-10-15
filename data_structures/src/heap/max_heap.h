/*  Igor Soares de Oliveira
Reference for Templates http://www.cprogramming.com/tutorial/templates.html  */

#include <vector>
#include "heap.h"
    
template <class T>
class max_heap : public heap<T> {
    public:
        max_heap () : heap<T> () {}
        max_heap (std::vector<T> elems) : heap<T> (elems) {}

    protected:
        int get_one_of_two_sons (int lson, int rson);
        bool compare_a_b (int a, int b);

};

template <class T>
int max_heap<T>::get_one_of_two_sons (int lson, int rson) {
    if (this->m_elements.at(lson) > this->m_elements.at(rson)) {
        return lson;
    }
    else {
        return rson;
    }
}

template <class T>
bool max_heap<T>::compare_a_b (int a, int b) {
    return this->m_elements.at(a) > this->m_elements.at(b);
}

