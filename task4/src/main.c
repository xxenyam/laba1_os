#include <stdio.h>
#include "arraylist.h"

void print_menu() {
    printf("\n--- МЕНЮ ---\n");
    printf("1. Вибрати довжину масиву і заповнити його\n");
    printf("2. Додати елемент в кінець списку\n");
    printf("3. Вставити елемент за індексом\n");
    printf("4. Видалити елемент за індексом\n");
    printf("5. Змінити значення елемента\n");
    printf("6. Отримати елемент за індексом\n");
    printf("7. Вивести список\n");
    printf("8. Вийти з програми\n");
}

void fill_list(ArrayList *list) {
    int n, item;
    printf("Введіть кількість елементів, яку хочете додати: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &item);
        add(list, item);
    }
}

void print_list(ArrayList *list) {
    if (size(list) == 0) {
        printf("Список порожній.\n");
        return;
    }
    printf("Список елементів: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n");
}

int main() {
    ArrayList *list = NULL;
    int choice, index, item, capacity;

    do {
        print_menu();
        printf("Виберіть дію: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (list != NULL) {
                    free_list(list);  // Звільняємо попередній список, якщо був
                }
                printf("Введіть початкову довжину масиву: ");
                scanf("%d", &capacity);
                list = create_list(capacity);
                fill_list(list);
                break;
            case 2:
                if (list == NULL) {
                    printf("Спочатку створіть список.\n");
                } else {
                    printf("Введіть елемент для додавання: ");
                    scanf("%d", &item);
                    add(list, item);
                }
                break;
            case 3:
                if (list == NULL) {
                    printf("Спочатку створіть список.\n");
                } else {
                    printf("Введіть індекс для вставки: ");
                    scanf("%d", &index);
                    printf("Введіть елемент: ");
                    scanf("%d", &item);
                    insert(list, index, item);
                }
                break;
            case 4:
                if (list == NULL) {
                    printf("Спочатку створіть список.\n");
                } else {
                    printf("Введіть індекс для видалення: ");
                    scanf("%d", &index);
                    remove_item(list, index);
                }
                break;
            case 5:
                if (list == NULL) {
                    printf("Спочатку створіть список.\n");
                } else {
                    printf("Введіть індекс для зміни: ");
                    scanf("%d", &index);
                    printf("Введіть нове значення: ");
                    scanf("%d", &item);
                    set(list, index, item);
                }
                break;
            case 6:
                if (list == NULL) {
                    printf("Спочатку створіть список.\n");
                } else {
                    printf("Введіть індекс для отримання елемента: ");
                    scanf("%d", &index);
                    item = get(list, index);
                    if (item != -1) {
                        printf("Елемент на індексі %d: %d\n", index, item);
                    }
                }
                break;
            case 7:
                if (list == NULL) {
                    printf("Спочатку створіть список.\n");
                } else {
                    print_list(list);
                }
                break;
            case 8:
                printf("Вихід з програми.\n");
                break;
            default:
                printf("Невірний вибір. Спробуйте ще раз.\n");
        }
    } while (choice != 8);

    if (list != NULL) {
        free_list(list);  // Звільняємо пам'ять перед виходом
    }

    return 0;
}
