/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:37 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/06 15:00:21 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./btc	<txt_file>\n";
		return 1;
	}
	BitcoinExchange	data("data.csv");
	data.checkSyntax(av[1]);
	return (0);
}