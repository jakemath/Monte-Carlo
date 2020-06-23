//
//  routines.cpp
//  monte_carlo
//
//  Created by Jacob Mathai on 5/9/20.
//  Copyright © 2020 Jacob Mathai. All rights reserved.
//

#include "routines.h"

double stock_price(double S_t,
                   double mu,
                   double sigma,
                   double delta_t,
                   std::normal_distribution<double> norm)
{
    std::random_device rd;
    return S_t*(1.0 + mu*delta_t + sigma*norm(rd)*pow(delta_t, 0.5));
}


list<double> generate_price_path(double S_0, double mu, double sigma, double delta_t, int n)
{
    list<double> path;
    double S_t = S_0;
    path.push_back(S_t);
    std::normal_distribution<double> norm(mu, sigma);
    for (unsigned i = 1; i <= n; ++i)
    {
        path.push_back(stock_price(S_t, mu, sigma, delta_t, norm));
        S_t = path.back();
    }
    return path;
}


list<list<double>> simulate_paths(double S_0, double mu, double sigma, double delta_t, int n, int m)
{
    list<list<double>> paths;
    for (unsigned i = 1; i <= m; ++i)
    {
        cout << "PATH " << i << endl;
        paths.push_back(generate_price_path(S_0, mu, sigma, delta_t, n));
    }
    return paths;
}


std::ostream& operator << (std::ostream& o, const list<double>& l)
{
    list<double>::const_iterator i = l.begin();
    for (; i != --l.end(); ++i)
        o << *i << ", ";
    o << *i << endl;
    return o;
}
