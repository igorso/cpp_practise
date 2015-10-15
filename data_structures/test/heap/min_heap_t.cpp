#include <iostream>
#include <vector>
#include "../../src/heap/min_heap.h"

template <class T> void print_vector (std::vector<T> *v) {
    for (auto it = v->cbegin(); it != v->cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool test_insert () {
    std::vector<int> elems_heap = {4, 7, 5, 8, 14, 13};
    min_heap<int> heap1 (elems_heap);
    heap1.insert (3);
    std::vector<int> returned = heap1.get_elements ();

    std::vector<int> correct1 = {3, 7, 4, 8, 14, 13, 5};

    for (int i = 0; i < 7; ++i) {
        if (correct1[i] != returned[i]) {
            return false;

        }
    }
    return true;
}

bool test_extract () {
    std::vector<int> elems_heap = {3, 6, 8, 10, 11, 13, 10, 17, 20};
    min_heap<int> heap1 (elems_heap);

    std::vector<int> correct = {3, 6, 8, 10, 10, 11, 13, 17, 20};
    std::vector<int> returned (0);

    for (int i = 0; i < 9; ++i) {
        returned.push_back (heap1.extract ());
    }

    for (int i = 0; i < 9; ++i) {
        if (correct[i] != returned[i]) {
            return false;
        }
    }
    return true;
}

bool test_pop_out_at () {
    std::vector<int> elems_heap = {3, 6, 8, 10, 11, 13, 10, 17, 20};
    min_heap<int> heap1 (elems_heap);

    std::vector<int> correct1 = {3, 6, 10, 10, 11, 13, 20, 17};
    heap1.pop_out_at (2);
    std::vector<int> returned = heap1.get_elements ();

    for (int i = 0; i < 8; ++i) {
        if (correct1[i] != returned[i]) {
            return false;
        }
    }
    return true;
}

int main () {
    
    std::string t1 = (test_extract() == 1) ? "Extract: passed" : "Extract: error";
    std::string t2 = (test_insert() == 1) ? "Insert: passed" : "Insert: error";
    std::string t3 = (test_pop_out_at() == 1) ? "Pop_out_at: passed" : "Pop_out_at: error";

    std::cout << "\nmin_heap tests\n\n";
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;

    return 0;
}