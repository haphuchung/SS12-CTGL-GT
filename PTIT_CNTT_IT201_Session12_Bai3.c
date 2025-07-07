#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc cua mot phan tu
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Tao mot phan tu moi
Node* taoPhanTu(int giaTri) {
    Node* nutMoi = (Node*)malloc(sizeof(Node));
    if (nutMoi == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    nutMoi->data = giaTri;
    nutMoi->next = NULL;
    nutMoi->prev = NULL;
    return nutMoi;
}

// Tao danh sach lien ket doi ban dau
void taoDanhSachLienKetDoi(Node** dau, Node** cuoi, int n) {
    if (n <= 0) return;

    int giaTri;
    printf("Nhap gia tri phan tu thu 1: ");
    scanf("%d", &giaTri);

    *dau = taoPhanTu(giaTri);
    Node* hienTai = *dau;

    for (int i = 2; i <= n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i);
        scanf("%d", &giaTri);

        Node* nutMoi = taoPhanTu(giaTri);
        hienTai->next = nutMoi;
        nutMoi->prev = hienTai;
        hienTai = nutMoi;
    }

    *cuoi = hienTai;
}

// In danh sach tu dau den cuoi
void inDanhSach(Node* dau) {
    Node* hienTai = dau;
    while (hienTai != NULL) {
        printf("%d", hienTai->data);
        if (hienTai->next != NULL)
            printf("<->");
        hienTai = hienTai->next;
    }
    printf("->NULL\n");
}

// Them phan tu moi vao cuoi danh sach
void themVaoCuoi(Node** cuoi) {
    int so;
    printf("Nhap mot so nguyen duong de them vao cuoi danh sach: ");
    scanf("%d", &so);

    Node* nutMoi = taoPhanTu(so);
    if (*cuoi != NULL) {
        (*cuoi)->next = nutMoi;
        nutMoi->prev = *cuoi;
        *cuoi = nutMoi;
    } else {
        // Neu danh sach ban dau rong
        *cuoi = nutMoi;
    }
}

// Ham main
int main() {
    Node* dau = NULL;
    Node* cuoi = NULL;
    int n;

    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    taoDanhSachLienKetDoi(&dau, &cuoi, n);

    printf("Danh sach truoc khi them: ");
    inDanhSach(dau);

    themVaoCuoi(&cuoi);

    printf("Danh sach sau khi them: ");
    inDanhSach(dau);

    return 0;
}
