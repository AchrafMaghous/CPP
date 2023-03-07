/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:28:46 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/07 18:53:12 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

// we cannot use a map here cause there could be an overlap of map keys in same date case
// in the case of data.csv file, it is possible to use a map because of the uniqueness of dates.

struct BitcoinExchange
{
	std::string	date;
	float		value;

	BitcoinExchange( std::string &date, float value ) : date(  date ), value( value ) {};
};

struct InputValues
{
	std::string	date;
	float		value;
	float		exchangedValue;

	bool		tooLarge;
	bool		notPositive;
	bool		badInput;

	InputValues(std::string &date, float value, bool tooLarge, bool notPositive, bool badInput) : date(date), value(value), exchangedValue( 0 ), tooLarge( tooLarge ), notPositive( notPositive ), badInput( badInput ) {};
};

void	btcDb(std::vector<BitcoinExchange> &bitcoinData, std::string fileName );
void	inputFile(std::vector<InputValues> &inputData, std::string fileName );
void	convert(const std::vector<BitcoinExchange> bitcoinData, std::vector<InputValues> &inputData );
void	bitcoinExchange(std::string csvFileName, std::string txtFileName );
void	printConversion(const std::vector<InputValues> inputData );
bool	checkDate(const std::string &date );
#endif