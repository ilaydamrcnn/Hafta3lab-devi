#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//SORU6: L�STEDE EN UZUN �SM�N OLDU�U KAYDI YAZDIRAN FONKS�YON:

// ��renci bilgileri tan�mlamalar�:
struct Student {
    int studentNumber;
    char name[50];
    int age;
    struct Student *next;
};

// Ba�l� liste �zerinde dola�arak en uzun ismi bulan fonksiyon
void findLongestName(struct Student *head) {
    struct Student *current = head;
    int maxLength = 0;
    char *longestName;

    while (current != NULL) {
        if (strlen(current->name) > maxLength) {
            maxLength = strlen(current->name);
            longestName = current->name;
        }
        current = current->next;
    }

    // En uzun isme sahip kayd� yazd�r
    printf("En uzun isme sahip kay�t: %s\n", longestName);
}

// Ba�l� liste �rne�i olu�turur:
struct Student* createSampleLinkedList() {
    struct Student *head = NULL;
    struct Student *second = NULL;
    struct Student *third = NULL;

    // Bellekte yer ayr�l�r:
    head = (struct Student *)malloc(sizeof(struct Student));
    second = (struct Student *)malloc(sizeof(struct Student));
    third = (struct Student *)malloc(sizeof(struct Student));

    // Veri atamas� yapar:
    head->studentNumber = 1;
    strcpy(head->name, "Ahmet");
    head->age = 20;
    head->next = second;

    second->studentNumber = 2;
    strcpy(second->name, "Mehmet");
    second->age = 21;
    second->next = third;

    third->studentNumber = 3;
    strcpy(third->name, "Abdullah");
    third->age = 22;
    third->next = NULL;

    // En uzun ismi bulan fonksiyonu �a��r
    findLongestName(head);

    return head;
}

// Ana fonksiyon
int main() {
    // �rnek ba�l� listeyi olu�tur
    struct Student *list = createSampleLinkedList();

    // Belle�i serbest b�rak
    free(list);
    
    return 0;
}

