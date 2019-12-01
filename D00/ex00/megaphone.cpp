#include <cctype>
#include <iostream>

int     main(int argc, char **argv)
{
        int i = 1;
        int j = 0;

        if(argc > 1)
        {

            while (i < argc)
            {
                j = 0;
                while (argv[i][j])
                {
                    putchar(toupper(argv[i][j]));
                    j++;
                }
                i++;
            }
        }
        else
            {
                std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
            }
        std::cout << "\n";
    return (0);
}
