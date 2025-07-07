#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc cua mot phan tu trong danh sach lien ket doi
typedef struct Node {
    int data;               // Du lieu kieu so nguyen
    struct Node* next;      // Con tro den phan tu tiep theo
    struct Node* prev;      // Con tro den phan tu truoc do
} Node;

// Ham tao mot phan tu moi
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

// Ham tao danh sach lien ket doi tu n phan tu
void taoDanhSachLienKetDoi(Node** dau, int n) {
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
}

// Ham in danh sach lien ket doi
void inDanhSach(Node* dau) {
    Node* hienTai = dau;
    while (hienTai != NULL) {
        printf("%d", hienTai->data);
        if (hienTai->next != NULL)
            printf(" <-> ");
        hienTai = hienTai->next;
    }
    printf(" -> NULL\n");
}

// Ham main de chay chuong trinh
int main() {
    Node* dau = NULL;
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    taoDanhSachLienKetDoi(&dau, n);
    printf("Danh sach lien ket doi: ");
    inDanhSach(dau);

    return 0;
}
