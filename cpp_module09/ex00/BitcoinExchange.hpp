/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:28:46 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/01 17:13:25 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>

class	BitcoinExchange {
	private:
		std::map<std::string, float>	*csvFile;
	public:
		BitcoinExchange();
		BitcoinExchange(char const *file);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange&	operator= (const BitcoinExchange& obj);
		~BitcoinExchange();	
};
#endif