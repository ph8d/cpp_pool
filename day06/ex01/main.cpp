
#include <iostream>

typedef struct s_Data {
    std::string s1;
    int n;
    std::string s2;
} Data;

Data * deserialize(void * raw) {
    Data *data = new Data;
    char strBuff[8];
    char intBuff[4];

    for (int i = 0; i != 8; i++) {
        strBuff[i] = (reinterpret_cast<char *>(raw)[i]);
    }

    data->s1.assign(strBuff, 8);

    for (int i = 0; i != 4; i++) {
        intBuff[i] = (reinterpret_cast<char *>(raw)[i + 8]);
    }

    data->n = *(reinterpret_cast<int *>(intBuff));

    for (int i = 0; i != 8; i++) {
        strBuff[i] = (reinterpret_cast<char *>(raw)[i + 12]);
    }

    data->s2.assign(strBuff, 8);
    return data;
}

void * serialize(void) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    char* ptr = new char[20];

    for (int i = 0; i != 8; i++) {
        ptr[i] = alphanum[rand() % 62];
    }

    *(reinterpret_cast<int *>(ptr + 8)) = rand() % 1000;

    for (int i = 12; i != 20; i++) {
        ptr[i] = alphanum[rand() % 62];
    }

    return ptr;
}

int main(void) {
    srand(clock());

    void * serialized = serialize();
    Data *data = deserialize(serialized);

    std::cout << "s1:   " + data->s1 << std::endl;
    std::cout << "s2:   " + data->s2 << std::endl;
    std::cout << "n:    " << data->n << std::endl;

    return 0;
}