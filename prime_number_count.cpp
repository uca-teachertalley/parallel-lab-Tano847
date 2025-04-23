/*-- prime_count_serial.cpp-----------------------------------------------------------
   This file implements a program that fills an arry with numbers and 
   then counts the prime numbers in the array
-------------------------------------------------------------------------*/

#include <iostream>
#include <chrono>
#include <cmath>
#include <omp.h>
using namespace std;

// gen_numbers
// This function adds numbers to an array
void gen_numbers(long int numbers[], long int how_many)
{
	for (int i = 0; i < how_many; i++)
	{
		numbers[i] = i;
	}
}

// This function determines if a number is a prime number
bool is_prime(long int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

// This function walks through an array and counts the prime numbers
int count_prime_serial(long int numbers[], long int how_many)
{
	int count = 0;
	for (int i = 0; i < how_many; i++)
	{
		if (is_prime(numbers[i]))
			count++;
	}
	return count;
}
int count_prime_parallel(long int numbers[], long int how_many)
{
	int count = 0;
	omp_set_num_threads(4);
	#pragma omp parallel for reduction(+:count)
	for (int i = 0; i < how_many; i++)
	{
		if (is_prime(numbers[i]))
			count++;
	}
	return count;
}

// This is the entrypoint into the program
int main() {
	long int n = 1000000;
	long int* numbers = new long int[n];
	
	cout << "Generating numbers..." << endl;
	// Generate numbers first
	gen_numbers(numbers, n);
	const int runs = 10;
	double total_time_serial = 0;
	double total_time_parallel = 0;
	int serial_result = 0;
	int parallel_result = 0;
	cout << "\n========== SERIAL RUNS ==========\n";
	for (int i = 0; i < runs; i++) {
		auto start = chrono::steady_clock::now();
		serial_result = count_prime_serial(numbers, n);
		auto end = chrono::steady_clock::now();
		double time = chrono::duration<double>(end - start).count();
		cout << "Serial Run " << i + 1 << ": " << time << " seconds\n";
		total_time_serial += time;
	}
	cout << "\n========== PARALLEL RUNS ==========\n";
	for (int i = 0; i < runs; i++) {
		auto start = chrono::steady_clock::now();
		parallel_result = count_prime_parallel(numbers, n);
		auto end = chrono::steady_clock::now();
		double time = chrono::duration<double>(end - start).count();
		cout << "Parallel Run " << i + 1 << ": " << time << " seconds\n";
		total_time_parallel += time;
	}
	double avg_serial = total_time_serial / runs;
	double avg_parallel = total_time_parallel / runs;
	double speedup = avg_serial / avg_parallel;
	// Print final comparison
	cout << "\n========== FINAL RESULTS ==========\n";
	cout << "Total primes (serial): " << serial_result << "\n";
	cout << "Total primes (parallel): " << parallel_result << "\n";
	cout << "Average time (serial): " << avg_serial << " seconds\n";
	cout << "Average time (parallel): " << avg_parallel << " seconds\n";
	cout << "Speedup (serial / parallel): " << speedup << "x\n";
	delete[] numbers;
    return 0;
}





