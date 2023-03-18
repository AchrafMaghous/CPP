/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:40:58 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/16 18:59:38 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <memory>
#include <sys/time.h>

class	PmergeMe {
	private:
		std::vector<int>	inputVec;
		std::deque<int>		deq;
		void	printVec(std::vector<int>&);
	public:
		PmergeMe();
		PmergeMe(int ac, char **);
		~PmergeMe();
		// void	print(std::queue<int>&);
};

template	<typename T>
void	merge(T& con, int left, int mid , int right);

template	<typename T>
void	mergeSort(T& arr, int left, int right);


#endif