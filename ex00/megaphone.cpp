#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    int i = 1;
    int j = 0;
    int var;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }

    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            var = std::toupper(argv[i][j]);
            std::cout << (char)var;
            j++;
        }

        if (i < argc - 1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;

    return (0);
}

