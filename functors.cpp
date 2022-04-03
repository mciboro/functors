#include <iostream>
#include <functional>
#include <inttypes.h>

void execute_operation(std::string &data, uint32_t data_len, std::function<void (std::string&, uint32_t)> func)
{
    func(data, data_len);
}

void capitalize_letters(std::string &string, uint32_t string_len)
{
    for(int i = 0; i < (string_len / sizeof(char) - 1); i++)
    {
        if(string[i] > 96)
            string[i] -= 32;    
    }
}

int main()
{
    std::string text = "sample Text";
    execute_operation(text, sizeof(text), &capitalize_letters);
    std::cout << text << std::endl;
}