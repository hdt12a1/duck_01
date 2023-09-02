#include <iostream>

/*
typedef = reserved keyword used to create an additional name
for another data type
New indentifier for an existing type
help with readability and reduces typos 
*/
typedef std::string text_t;
/*
 * nowdays, more popular using "using" keyword
 * using text_t = std::string;
 */
int main(int argc, char const *argv[])
{
    text_t hello = "Hello Huynh Duc Tran";
    std::cout << hello << "\n";

    return 0;
}
