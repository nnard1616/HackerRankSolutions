//
// Created by Nathan Nard on 12/19/18.
//

#include "gtest/gtest.h"
#include "../common/common.hpp"
#include "../Custom_Datastructures/Priority_Deque.hpp"
#include <bits/stdc++.h>

using namespace std;

namespace{

class commonTests : public testing::Test{
protected:
    virtual void SetUp(){
        ;
    }

    virtual void TearDown(){
        ;
    }

    vector<int> sortedEven{1,2,3,5,6,7,8,9};
    vector<int> sortedOdd {1,2,3,5,6,7,8};
};

class binarySearch : public commonTests{
};


    TEST_F(binarySearch, evenMissing){

        EXPECT_EQ(5, *common::binary_search_for_insertion_point(4, sortedEven));

    }

    TEST_F(binarySearch, oddMissing){

        EXPECT_EQ(5,*common::binary_search_for_insertion_point(4, sortedOdd));

    }

    TEST_F(binarySearch, oddPresent){

        EXPECT_EQ(8,*common::binary_search_for_insertion_point(8, sortedOdd));

    }

    TEST_F(binarySearch, evenPresent){

        EXPECT_EQ(8,*common::binary_search_for_insertion_point(8, sortedEven));

    }

    TEST_F(binarySearch, evenPresentLower){

        EXPECT_EQ(1,*common::binary_search_for_insertion_point(1, sortedEven));

    }

    TEST_F(binarySearch, oddPresentLower){

        EXPECT_EQ(1,*common::binary_search_for_insertion_point(1, sortedOdd));

    }

    TEST_F(binarySearch, oddMissingLower){

        EXPECT_EQ(1,*common::binary_search_for_insertion_point(0, sortedOdd));

    }

    TEST_F(binarySearch, evenMissingLower){

        EXPECT_EQ(1,*common::binary_search_for_insertion_point(0, sortedEven));

    }

    TEST_F(binarySearch, evenMissingUpper){

        EXPECT_EQ(*sortedEven.end(),*common::binary_search(10, sortedEven));

    }

    TEST_F(binarySearch, evenPresentUpper){

        EXPECT_EQ(9,*common::binary_search_for_insertion_point(9, sortedEven));

    }

    TEST_F(binarySearch, oddPresentUpper){

        sortedOdd.insert(common::binary_search(9, sortedOdd), 9);
        EXPECT_EQ(8, sortedOdd.size());
        EXPECT_EQ(9, sortedOdd[sortedOdd.size()-1]);
        EXPECT_EQ(8, sortedOdd[sortedOdd.size()-2]);

    }

    TEST_F(binarySearch, oddMissingUpper){

        sortedOdd.insert(common::binary_search(9, sortedOdd), 9);

        EXPECT_EQ(9, sortedOdd[sortedOdd.size()-1]);
        EXPECT_EQ(8, sortedOdd[sortedOdd.size()-2]);

    }

class swap : public commonTests{
};

    TEST_F(swap, generic){
        auto left = sortedEven.begin()+3;
        auto right = sortedEven.begin()+5;

        cout << *left << " " << *right << endl;
        common::swap(left, right);
        cout << *left << " " << *right << endl;

        EXPECT_EQ(7, sortedEven[3]);
        EXPECT_EQ(5, sortedEven[5]);

    }

class partition : public commonTests{
protected:
    vector<int> unsortedOdd {3,1,2,4,5,8,7,6,9};
    vector<int> unsortedEven {3,1,2,4,5,8,7,6};
};

    TEST_F(partition, odd){
        auto left = unsortedOdd.begin();
        auto right = unsortedOdd.end()-1;

        common::partition(left, right);

        EXPECT_EQ(3, unsortedOdd[2]);

    }

    TEST_F(partition, even){
        auto left = unsortedEven.begin();
        auto right = unsortedEven.end()-1;

        common::partition(left, right);

        EXPECT_EQ(3, unsortedEven[2]);

    }


class rselect : public partition{
};

    TEST_F(rselect, generic){
        auto left = unsortedOdd.begin();
        auto right = unsortedOdd.end()-1;
        auto actual = common::rselect(7, left, right);

        common::print_container(unsortedOdd);
        EXPECT_EQ(8, *actual);

    }


class priorityDeque : public partition{
};

    TEST_F(priorityDeque, generic){
        common::Priority_Deque<int> pd(3);
        pd.enqueue(48);
        pd.enqueue(12);
        pd.enqueue(16);


        EXPECT_EQ(16, pd.median());

        pd.dequeue();


//        EXPECT_EQ(12, pd.median());



    }
}