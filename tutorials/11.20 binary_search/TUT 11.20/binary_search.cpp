#include <iostream>

int main();

int main()
{
    int guess_number{(1+255)/2};
    unsigned int quantity_guesses{1};
    bool not_guessed_yet{true};
    std::string user_response;
    int right{255}, left{1};

    while (quantity_guesses <= 99 && not_guessed_yet)
    {
        std::cout << "Is your number" << guess_number << "?" << std::endl;
        std::cin >> user_response;

        if (user_response == "Y")
        {
            not_guessed_yet = false;
            std::cout << "The computer has correctly guessed your number " << guess_number << " in " << quantity_guesses << " guesses." << std::endl;
        }
        else
        {
            if (user_response == "H")
            {
                left = guess_number + 1;
                guess_number = (right + left)/2;
            }
            else if (user_response == "L")
            {
                right = guess_number - 1;
                guess_number = (right + left)/2;
            }
        }
        ++quantity_guesses;
    }
}
