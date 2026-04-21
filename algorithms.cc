#include "algorithms.h"
#include <limits>
#include <algorithm> // For std::min_element, std::max_element
#include <vector>    // For std::vector

/**
 * SELECTION SORT
 * Logic: Find the smallest, move it to the new list, repeat.
 */
std::vector<int> SelectionSort(std::vector<int> A) {
    std::vector<int> B;

    while (!A.empty()) {
        auto it = std::min_element(A.begin(), A.end());
        int x = *it;

        B.push_back(x);
        A.erase(it);
    }
    return B;
}

/**
 * MERGE (Helper for MergeSort)
 * Logic: Combine two already-sorted lists into one.
 */
std::vector<int> Merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> result;

    size_t i = 0;
    size_t j = 0;

    while(i < left.size() && j< right.size()){
        if (left[i]<= right[j]){
            result.push_back(left[i]);
            i++;
        }else {
            result.push_back(right[j]);
            j++;
        };
    };

    while(i<left.size()){
        result.push_back(left[i]);
        i++;
    };

    while(j<right.size()){
        result.push_back(right[j]);
        j++;
    };
 

    return result;
}

/**
 * MERGE SORT
 * Logic: Split in half, recurse, then merge.
 */
std::vector<int> MergeSort(std::vector<int> A) {
    // Base Case: A list of 1 (or 0) is already sorted
    if (A.size() <= 1) return A;

    int mid = A.size()/2;

    std::vector<int> left_half(A.begin(), A.begin() + mid);
    std::vector<int> right_half(A.begin()+mid, A.end());

    return Merge(MergeSort(left_half), MergeSort(right_half));

}

/**
 * COUNTING SORT
 * Logic: Count how many times each number appears.
 */
std::vector<int> CountingSort(std::vector<int> A) {
    std::vector<int> B;
    if (A.empty()) return B;

    int minVal = *std::min_element(A.begin(),A.end());
    int maxVal = *std::max_element(A.begin(),A.end());

    std:: vector<int>T(maxVal-minVal+1,0);

    for(int a: A){
        T[a-minVal]++;
    };

    for(int i = minVal; i<= maxVal; i++){
        for(int j=0;j< T[i-minVal]; j++){
            B.push_back(i);
        };

    };

    
    return B; 
}