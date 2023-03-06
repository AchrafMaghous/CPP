#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error: Failed to open input file " << argv[1] << "\n";
        return 1;
    }

    std::map<std::string, double> date_values;
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string date_str, value_str;
        double value;
        char sep;
        if (iss >> date_str >> sep >> value_str) {
            std::istringstream value_ss(value_str);
            if (value_ss >> value) {
                date_values[date_str] += value;
            } else {
                std::cerr << "Error: Invalid value on line " << line << "\n";
            }
        } else if (!line.empty()) {
            std::cerr << "Error: Invalid input on line " << line << "\n";
        }
    }

    std::cout << "Date | Value\n";
    for (std::map<std::string, double>::const_iterator it = date_values.begin(); it != date_values.end(); ++it) {
        std::cout << it->first << " | " << it->second << "\n";
    }

    return 0;
}
