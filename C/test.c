#include <stdio.h>

int myAtoi(char *str) {
  int result = 0;
  int sign = 1;
  int i = 0;

  // Skip whitespace
  while (str[i] == ' ') {
    i++;
  }

  // Handle optional sign
  if (str[i] == '-' || str[i] == '+') {
    sign = (str[i++] == '-') ? -1 : 1;
  }

  // Process digits
  while (str[i] >= '0' && str[i] <= '9') {
    // Handle overflow
    if (result > INT_MAX / 10 ||
        (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
      return (sign == 1) ? INT_MAX : INT_MIN;
    }
    result = result * 10 + (str[i++] - '0');
  }

  return result * sign;
}

int main() {
  char str[] = "12345";
  printf("%d\n", myAtoi(str)); // Output: 12345

  char str2[] = "-6789";
  printf("%d\n", myAtoi(str2)); // Output: -6789

  char str3[] = "  987 abc";
  printf("%d\n", myAtoi(str3)); // Output: 987

  char str4[] = "words and 987";
  printf("%d\n", myAtoi(str4)); // Output: 0

  return 0;
}
