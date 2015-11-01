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
    // predicators: A is a N x D matrix, where N is the number of examples, and D is the number features
    const size_t n_dims = predicators.n_cols;
    const size_t n_insts = predicators.n_rows;
    
    // We need to do some preprocessing over A
    // We don't want to do manipulation on the original data. Such that we copy the data into a new matrix
    arma::mat p = predicators;
    arma::vec r = responses;
    
    // Add psudo-feature x_0 for the bias term
    if (intercept)
    {
        p.insert_cols(0, arma::ones<arma::mat>(n_insts, 1));
    }
    
    if (weights.n_elem > 0) {
        p = arma::diagmat(sqrt(weights)) * p;
        r = arma::sqrt(weights) % responses;
    }
    
    // Get B = [A; sqrt(\lambda)I], if lambda is non-zero
    if (lambda != 0.0)
    {
        p.insert_rows(p.n_rows, n_dims);
        p.submat(p.n_rows - n_dims + 1, p.n_cols - n_dims, n_dims, n_dims) =
        sqrt(lambda) * arma::eye<arma::mat>(n_dims, n_dims);
    }
    
    // Perform QR decomposition
    
    arma::mat Q, R;
    arma::qr(Q, R, p);
    
    // Solve the linear system
    if (lambda == 0.0)
    {
        arma::solve(parameters, R, arma::trans(Q)*r);
    }
    else
    {
        r.insert_rows(n_insts, n_dims);
        arma::solve(parameters, R, arma::trans(Q)*r);
    }
    
}


LinearRegression::LinearRegression(const LinearRegression& linearRegression) : parameters(linearRegression.parameters),
lambda(linearRegression.lambda)
{
    
}

void LinearRegression::Predict (const arma::mat& points, arma::vec & predictions) const
{
    if (!intercept) {
        predictions = points * parameters;
    } else
    {
        predictions = points * parameters.subvec(1, parameters.n_rows - 1);
        predictions = predictions + parameters(0);
    }

}

double LinearRegression::ComputeError (const arma::mat& points, const arma::vec& responses) const
{
    arma::vec temp;
    Predict(points, temp);
    temp = temp - responses;
    
    const double err = arma::dot(temp, temp) / points.n_rows;
    return err;
}

