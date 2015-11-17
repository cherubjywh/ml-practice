//
//  main.cpp
//  TreeSampling
//
//  Created by Yuyin Sun on 15-11-15.
//  Copyright (c) 2015年 Yuyin Sun. All rights reserved.
//

#include <armadillo>
#include <boost/generator_iterator.hpp>
#include <boost/random.hpp>
#include <boost/random/binomial_distribution.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace arma;
using namespace std;


class multinomial {
    public:
    static size_t get_one(const vector<double>::iterator iter_begin, const vector<double>::iterator iter_end) {
        boost::random::discrete_distribution<> dist(iter_begin, iter_end);
        return dist(*(multinomial::rng));
    }
    static void get_multiple(const vector<double>::iterator iter_begin, const vector<double>::iterator iter_end, int N, unordered_map<size_t, int>& results) {
        for (int i = 0; i < N; ++i) {
            size_t num = get_one(iter_begin, iter_end);
            if (results.find(num) == results.end()) {
                results[num] = 1;
            } else {
                results[num] += 1;
            }
        }
    }
    private:
    static auto_ptr<boost::mt19937> rng;
    
};

auto_ptr<boost::mt19937> multinomial::rng(new boost::mt19937());

class tree_sampler {
public:
    tree_sampler(const vector<vector<double>>& weights);
    void sample_a_tree(unordered_map<size_t, size_t> &);
    void sample_trees(size_t, vector<unordered_map<size_t, size_t>>&);
    void sample_trees(size_t, string);
private:
    vector<vector<double>> _weights;
};

tree_sampler::tree_sampler(const vector<vector<double>>& weights) {
    _weights = weights;
}

void tree_sampler::sample_trees(size_t N, vector<unordered_map<size_t, size_t> > &trees) {
    for (size_t i = 0; i < N; ++i) {
        sample_a_tree(trees[i]);
    }
}

void tree_sampler::sample_a_tree (unordered_map<size_t, size_t> &tree) {
    set<size_t> in_tree;
    in_tree.insert(0);
    
    for (size_t i = 1; i < _weights.size(); ++i) {
        size_t n = i;
        set<size_t> temp;
        while (in_tree.find(n) == in_tree.end()) {
            temp.insert(n);
            vector<double> pvals = _weights[n - 1];
            size_t u = multinomial::get_one(pvals.begin(), pvals.end());
            tree[n] = u;
            n = u;
        }
        
        for (auto i : temp) {
            in_tree.insert(i);
        }
        
    }

}

int main(int argc, const char * argv[]) {
    
    vector<double> pvals = {0.1, 0.2, 0.3, 0.25, 0.15};
    
    cout << multinomial::get_one(pvals.begin(), pvals.end()) << endl;
    
    unordered_map<size_t, int> results;
    int N = 10000;
    multinomial::get_multiple(pvals.begin(), pvals.end(), N, results);
    
    for (int i = 0; i < pvals.size(); ++i) {
        if (results.find(i) == results.end()) {
            cout << i << ": 0" <<endl;
        } else {
            cout << i << ": " << results[i]*1.0/N << endl;
        }
    }
    
    return 0;
}
