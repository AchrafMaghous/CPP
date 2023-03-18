/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:46:21 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/18 12:29:26 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	*this = obj;
}

BitcoinExchange::BitcoinExchange(std::string csv, std::string txt) {
	parseBtcData(csv);
	Input(txt);
}

BitcoinExchange&	BitcoinExchange::operator= (const BitcoinExchange& obj) {
	exchange_rates = obj.exchange_rates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {

}

float BitcoinExchange::getExchangeRate(const std::string &date_str)
{
	std::string year_str = date_str.substr(0, 4);
	std::string month_str = date_str.substr(5, 2);
	std::string day_str = date_str.substr(8, 2);
	std::string key = year_str + month_str + day_str;

	std::map<std::string, float>::iterator it;
	it = exchange_rates.lower_bound(key);
	if (it != exchange_rates.end())
		return it->second;
	else {
		--it;
		return	it->second;
	}
}

void	BitcoinExchange::parseBtcData(const std::string &btc) {
	std::ifstream data_file(btc);
	if (!data_file)
		throw std::runtime_error("Could not open data file.");

	std::string line;
	
	while (std::getline(data_file, line))
	{
		std::stringstream ss(line);
		std::string year, month, day , exchange_rate_str;
		std::getline(ss, year, '-');
		std::getline(ss, month, '-');
		std::getline(ss, day, ',');
		std::getline(ss, exchange_rate_str);
		std::string key = year + month + day;
		

		float exchange_rate;
		try
		{
			exchange_rate = std::atof(exchange_rate_str.c_str());
		}
		catch (...)
		{
			std::cerr << "Invalid argument" << std::endl;
			continue;
		}
		exchange_rates[key] = exchange_rate;
	}
}

bool	BitcoinExchange::checkDate(std::string date) {
	if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2023)
        return false;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > 31)
        return false;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        if (day > 29)
            return false;
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return false;
    }

    return true;
}

void	BitcoinExchange::Input(std::string txt ) {
	std::ifstream	file(txt);
	std::string line;
	while (std::getline(file, line))
	{
		std::string date_str, value_str;
		std::size_t pos = line.find('|');
		if (pos != std::string::npos || checkDate(date_str))
		{
			date_str = line.substr(0, pos);
			value_str = line.substr(pos + 1);
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value;
		try
		{
			value = std::stof(value_str);
   			if (value > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			if (value < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Parse date and get exchange rate
		float exchange_rate = getExchangeRate(date_str);
		if (exchange_rate < 0)
		{
			std::cout << "Error: invalid date => " << date_str << std::endl;
			continue;
		}

		// Compute and print result
		float result = value * exchange_rate;
		std::cout << date_str << " => " << value << " = " << result << std::endl;
	}
}
