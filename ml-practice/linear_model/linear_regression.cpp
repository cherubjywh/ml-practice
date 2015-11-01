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
                 const arma::mat& response,
                 const double lambda,
                 const bool intercept,
                 const arma::vec& weights)
{
    
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