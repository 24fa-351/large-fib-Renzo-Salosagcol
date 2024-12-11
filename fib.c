#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef __uint128_t fib_int_t;

fib_int_t recursiveFibWrapper (
   fib_int_t target_fib_index, 
   fib_int_t fib_series[], int max_index) {

   if (max_index == target_fib_index) {
      return fib_series[max_index];
   } else {
      fib_series[max_index + 1] = 
      fib_series[max_index] + fib_series[max_index - 1];
      return recursiveFibWrapper(
         target_fib_index, 
         fib_series, 
         max_index + 1);
   }

   return 0;
}

fib_int_t iterativeFibWrapper (
   fib_int_t target_fib_index, 
   fib_int_t fib_series[], int max_index) {

   while (max_index != target_fib_index) {
      fib_series[max_index + 1] = 
      fib_series[max_index - 1] + fib_series[max_index];
      max_index++;
   }

   return fib_series[max_index];
}

fib_int_t fib_r(
   fib_int_t target_fib_index, 
   fib_int_t fib_series[]) {

      if (fib_series[target_fib_index] != 0 ||
         target_fib_index == 0 ||
         target_fib_index == 1) {
            return fib_series[target_fib_index];
         }
      
      return recursiveFibWrapper(target_fib_index, fib_series, 1);
}

fib_int_t fib_i(
   fib_int_t target_fib_index, 
   fib_int_t fib_series[]) {

      if (fib_series[target_fib_index] != 0 ||
         target_fib_index == 0 ||
         target_fib_index == 1) {
            return fib_series[target_fib_index];
         }
      
      return iterativeFibWrapper(target_fib_index, fib_series, 1);
}

int main (int argc, char *argv[]) {

   if (argc != 3) {
      fprintf(stderr, "Usage: %s <number> <type>\n", argv[0]);
      return 1;
   }

   const fib_int_t TARGET_FIB_INDEX = atoi(argv[1]);
   const char INFORMATION_TYPE = argv[2][0];

   fib_int_t fib_series[TARGET_FIB_INDEX + 1];
   for (fib_int_t index = 0; index < TARGET_FIB_INDEX + 1; index++) {
      fib_series[index] = 0;
   }
   fib_series[0] = 0;
   fib_series[1] = 1;
   fib_int_t result = 0;

   if (INFORMATION_TYPE == 'r') {
      result = fib_r(TARGET_FIB_INDEX, fib_series);
   }
   else if (INFORMATION_TYPE == 'i') {
      result = fib_i(TARGET_FIB_INDEX, fib_series);
   }

   printf("%llu\n", (unsigned long long)result);
   
   return 0;
}