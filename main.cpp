//
//  main.cpp
//  monte_carlo
//
//  Created by Jacob Mathai on 5/9/20.
//  Copyright © 2020 Jacob Mathai. All rights reserved.
//

#include "routines.h"

int main()
{
    list<list<double>> paths = simulate_paths(100.0, 0.0, .1, 0.001, 10000, 20);
    std::ofstream out("paths.txt");
    for (list<list<double>>::iterator i = paths.begin(); i != paths.end(); ++i)
        out << *i;
}
