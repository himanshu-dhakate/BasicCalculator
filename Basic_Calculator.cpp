#include <iostream>
#include <string>
using namespace std;

long long fact(int n) {
  if (n == 0) return 0;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}

long long countZeros(int n) {
  if (n < 0) return -1;
  long long count = 0;

  for (int i = 5; n / i >= 1; i *= 5) {
    count += n / i;
  }
  return count;
}

int main() {

  while (true) {
  cout << "\t1. Add Two Numbers\n";
  cout << "\t2. Subtract Two numbers\n";
  cout << "\t3. Multiply Two numbers\n";
  cout << "\t4. Divide Two numbers\n";
  cout << "\t5. Factorial of number\n";
  cout << "\t6. Number of zeros at the end of the factorial\n";
  cout << "\t7. Enter Zen Mode\n";
  cout << "\tAnything else to exit\n";

  int choice;
  cin >> choice;

  if (choice >= 1 && choice <= 4) {
    int a, b;
    cout << "Enter two numbers\n";
    cin >> a >> b;

    switch(choice) {
      case 1: cout << "Addition is " << a + b << '\n'; break;
      case 2: cout << "Subtraction is " << a - b << '\n'; break;
      case 3: cout << "Multiplication is " << a * 1LL * b << '\n'; break;
      case 4: if (b == 0) cout << "Cannot divide by 0\n";
              else cout << "Division is " << a / b << '\n'; break;
    }
  }
  
  else if (choice >= 5 && choice <= 6) {
    int n;
    cout << "Enter a number\n";
    cin >> n;
    switch(choice) {
      case 5: cout << "Factorial is " << fact(n) << '\n'; break;
      case 6: cout << "Number of zeros at the end of factorial is " << countZeros(n) << '\n'; break;
    }
  }

  else if (choice == 7) {
    cout << "Zen mode activated\n";
    while (true) {
      string input;
      getline(cin, input);
      if (input == "normal") break;
      
      int num1 = 0, num2 = 0;
      char op = 'x';

      for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ') continue;
        
        if (op == 'x' && input[i] >= '0' && input[i] <= '9') {
          num1 = num1 * 10 + (input[i] - '0');
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '!') {
          op = input[i];
        }
        else if (op != 'x' && input[i] >= '0' && input[i] <= '9') {
          num2 = num2 * 10 + (input[i] - '0');
        }
      }

      switch(op) {
        case '!': cout << "Factorial is " << fact(num1) << '\n'; break;
        case '+': cout << "Addition is " << num1 + num2 << '\n'; break;
        case '*': cout << "Multiplication is " << num1 * 1LL * num2 << '\n'; break;
        case '-': cout << "Subtraction is " << num1 - num2 << '\n'; break;
        case '/': if (num2 == 0) cout << "Cannot divide by 0\n";
                  else cout << "Division is " << num1 / num2 << '\n'; break;
        default: cout << "Please enter a valid operator\n";
      }
    }
  }

  else {
    cout << "ThankYou for using our calculator ^_^\n";
    break;
  }
  }
}