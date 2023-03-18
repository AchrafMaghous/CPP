/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:41:12 by acmaghou          #+#    #+#             */
/*   Updated: 2023/03/18 11:16:09 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(int ac, char **av) {
	clock_t	start_time_vec, end_time_vec, start_time_deq, end_time_deq;
	for (int i = 1; i < ac; i++) {
		int	conv = std::atoi(av[i]);
		if (conv < 0) throw	"Error";
		else {
			inputVec.push_back(conv);
			deq.push_back(conv);
		}
	}
	std::cout << "Before: ";
	printVec(inputVec);
	start_time_vec = clock();
	mergeSort(inputVec, 0 , inputVec.size() - 1);
	end_time_vec = clock();
	start_time_deq = clock();
	mergeSort(deq, 0, deq.size() - 1);
	end_time_deq = clock();
	std::cout << "After: ";
	printVec(inputVec);
	double	elapsed_time_vec = (double)(end_time_vec - start_time_vec)/ CLOCKS_PER_SEC;
	std::cout << "Time to process a range of 5 elements with std::vector : " << std::fixed
	<< elapsed_time_vec << " us" << std::endl;

	double	elapsed_time_deq = (double)(end_time_deq - start_time_deq)/ CLOCKS_PER_SEC;
	std::cout << "Time to process a range of 5 elements with std::deque :  " << std::fixed
	<< elapsed_time_deq<< " us" << std::endl;
}

PmergeMe::~PmergeMe() {

}

template	<typename T>
void	merge(T &con, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    T temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (con[i] <= con[j]) {
            temp[k++] = con[i++];
        } else {
            temp[k++] = con[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = con[i++];
    }

    while (j <= right) {
        temp[k++] = con[j++];
    }

    for (i = left, k = 0; i <= right; ++i, ++k) {
        con[i] = temp[k];
    }
}
template	<typename T>
void	mergeSort(T& con, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(con, left, mid);
        mergeSort(con, mid + 1, right);
        merge(con, left, mid, right);
    }
}

// void	PmergeMe::print(std::queue<int>& res) {
	
// }

void	PmergeMe::printVec(std::vector<int>& vec) {
	std::vector<int>::iterator	it = vec.begin();
	for (; it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// time

