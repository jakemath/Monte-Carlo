//
//  routines.h
//  monte_carlo
//
//  Created by Jacob Mathai on 5/9/20.
//  Copyright © 2020 Jacob Mathai. All rights reserved.
//

#ifndef routines_h
#define routines_h

#include <list>
#include <random>
#include <iostream>
#include <iterator>
#include <thread>
#include <fstream>
#include <chrono>

using namespace std;

double stock_price(double curr_price, double mu, double sigma, double delta_t);
list<double> generate_price_path(double S_0, double mu, double sigma, double delta_t, int n);
list<list<double>> simulate_paths(double S_0, double mu, double sigma, double delta_t, int n, int m);

std::ostream& operator << (std::ostream& o, const list<double>& l);

#endif /* routines_h */
