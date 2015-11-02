//
//  main.cpp
//  ml-practice
//
//  Created by Yuyin Sun on 15-11-1.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main(int argc, const char * argv[]) {
    
    arma::mat A;
    A << 0 << arma::endr
    << 1;
    
    arma::mat y;
    y << 0.5 << arma::endr << 1;
    
    LinearRegression lr(A, y);
    
    auto parameters = lr.Parameters();
    
    return 0;
}
