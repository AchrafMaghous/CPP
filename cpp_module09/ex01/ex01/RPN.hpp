/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:53:59 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/15 15:55:51 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <cstring>
#include <stack>
#include <cmath>

class	RPN {
		
	public:
		RPN();
		~RPN();
		RPN&	operator= (const RPN& obj);
		RPN(const RPN& obj);

		int	result( const std::string&);
	private:
		bool	checkOperator(char c);
		int		executeOperation(char o, int a, int b);
		std::stack<int>	s;
		
};

#endif