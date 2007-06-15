    #include <algorithm>
    #include <iostream>
    #include <string>
    #include <iterator>
    using namespace std;

    int main()
    {
        string words[] =
            { "kilo", "alpha", "lima", "mike", "alpha", "november", "alpha",
                "oscar", "alpha", "alpha", "papa", "quebec" };
        size_t const size = sizeof(words) / sizeof(string);

        replace(words, words + size, string("alpha"), string("ALPHA"));
        copy(words, words + size, ostream_iterator<string>(cout, " "));
        cout << endl;

        return 0;
    }
    /*
        Generated output:

        kilo ALPHA lima mike ALPHA november ALPHA oscar ALPHA ALPHA papa quebec
    */
