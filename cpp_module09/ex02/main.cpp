/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:41:01 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/16 18:05:47 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cout << "Usage: " << av[0] << " <sequence of positive integers>\n";
		return 1;
	}
	
	try {
		PmergeMe	p(ac, av);
	}
	catch(const char *msg) {
		std::cout << msg << std::endl;
		return 2;
	};
}