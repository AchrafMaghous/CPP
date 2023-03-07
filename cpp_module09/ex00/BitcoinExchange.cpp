/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:58 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/07 18:53:12 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	bitcoinExchange(std::string csvFileName, std::string txtFileName)
{
	std::vector<BitcoinExchange>	bitcoinData;
	std::vector<InputValues>		inputData;

	btcDb(bitcoinData, csvFileName);
	inputFile(inputData, txtFileName);

	convert(bitcoinData, inputData);

	printConversion(inputData);
}

void	btcDb(std::vector<BitcoinExchange> &bitcoinData, std::string fileName)
{
	std::ifstream	file;
	std::string		line;

	file.open(fileName.c_str());

	getline(file, line);

	while (getline(file, line))
	{
		std::istringstream	stringStream;
		std::string			date;
		float				value;

		stringStream.str(line);

		getline(stringStream, date, ',');

		stringStream >> value;

		BitcoinExchange bitcoin(date, value);

		bitcoinData.push_back(bitcoin);
  }
}

void inputFile(std::vector<InputValues> &inputData, std::string fileName)
{
	std::ifstream	file;
	std::string	line;

	file.open(fileName.c_str());

	getline(file, line);

	if (!(line == "date | value"))
	{
		std::cout << "Error: bad input =>" << line << std::endl;
		return ;
	}

	while (getline(file, line))
	{
		std::string	delimiter = " | ";
		std::string	date;
		std::string	stringValue;
		
		size_t pos = line.find(delimiter);

		if (pos == 10)
		{
			date = line.substr(0, pos);
			stringValue = line.substr(pos + delimiter.length());
		}
		else
		{
			date = line;
			stringValue = "";
		}
		
		double value = std::atof(stringValue.c_str());
		bool tooLarge = false;
		bool notPositive = false;
		bool badInput = false;

		if (value > INT_MAX)
			tooLarge = true;
		else if (pos != 10 || !checkDate(date))
			badInput = true;
		else if (value < 0)
			notPositive = true;
		else
			value = float(value);

		InputValues input(date, value, tooLarge, notPositive, badInput);

		inputData.push_back(input);
	}
}

void	convert(const std::vector<BitcoinExchange> bitcoinData, std::vector<InputValues> &inputData)
{
	for (int i = 0; i < bitcoinData.size(); i++)
	{
		for (int j = 0; j < inputData.size(); j++)
		{
			if (inputData[j].date == bitcoinData[i].date)
			{
				if (inputData[j].tooLarge || !inputData[j].notPositive || !inputData[j].badInput)
				inputData[j].exchangedValue = inputData[j].value * bitcoinData[i].value;
			}
		}
	}
}

void printConversion(const std::vector<InputValues> inputData)
{
	for (int i = 0; i < inputData.size(); i++)
	{
		if (inputData[i].tooLarge)
			std::cout << "Error: too large a number." << std::endl;
		else if (inputData[i].notPositive)
			std::cout << "Error: not a positive number." << std::endl;
		else if (inputData[i].badInput)
			std::cout << "Error: bad input => " << inputData[i].date << std::endl;
		else
			std::cout << inputData[i].date << " => " << inputData[i].value << " = "  << inputData[i].exchangedValue << std::endl;
	}
}

bool checkDate( const std::string &date )
{
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
