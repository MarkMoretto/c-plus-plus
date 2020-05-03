/***********************************************************
Program to check whether an integer is a palindrome or not.

Contributor(s): Mark Moretto
Date: 2020-05-03
***********************************************************/

#include <iostream>

const char nl = '\n';


// Reverse the input value.
void reverser(long n, long &out) {
    out = 0;
    long tmp;

    while (n != 0) {
        tmp = n % 10;
        out = (out * 10) + tmp;
        n /= 10;
    }
}

// Validate and return notification of success or failure.
void ispalindrome(long original, long result) {
    if (original == result) {
        std::cout << "Your number is a palindrome, Harry!";
    } else {
        std::cout << "Your number is NOT a palindrome.";
    }    
}

int main() {
    // Define two integers and a pointer
    long res(0);
    long num;
    long * n_ptr = &num;
    
    // Ask used to input non-zero number.
    // TODO: Add integer check
    // TODO: Add method to handle string input.
    // TODO: Allow for command-line arguments.
    std::cout << "Pleae enter a non-zero integer value" << nl << ">>>";
    std::cin >> num;
    
    // Call our function to reverse the numeric input
    // Function uses res memory location reference to update res.
    reverser(*n_ptr, res);
    
    // Print result of reverser function to prompt.
    std::cout << "The reverse of " << num << " is " << res << nl;
    
    // Run palindrom check method.
    ispalindrome(*n_ptr, res);
    
    return 0;
}
