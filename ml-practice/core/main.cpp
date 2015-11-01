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
    
    mat A;
    A.randu(4, 3);
    A.print("A Random Matrix");
    
    return 0;
}
