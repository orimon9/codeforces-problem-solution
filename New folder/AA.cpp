#include<bits/stdc++.h>

using namespace std;
std::string computeEncodedProductName(std::string nameString)
{
    int n = nameString.size();
    std::map<char, int> freq;

    for (char c : nameString)
    {
        freq[c]++;
    }

    std::string h, m;
    for (auto &[ch, count] : freq)
    {
        if (count % 2 == 1)
        {
            m += ch;
        }
        h += std::string(count / 2, ch);
    }
    std::sort(h.begin(), h.end());
    if (m.size() > 1)
    {
        return "";
    }
    std::string out = h + m + std::string(h.rbegin(), h.rend());
    return out;
}

int main()
{
    std::string nameString;
    std::cin >> nameString;
    std::string out = computeEncodedProductName(nameString);
    std::cout << out << std::endl;
    return 0;
}

