//
//  linear_regression.h
//  ml-practice
//
//  Created by Yuyin Sun on 15-11-1.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#ifndef __ml_practice__linear_regression__
#define __ml_practice__linear_regression__

#include <armadillo>

namespace regression {
    class LinearRegression {
    public:
        LinearRegression(const arma::mat& predicators,
                         const arma::mat& responses,
                         const double lambda = 0,
                         const bool intercept = true,
                         const arma::vec& weights = arma::vec());
//        LinearRegression(const std::string& filename);
        LinearRegression(const LinearRegression& linearRegression);
        LinearRegression() {}
        
        void Predict (const arma::mat& points, arma::vec & predicts) const;
        
        double ComputeError (const arma::mat& points, const arma::vec& responses) const;
        
        const arma::vec& Parameters () const {return parameters;}
        
        arma::vec& Parameters () {return parameters;}
        
        double Lambda () const {return lambda;}
        double& Lambda () {return lambda;}
        
//        std::string ToString () const;
        
    private:
        arma::vec parameters;
        double lambda;
        bool intercept;
    };
}

#endif /* defined(__ml_practice__linear_regression__) */
