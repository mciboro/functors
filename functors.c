#include <stdio.h>
#include <inttypes.h>

void execute_operation(void * data, uint32_t data_len, void (*func) (void *, uint32_t))
{
    func(data, data_len);
}

void capitalize_letters(void * string, uint32_t string_len)
{
    for(int i = 0; i < (string_len / sizeof(char) - 1); i++)
    {
        if(*(char *)(string + i) > 96)
            *(char *)(string + i) -= 32;    
    }
}

int main()
{
    char text[] = "sample Text";
    execute_operation(text, sizeof(text), &capitalize_letters);
    printf("%s\n", text);
}