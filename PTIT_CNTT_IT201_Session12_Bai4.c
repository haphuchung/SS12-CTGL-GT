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

// Xoa phan tu cuoi cung trong danh sach
void xoaCuoi(Node** dau, Node** cuoi) {
    if (*cuoi == NULL) return; // Danh sach rong

    Node* nutCanXoa = *cuoi;

    if (nutCanXoa->prev != NULL) {
        *cuoi = nutCanXoa->prev;
        (*cuoi)->next = NULL;
    } else {
        // Danh sach chi co 1 phan tu
        *dau = NULL;
        *cuoi = NULL;
    }

    free(nutCanXoa);
}

// Ham main
int main() {
    Node* dau = NULL;
    Node* cuoi = NULL;
    int n;

    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    taoDanhSachLienKetDoi(&dau, &cuoi, n);

    printf("Danh sach truoc khi xoa: ");
    inDanhSach(dau);

    xoaCuoi(&dau, &cuoi);

    printf("Danh sach sau khi xoa: ");
    inDanhSach(dau);

    return 0;
}
