class Solution {
public:
    bool isPalindrome(string str) {
        // Convert uppercase letters to lowercase
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (ch >= 'A' && ch <= 'Z')
                str[i] = ch - 'A' + 'a';
        }

        // Check for palindrome
        int start = 0;
        int end = str.length() - 1;
        while (start <= end) {
            char startChar = str[start];
            char endChar = str[end];
            
            // Skip non-alphanumeric characters
            if (!isalnum(startChar)) {
                start++;
            } else if (!isalnum(endChar)) {
                end--;
            } else {
                // Convert characters to lowercase for comparison
                if (tolower(startChar) != tolower(endChar)) {
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};

