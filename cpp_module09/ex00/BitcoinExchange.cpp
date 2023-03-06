/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:58 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/06 18:53:52 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : file(nullptr) {
}

BitcoinExchange::BitcoinExchange(const std::string& line) : file(line) {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&	obj) {
	this->file = obj.file;
}

BitcoinExchange&	BitcoinExchange::operator= (const BitcoinExchange& obj) {
	this->file = obj.file;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

bool	BitcoinExchange::check_is_num(std::string str) {
	std::string::iterator	it = str.begin();
	while (*it != '|')
		++it;
	++it;
	for (; it != str.end(); ++it) {
		if (!isdigit(*it))
			return false;
	}
	return true;
}

bool	BitcoinExchange::checkDate(std::string line) {

	return true;
}

void	BitcoinExchange::getValue(std::string line)
{
	int i = 0;
	for (; line[i] != '|'; ++i);
	std::string sub = line.substr(i + 2);
	// int	convsub = stoi(sub);
	// std::cout << "value: " << convsub << std::endl;
	// if (convsub < 0)
		// return ;
}

void	BitcoinExchange::checkSyntax(std::string file) {
	std::ifstream	infile(file);
	std::string		line;
	while (getline(infile, line)) {
		checkDate(line);
		// getValue(line);
	}
}