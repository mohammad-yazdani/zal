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
    for (auto instr : parsed)
        std::cout << instr->prettyPrint() << std::endl;

    delete parser;
    return 0;
}