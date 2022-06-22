struct answer {
    float number[2];
};

struct params {
    float number[500000];
};

program PROG {
 version VERSAO {
    answer sort(params) = 1;
 } = 1000;
} = 55555555;
