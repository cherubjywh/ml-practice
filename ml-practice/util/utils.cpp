//
//  utils.cpp
//  ml-practice
//
//  Created by Yuyin Sun on 15-11-7.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#include "utils.h"

template <typename T>
void euclidean_normalization(arma::Mat<T>& A, size_t dim) {
    // Isn't it strange?
    A = arma::normalise(A);
}

template <typename T>
void min_max_normalization(arma::Mat<T>& A, size_t dim, double min_val, double max_val) {
}

template <typename T>
void whitening_normalization(arma::Mat<T>& A, size_t dim) {
    
}

template <typename T>
void row_normalization(arma::Mat<T>& A, normalization_type N) {
    switch (N) {
        case normalization_type::EUCLIDEAN:
            euclidean_normalization(A, 1);
            break;
        case normalization_type::MIN_MAX_0_1:
            min_max_normalization(A, 1);
            break;
        default:
            whitening_normalization(A, 1);
            break;
    }
}

template <typename T>
void col_normalization(arma::Mat<T>& A, normalization_type N) {
    switch (N) {
        case normalization_type::EUCLIDEAN:
            euclidean_normalization(A, 1);
            break;
        case normalization_type::MIN_MAX_0_1:
            min_max_normalization(A, 1);
            break;
        default:
            whitening_normalization(A, 1);
            break;
    }
}