    #include <algorithm>
    #include <string>
    #include <iostream>
    #include <functional>
    using namespace std;

    int main()
    {
        string sarr[] =
            {
                "alpha", "bravo", "charley", "delta", "echo",
                "foxtrot", "golf", "hotel"
            };
        string *last = sarr + sizeof(sarr) / sizeof(string);
        bool result = binary_search(sarr, last, "foxtrot");

        cout << (result ? "found " : "didn't find ") << "foxtrot" << endl;

        reverse(sarr, last);                // reverse the order of elements
                                            // binary search now fails:
        result = binary_search(sarr, last, "foxtrot");
        cout << (result ? "found " : "didn't find ") << "foxtrot" << endl;
                                            // ok when using appropriate
                                            // comparator:
        result = binary_search(sarr, last, "foxtrot", greater<string>());
        cout << (result ? "found " : "didn't find ") << "foxtrot" << endl;

        return 0;
    }
    /*
        Generated output:

        found foxtrot
        didn't find foxtrot
        found foxtrot
    */
