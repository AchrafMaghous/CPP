/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:54:06 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/15 16:23:48 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& obj) { *this = obj;}

RPN::~RPN() {}

RPN&	RPN::operator= (const RPN &obj) {
	s = obj.s;
	return *this;
}

bool	RPN::checkOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int	RPN::executeOperation(char o, int a, int b) {
	switch (o)
	{
	case '+' : return a + b;
	case '-' : return a - b;
	case '*' : return a * b;
	case '/' :
		if (b == 0) throw	std::runtime_error("Error: cannot divide by 0");
		else
			return a / b;
	
	default:	throw std::runtime_error("Error: invalid operator");
	}
}

int	RPN::result ( const std::string &rpn ) {
	while (!s.empty()) s.pop();
	for (size_t i = 0; i < rpn.size(); ++i) {
		if (isdigit(rpn[i])) {
			int num = rpn[i] - '0';
			if (num >= 10) throw std::runtime_error("Error: Number must be less than 10.");
			s.push(num);
		} else if (checkOperator(rpn[i])) {
			if (s.size() < 2) throw std::runtime_error("Error: Invalid RPN expression.");
			int b = s.top(); s.pop();
			int a = s.top(); s.pop();
			s.push(executeOperation(rpn[i], a, b));
		}
	}

	if (s.size() != 1) throw std::runtime_error("Error: Invalid rpn.");
	return s.top();
}