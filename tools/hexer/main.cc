#include <iostream>
#include "Parser.h"

int
main()
{
    std::cout << "Hexer!\n" << std::endl;
    auto parser = new Parser();

    std::string fetched;
    while (std::cin >> fetched)
    {
        parser->push(fetched);   
    }

    auto parsed = parser->flush();
    auto len = parsed.size();
    for (int i = 0; i < len; i++)
        std::cout << i << " " << parsed[i]->prettyPrint() << std::endl;

    delete parser;
    return 0;
}