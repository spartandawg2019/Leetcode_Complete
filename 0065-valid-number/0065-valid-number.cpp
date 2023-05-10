class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();
        // skip leading whitespaces
        while (i < n && isspace(s[i])) i++;
        // check for a sign character
        if (s[i] == '+' || s[i] == '-') i++;
        // check for a decimal number or an integer
        bool isDecimal = false;
        int digits = 0;
        while (i < n && (isdigit(s[i]) || s[i] == '.')) {
            if (s[i] == '.') {
                if (isDecimal) return false; // more than one dot
                isDecimal = true;
            } else {
                digits++;
            }
            i++;
        }
        // check for an exponent value
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            // check for a sign character
            if (s[i] == '+' || s[i] == '-') i++;
            int expDigits = 0;
            while (i < n && isdigit(s[i])) {
                expDigits++;
                i++;
            }
            if (expDigits == 0) return false; // no digits after exponent
        }
        // skip trailing whitespaces
        while (i < n && isspace(s[i])) i++;
        return (digits > 0) && (i == n); // a valid number must have at least one digit and no extra characters
    }
};
