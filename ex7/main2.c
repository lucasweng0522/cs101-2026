#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Books {
    int id;
    int price;
    char title[128];
} book_t;

int total_price(const book_t books[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += books[i].price;
    }
    return sum;
}

void list_books(const book_t books[], int n) {
    printf("%-4s | %-6s | %s\n", "Id", "Price", "Title");
    printf("-----+--------+--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d | %-6d | %s\n", books[i].id, books[i].price, books[i].title);
    }
}

int main(void) {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        perror("無法建立 Book.bin");
        return 1;
    }
    fwrite(books, sizeof(book_t), 6, fp);
    fclose(fp);

    list_books(books, 6);
    printf("\nTotal Price: %d\n", total_price(books, 6));

    return 0;
}
