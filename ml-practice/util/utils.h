//
//  utils.h
//  ml-practice
//
//  Created by Yuyin Sun on 15-11-7.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#ifndef __ml_practice__utils__
#define __ml_practice__utils__

#include <stdio.h>
#include <armadillo>

enum normalization_type {
    EUCLIDEAN,
    MIN_MAX_0_1,
    WHITENING
};

template <typename T>
void euclidean_normalization(arma::Mat<T>& A, size_t dim = 0);

template <typename T>
void min_max_normalization(arma::Mat<T>& A, size_t dim = 0, double min_val = 0.0, double max_val = 1.0);

template <typename T>
void whitening_normalization(arma::Mat<T>& A, size_t dim = 0);

template <typename T>
void row_normalization(arma::Mat<T>&, normalization_type);

template <typename T>
void col_normalization(arma::Mat<T>&, normalization_type);


#endif /* defined(__ml_practice__utils__) */
