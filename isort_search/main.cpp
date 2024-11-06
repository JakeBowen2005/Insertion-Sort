//
//  main.cpp
//  isort_search
//
//  Created by Jake Bowen on 10/19/24.
//

#include <iostream>
#include <stdlib.h>
#include <vector>

void Insertion_sort(std::vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++) {
        int key = nums.at(i);
        int j = i - 1;
        while(j >= 0 && nums.at(j) > key) {
            nums.at(j + 1) = nums.at(j);
            j = j - 1;
        }
        nums.at(j+1) = key;
    }
}

void Print_sorted(std::vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums.at(i) << " ";
    }
}

int B_search(std::vector<int>& nums, int value) {
    int l = 0;
    int r = nums.back();
    while(l <= r) {
        int q = (l + r) / 2;
        if (value == nums.at(q)) {
            return q;
        }
        if (nums.at(q) < value) {
            l = q + 1;
        } else {
            r = q - 1;
        }

    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    srand (time_t(NULL));
    std::vector<int> nums;
    
    std::cout << "Generate random numbers 0 - : ";
    int max_num;
    std::cin >> max_num;
    for (int i = 0; i < max_num; i++) {
        nums.push_back(rand() % max_num + 1);
    }
    std::cout << "Sorting now..." << std::endl;
    std::cout << std::endl;
    Insertion_sort(nums);
    std::cout << std::endl;
    int value;
    std::cout << "What value would you like to find in the random numbers: ";
    std::cin >> value;
    
    if(B_search(nums, value) > -1) {
        std::cout << "Number found at postion " << B_search(nums, value) << std::endl;
    } else {
        std::cout << "Number not found sorry!!" << std::endl;
    }
    


    return 0;
}
