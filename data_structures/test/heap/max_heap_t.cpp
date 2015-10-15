#include <iostream>
#include <vector>
#include "../../src/heap/max_heap.h"

bool test_insert () {
    std::vector<int> elems_heap = {53, 49, 37, 15, 35, 34, 29, 9, 3, 27, 15, 9};
    max_heap<int> heap1 (elems_heap);
    heap1.insert (42);
    std::vector<int> returned = heap1.get_elements ();

    std::vector<int> correct1 = {53, 49, 42, 15, 35, 37, 29, 9, 3, 27, 15, 9, 34};

    for (int i = 0; i < 13; ++i) {
        if (correct1[i] != returned[i]) {
            return false;

        }
    }
    return true;
}

bool test_extract () {
    std::vector<int> elems_heap = {53, 49, 37, 15, 35, 34, 29, 9, 3, 27, 15, 9};
    max_heap<int> heap1 (elems_heap);

    std::vector<int> correct = {53, 49, 37, 35, 34, 29, 27, 15, 15, 9, 9, 3};
    std::vector<int> returned (0);

    for (int i = 0; i < 12; ++i) {
        returned.push_back (heap1.extract ());
    }

    for (int i = 0; i < 13; ++i) {
        if (correct[i] != returned[i]) {
            return false;
        }
    }
    return true;
}

bool test_pop_out_at () {
    std::vector<int> elems_heap = {53, 49, 37, 15, 35, 34, 29, 9, 3, 27, 15, 9};
    max_heap<int> heap1 (elems_heap);

    std::vector<int> correct1 = {53, 35, 37, 15, 27, 34, 29, 9, 3, 9, 15};
    heap1.pop_out_at (1);
    std::vector<int> returned = heap1.get_elements ();

    for (int i = 0; i < 11; ++i) {
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

    std::cout << "\nmax_heap tests\n\n";
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;

    return 0;
}
