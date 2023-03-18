/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:03 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/15 16:21:56 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Usage: ./RPN <RPN_expression>\n" << std::endl;
		return 1;
	}
	try
	{
		RPN	rpn;
		int	res = rpn.result(av[1]);
		std::cout << res << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}
	
	return 0;
}