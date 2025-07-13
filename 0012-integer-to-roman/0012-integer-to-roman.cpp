class Solution {
public:
    // Converts an integer to a Roman numeral string.
    string intToRoman(int num) {
        // Arrays to map digit values to their respective Roman symbols.
        string thousands[4] = {"", "M", "MM", "MMM"};
        string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string units[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        // Extract digits based on decimal position
        int thousandPart = num / 1000;
        int hundredPart = (num / 100) % 10;
        int tenPart = (num / 10) % 10;
        int unitPart = num % 10;

        // Construct Roman numeral by concatenating strings from each part
        string result = "";

        // Add thousands place Roman numeral
        result += thousands[thousandPart];

        // Add hundreds place Roman numeral
        result += hundreds[hundredPart];

        // Add tens place Roman numeral
        result += tens[tenPart];

        // Add units place Roman numeral
        result += units[unitPart];

        return result;
    }
};

/*
Intuition and Algorithm:
- Roman numerals follow specific patterns where certain characters represent 1, 5, 10, etc.
- To convert an integer to Roman, break it into digit components: thousands, hundreds, tens, units.
- Each digit (0-9) has a fixed mapping in Roman numerals depending on its position.
- Predefine the Roman representation of each possible digit at each position.
- Combine the string representations in order (thousands to units).

Time Complexity:
- O(1) because the number of operations is constant regardless of input value (bounded by 3999).

Space Complexity:
- O(1) extra space, just uses fixed arrays and a result string.

Base Test Cases:
1. num = 3
   -> 3 = III
   Thousand: 0, Hundred: 0, Ten: 0, Unit: 3 → "III"
2. num = 58
   -> 50 + 8 = L + VIII = "LVIII"
   Thousand: 0, Hundred: 0, Ten: 5, Unit: 8 → "LVIII"
3. num = 1994
   -> 1000 + 900 + 90 + 4 = M + CM + XC + IV = "MCMXCIV"
   Thousand: 1, Hundred: 9, Ten: 9, Unit: 4 → "MCMXCIV"

Edge Test Cases:
1. num = 1
   → "I"
2. num = 3999
   → 3000 + 900 + 90 + 9 = MMM + CM + XC + IX = "MMMCMXCIX"
3. num = 1000
   → M
*/
