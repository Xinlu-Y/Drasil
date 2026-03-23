#include "Populate.hpp"

#include <vector>

using std::vector;

Populate::Populate(vector<double> &q) : q(q) {
}

void Populate::operator()(vector<double> &y, double t) {
    q.push_back(y.at(0));
}
