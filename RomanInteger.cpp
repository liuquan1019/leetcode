string intToRoman(int num) {
    string table[] = {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV"
,"I"};
    int   values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string result;
    for(int iter = 0; iter < 13;)
    {
        if(num >= values[iter])
        {
            result += table[iter];
            num -= values[iter];
        }
        else
            ++iter;
    }
    return result;
}

int romanToInt(string s) {
    int result = 0;
    map<char, int> lookup;
    lookup['I'] = 1; lookup['V'] = 5; lookup['X'] = 10; lookup['L'] = 50;
lookup['C'] = 100; lookup['D'] = 500; lookup['M'] = 1000;
    for(int i = 0; i < s.size() -1; i++)
    {
        if(lookup[s[i]] < lookup[s[i+1]])
            result -= lookup[s[i]];
        else
            result += lookup[s[i]];
    }
    result += lookup[s[s.size()-1]];
    return result;
}