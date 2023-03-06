/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:28:46 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/05 15:24:06 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

class	BitcoinExchange {
	private:
		std::string	file;
		bool	check_is_num(std::string str);
	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& str);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange&	operator= (const BitcoinExchange& obj);
		~BitcoinExchange();

		std::string	getFile();
		bool	checkDate(std::string line);
		void	getValue(std::string line);
		void	checkSyntax(std::string file);
};
#endif