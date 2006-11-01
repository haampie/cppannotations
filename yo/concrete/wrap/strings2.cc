    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    #include "wrap1.h"

    class Strings
    {
        std::vector<std::string> d_vs;

        struct Context
        {
            std::ostream &out;
        };

        public:
            void uppercase(std::ostream &out)
            {
                Context context = {out};
                for_each(d_vs.begin(), d_vs.end(),
                    Wrap1<std::string, Context>(&xform, context));
            }

        private:
            static void xform(std::string &str, Context &context)
            {
                context.out << str << " ";
                transform(str.begin(), str.end(), str.begin(), toupper);
                context.out << str << std::endl;
            }
    };

    using namespace std;

    int main()
    {
        Strings s;

        s.uppercase(cout);
    }