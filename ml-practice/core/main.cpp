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

void learn_normalization() {
    
    arma::Mat<double> A;
    A.randn(2, 4);
    auto B = normalise(A, 2);
    auto C = normalise(A, 1);
    auto D = normalise(A, 2, 1);
    
    A.print("Matrix A");
    // diagmat: generate a diagnal matrix from a vector of a matrix
    // It is the same as matlab function diag()
    // Nice
    diagmat(A.t() * A).print("Norm of each column");
    diagmat(A * A.t()).print("Norm of each row");
    
    // Each column is l-2 normalised
    B.print("L-2 normalization of A");
    diagmat(B.t() * B).print("Norm of each column");
    diagmat(B * B.t()).print("Norm of each row");
    
    
    // Each column is l-1 normalised
    C.print("L-1 normalization of A");
    diagmat(C.t() * C).print("Norm of each column");
    diagmat(C * C.t()).print("Norm of each row");
    
    
    // Each row is l-2 normalised
    D.print("L-2 normalization of A, row-wise");
    diagmat(D.t() * D).print("Norm of each column");
    diagmat(D * D.t()).print("Norm of each row");

}

int main(int argc, const char * argv[]) {
    
    learn_normalization();
    
    return 0;
}
