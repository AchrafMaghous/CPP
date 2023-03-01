/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:58 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/01 17:13:49 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	csvFile = new	std::map<std::string, float>();
}

BitcoinExchange::BitcoinExchange(char const *file) {
	if (substr(strlen(file) - 4, 4) != ".csv") {
		std::cerr << "wrong file extension\n";
		exit(EXIT_FAILURE);
	}
	std::ifstream(file);
	while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key; 
		float	value;
        std::getline(iss, key, '=');
        std::getline(iss, value);
        csvFile[key] = std::stof(value);
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&	obj) {
	if (*this != obj)
		this->csvFile = obj.csvFile;
}

BitcoinExchange&	BitcoinExchange::operator= (const BitcoinExchange& obj) {
	BitcoinExchange(obj);
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	std::map<std::string, float>::iterator	it = this->csvFile.begin();
	for (; it != csvFile.end(); ++it) {
		delete	it;
	}
}