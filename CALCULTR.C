#include <stdio.h>
#include <math.h>

int main(void) {
  char operation;
  double num1, num2;

  printf("Enter an operation (+, -, *, /, ^, s (sine), c (cosine), t (tangent)): ");
  scanf(" %c", &operation);

  printf("Enter two numbers: ");
  scanf("%lf %lf", &num1, &num2);

  switch (operation) {
    case '+':
      printf("%.1lf + %.1lf = %.1lf\n", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%.1lf - %.1lf = %.1lf\n", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%.1lf * %.1lf = %.1lf\n", num1, num2, num1 * num2);
      break;
    case '/':
      printf("%.1lf / %.1lf = %.1lf\n", num1, num2, num1 / num2);
      break;
    case '^':
      printf("%.1lf ^ %.1lf = %.1lf\n", num1, num2, pow(num1, num2));
      break;
    case 's':
      printf("sin(%.1lf) = %.1lf\n", num1, sin(num1));
      break;
    case 'c':
      printf("cos(%.1lf) = %.1lf\n", num1, cos(num1));
      break;
    case 't':
      printf("tan(%.1lf) = %.1lf\n", num1, tan(num1));
      break;
    default:
      printf("Invalid operator.\n");
      break;
  }

  return 0;
}
