//
//  test_least_square.cpp
//  ml-practice
//
//  Created by Yuyin Sun on 15-11-1.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>
#include "linear_regression.h"


int add(int i, int j)
{
    return i + j;
}

using namespace regression;

BOOST_FIXTURE_TEST_SUITE(LRTest, LinearRegression)

BOOST_AUTO_TEST_CASE(initLR)
{
    arma::mat A;
    A << 0 << arma::endr
    << 1;
    
    arma::mat y;
    y << 0.5 << arma::endr << 1;
    
    LinearRegression lr(A, y);
    
    auto parameters = lr.Parameters();
    
    parameters.print("results 1 dimension");
    
    BOOST_CHECK_CLOSE(parameters(0), 0.5, 1e-4);
    BOOST_CHECK_CLOSE(parameters(1), 0.5, 1e-4);
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(Maths)

BOOST_AUTO_TEST_CASE(universeInOrder)
{
    BOOST_CHECK(add(2, 2) == 4);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Physics)

BOOST_AUTO_TEST_CASE(specialTheory)
{
    int e = 32;
    int m = 2;
    int c = 4;
    
    BOOST_CHECK(e == m * c * c);
}

BOOST_AUTO_TEST_SUITE_END()