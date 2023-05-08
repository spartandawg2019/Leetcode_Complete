class Solution {
public:
    int myAtoi(string s) {
        // Initialize variables to hold the result, the current sign, and the current digit
        int result = 0;
        int sign = 1;
        int digit = 0;
        
        // Iterate through the input string
        for (int i = 0; i < s.size(); i++) {
            // If the current character is whitespace, continue to the next character
            if (s[i] == ' ') continue;
            
            // If the current character is a sign, set the sign accordingly and continue to the next character
            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            else if (s[i] == '+') {
                i++;
            }
            
            // Iterate through the remaining characters, converting them to integers and adding them to the result
            // until a non-digit character is reached
            while (i < s.size() && isdigit(s[i])) {
                digit = s[i] - '0';
                // Check if the resulting number will be out of the 32-bit signed integer range
                if (result > INT_MAX/10 || (result == INT_MAX/10 && digit > 7)) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                result = result*10 + digit;
                i++;
            }
            break;
        }
        
        // Return the final result with the appropriate sign
        return result*sign;
    }
};
