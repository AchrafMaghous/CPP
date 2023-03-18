/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:46:13 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/18 14:11:48 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstring>
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

class	BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange(std::string csv, std::string txt);
		BitcoinExchange &operator=(const BitcoinExchange &obj);
		~BitcoinExchange();
		
		float	getExchangeRate(const std::string &date);

	private:
		std::map<std::string, float> exchange_rates;
		bool	checkDate(std::string &date);
		void	parseBtcData(const std::string &csv);
		void	Input(std::string& );
		
};



#endif