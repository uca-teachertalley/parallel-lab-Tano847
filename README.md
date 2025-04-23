Prime number count parallelism exercise

- This code counts the number of primes in an array without parallelism
- Your goal is to add parallelism with OpenMP!
- The project should be configured properly, but you can add OpenMP to 
  Visual Studio project by going to Project Properties-C/C++-Language.
  Set the Open MP Support option to "Yes"
 

  ## 1. Average Time for 10 Serial Runs:
- Serial Run 1: 0.340184 seconds
- Serial Run 2: 0.389753 seconds
- Serial Run 3: 0.337542 seconds
- Serial Run 4: 0.332908 seconds
- Serial Run 5: 0.331952 seconds
- Serial Run 6: 0.332642 seconds
- Serial Run 7: 0.334194 seconds
- Serial Run 8: 0.335501 seconds
- Serial Run 9: 0.331157 seconds
- Serial Run 10: 0.330889 seconds
- **Average Serial Time:** 0.339672 seconds

## 2. Average Time for 10 Parallel Runs:
  Parallel Run 1: 0.330982 seconds
- Parallel Run 2: 0.329257 seconds
- Parallel Run 3: 0.329554 seconds
-Parallel Run 4: 0.33133 seconds
- Parallel Run 5: 0.331399 seconds
- Parallel Run 6: 0.332537 seconds
- Parallel Run 7: 0.330284 seconds
- Parallel Run 8: 0.329305 seconds
- Parallel Run 9: 0.330447 seconds
- Parallel Run 10: 0.33137 seconds
**Average Parallel Time:** 0.330647 seconds
## 3. Speedup Calculation:
Speedup (serial / parallel): 1.0273x

## 4. Thread Decomposition (How OpenMP divides the work):
- Threads used: **4**
- Total elements: **1,000,000**
## 5. Did parallelizing `gen_numbers()` help?
- Not tested.
- But likely wouldn't improve much — that loop is simple and very fast already.