//
//  linear_regression.cpp
//  ml-practice
//
//  Created by Yuyin Sun on 15-11-1.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#include "linear_regression.h"


using namespace regression;

LinearRegression::LinearRegression(const arma::mat& predicators,
                 const arma::mat& responses,
                 const double lambda,
                 const bool intercept,
                 const arma::vec& weights) :
    lambda (lambda), intercept(intercept)
{
    // predicators: X is a N x D matrix, where N is the number of examples, and D is the number features
    const size_t n_dims = predicators.n_cols;
    const size_t n_insts = predicators.n_rows;
    
    // We need to do some preprocessing over X
    // We don't want to do manipulation on the original data. Such that we copy the data into a new matrix
    arma::mat p = predicators;
    arma::vec r = responses;
}


LinearRegression::LinearRegression(const std::string& filename)
{
    
}


LinearRegression::LinearRegression(const LinearRegression* linearRegression)
{
    
}

void LinearRegression::Predict (const arma::mat& points, arma::vec & predicts) const
{
    
}

double LinearRegression::ComputeError (const arma::mat& points, const arma::vec& responses) const
{
    return 0.0;
}


std::string LinearRegression::ToString () const
{
    return "";
}