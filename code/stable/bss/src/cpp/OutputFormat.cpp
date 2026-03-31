#include "OutputFormat.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::ofstream;
using std::string;
using std::vector;

void write_output(vector<vector<double>> &q) {
    ofstream outputfile;
    outputfile.open("output.txt", std::fstream::out);
    outputfile << "q = ";
    outputfile << "[";
    for (int list_i1 = 0; list_i1 < (int)(q.size()) - 1; list_i1++) {
        outputfile << q.at(list_i1);
        outputfile << ", ";
    }
    if ((int)(q.size()) > 0) {
        outputfile << q.at((int)(q.size()) - 1);
    }
    outputfile << "]" << std::endl;
    outputfile.close();
}
