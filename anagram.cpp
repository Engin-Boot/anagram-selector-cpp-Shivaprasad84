#include "anagram.h"
#include <algorithm>
#define NO_OF_CHARS_ASCII 256

bool is_equal(int array1[], int array2[])
{
    for (int i = 0; i < NO_OF_CHARS_ASCII; i++)
    {
        if (array1[i] != array2[i]) return false;
    }
    return true;
}

std::string ToLowerAndRemoveSpaces(const std::string& word)
{
    std::string temp_word = word;
    std::transform(temp_word.begin(), temp_word.end(), temp_word.begin(), ::tolower);
    std::string modified_word = "";
    for (auto ch : temp_word)
        if (!isspace(ch))
            modified_word += ch;

    return modified_word;
}

bool Anagram::WordPairIsAnagram(const std::string& word1, const std::string& word2) {
    //Fill the correct implementation here

    std::string modified_word1 = ToLowerAndRemoveSpaces(word1);
    std::string modified_word2 = ToLowerAndRemoveSpaces(word2);

    if (modified_word1.length() != modified_word2.length()) return false;

    int letter_frequency_array1[NO_OF_CHARS_ASCII] = { 0 };
    int letter_frequency_array2[NO_OF_CHARS_ASCII] = { 0 };

    for (int i = 0; i < modified_word1.length(); i++)
    {
        letter_frequency_array1[modified_word1[i]]++;
        letter_frequency_array2[modified_word2[i]]++;
    }
    
    return is_equal(letter_frequency_array1, letter_frequency_array2);
}

std::vector<std::string> Anagram::SelectAnagrams(
    const std::string& word,
    const std::vector<std::string>& candidates) {
    //Fill the correct implementation here
    std::vector<std::string> selected_candidates;
    for (std::string candidate : candidates)
    {
        if (Anagram::WordPairIsAnagram(word, candidate)) selected_candidates.push_back(candidate);
    }
    return selected_candidates;
}
