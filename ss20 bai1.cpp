#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char bookName[100];
    char author[50];
    long long price;
    char category[50];
} Book;

void inputBook(Book book[], int *n);
void printBook(Book book[], int n);
void addBook(Book book[], int *n);
void deleteBook(Book book[], int *n);
void updateBook(Book book[], int n);
void sortBook(Book book[], int n);
void findBook(Book book[], int n);

int main() {
    Book books[50];
    int n = 0;
    int choice;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang dan)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputBook(books, &n);
                break;
            case 2:
                printBook(books, n);
                break;
            case 3:
                addBook(books, &n);
                break;
            case 4:
                deleteBook(books, &n);
                break;
            case 5:
                updateBook(books, n);
                break;
            case 6:
                sortBook(books, n);
                break;
            case 7:
                findBook(books, n);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 8);

    return 0;
}

void inputBook(Book book[], int *n) {
    printf("Nhap so luong sach muon them: ");
    scanf("%d", n);
    getchar(); 
    for (int i = 0; i < *n; i++) {
        book[i].id = i + 1;
        printf("Moi ban nhap vao ten sach: ");
        fgets(book[i].bookName, 100, stdin);
        book[i].bookName[strcspn(book[i].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: ");
        fgets(book[i].author, 50, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: ");
        scanf("%lld", &book[i].price);
        getchar();
        printf("Moi ban nhap vao the loai: ");
        fgets(book[i].category, 50, stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
    }
}

void printBook(Book book[], int n) {
    printf("Danh sach cac cuon sach:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma sach: %d\n", book[i].id);
        printf("Ten sach: %s\n", book[i].bookName);
        printf("Gia tien: %lld\n", book[i].price);
        printf("Tac gia: %s\n", book[i].author);
        printf("The loai: %s\n", book[i].category);
        printf("\n");
    }
}

void addBook(Book book[], int *n) {
    getchar();
    book[*n].id = *n + 1;
    printf("Moi ban nhap vao ten sach: ");
    fgets(book[*n].bookName, 100, stdin);
    book[*n].bookName[strcspn(book[*n].bookName, "\n")] = '\0';
    printf("Moi ban nhap vao ten tac gia: ");
    fgets(book[*n].author, 50, stdin);
    book[*n].author[strcspn(book[*n].author, "\n")] = '\0';
    printf("Moi ban nhap vao gia tien: ");
    scanf("%lld", &book[*n].price);
    getchar();
    printf("Moi ban nhap vao the loai: ");
    fgets(book[*n].category, 50, stdin);
    book[*n].category[strcspn(book[*n].category, "\n")] = '\0';
    (*n)++;
}

void deleteBook(Book book[], int *n) {
    int id;
    printf("Moi ban nhap ma sach muon xoa: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (book[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sach voi ma %d.\n", id);
    } else {
        for (int i = index; i < *n - 1; i++) {
            book[i] = book[i + 1];
        }
        (*n)--;
    }
}

void updateBook(Book book[], int n) {
    int id;
    printf("Moi ban nhap ma sach muon cap nhat: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (book[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Khong tim thay sach voi ma %d.\n", id);
    } else {
        getchar(); 
        printf("Moi ban nhap vao ten sach: ");
        fgets(book[index].bookName, 100, stdin);
        book[index].bookName[strcspn(book[index].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: ");
        fgets(book[index].author, 50, stdin);
        book[index].author[strcspn(book[index].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: ");
        scanf("%lld", &book[index].price);
        getchar();
        printf("Moi ban nhap vao the loai: ");
        fgets(book[index].category, 50, stdin);
        book[index].category[strcspn(book[index].category, "\n")] = '\0';
    }
}

void sortBooks(Book book[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (book[i].price > book[j].price) {
                Book temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }
    printf("sau khi sap xep theo gia:\n");
    printBook(book, n);
}

void findBook(Book book[], int n) {
    char searchName[100];
    printf("Moi ban nhap ten sach muon tim: ");
    getchar(); 
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    int found = 0;
    printf("Ket qua tim kiem:\n");
    for (int i = 0; i < n; i++) {
        if (strstr(book[i].bookName, searchName) != NULL) {
            printf("Ma sach: %d\n", book[i].id);
            printf("Ten sach: %s\n", book[i].bookName);
            printf("Gia tien: %lld\n", book[i].price);
            printf("Tac gia: %s\n", book[i].author);
            printf("The loai: %s\n", book[i].category);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach nao co ten \"%s\".\n", searchName);
    }
}

