//checking if a string is palindrom or  not


string s;

bool is_palindrome(){
    int l = 0;
    h=s.size();

    while (h > l)
    {
        if (s[l++] != s[h--])
        {
            return 0; // not palindrome
        }
    }
    return 1; // palindrome 
}
