/*  Igor Soares de Oliveira
Reference for Templates http://www.cprogramming.com/tutorial/templates.html  */
#ifndef heap_H
#define heap_H

#include <vector>
#include <cmath>

template <class T>
class heap {
    public:
        heap ();
        heap (std::vector<T> elems);
        T extract ();
        T value ();
        int size ();
        T pop_out_at (int id);
        std::vector<T> get_elements ();
        void insert (T elem);

    protected:
        T pop_out (int id);
        int parent_id (int sonid);
        int lson_id (int pid);
        int rson_id (int pid);
        std::vector<T> m_elements;
        virtual bool compare_a_b (int a, int b) = 0;
        virtual int get_one_of_two_sons (int lson, int rson) = 0;
};

template <class T>
heap<T>::heap () {
    m_elements = std::vector<T>(0);
}

template <class T>
heap<T>::heap (std::vector<T> elems) {
    m_elements = std::vector<T>(elems);
}

//  This does not work with id=0        
template <class T>
int heap<T>::parent_id (int sonid) {
    if (sonid%2 == 0) {
        return ((int) std::floor((float)(sonid+1)/2)) - 1;
    }
    else {
        return (sonid+1)/2 - 1;
    }
}

template <class T>
int heap<T>::lson_id (int pid) {
    return 2*(pid+1) - 1;
}

template <class T>
int heap<T>::rson_id (int pid) {
    return 2*(pid+1);
}

template <class T>
std::vector<T> heap<T>::get_elements () {
    return m_elements;
}

template <class T>
int heap<T>::size () {
    return m_elements.size ();
}

template <class T>
T heap<T>::value () {
    if (m_elements.size () > 0)
        return m_elements.at (0);
    else
        return T();
}

template <class T>
void heap<T>::insert (T elem) {
    m_elements.push_back (elem);
    int id = m_elements.size () -1;
    int pid = parent_id (id);

    //  id cannont be 0
    while (id > 0) {
        if (compare_a_b (id, pid)) {
            T aux = m_elements.at(pid);
            m_elements.at(pid) = m_elements.at(id);
            m_elements.at(id) = aux;
            id = pid;
            pid = parent_id (id);
        }
        else {
            break;
        }
    }
}

template <class T>
T heap<T>::extract () {
    return pop_out (0);
}

template <class T>
T heap<T>::pop_out_at (int id) {
    return pop_out (id);
}

template <class T>
T heap<T>::pop_out (int id) {
    if (m_elements.size() < 1) {
        return T();
    }

    if (id >= m_elements.size ()) {
        return T();
    }

    if (m_elements.size() == 1) {
        T extracted = m_elements.at (id);
        m_elements.pop_back ();  // Now m_elements is empty
        return extracted;
    }

    T extracted = m_elements.at (id);
    T last = m_elements.back ();
    
    m_elements.pop_back ();
    m_elements.at (id) = last;

    int lson = lson_id (id);
    int rson = rson_id (id);

    while ((lson < m_elements.size()) && (rson < m_elements.size())) {
        int son = get_one_of_two_sons (lson, rson);

        //  If the parent (id) is smaller son, stop
        if (compare_a_b (id, son)) {
            break;
        }

        T aux = m_elements.at(son);
        m_elements.at(son) = m_elements.at(id);
        m_elements.at(id) = aux;
        id = son;
        lson = lson_id (id);
        rson = rson_id (id);
    }

    //  If we are at an incomplete level
    if ((lson < m_elements.size()) && (compare_a_b (lson, id))) {
        T aux = m_elements.at(lson);
        m_elements.at(lson) = m_elements.at(id);
        m_elements.at(id) = aux;
    }
    return extracted;
}

#endif