#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc cua mot phan tu trong danh sach lien ket doi
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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

    *cuoi = hienTai; // Luu lai con tro den phan tu cuoi cung
}

// Ham in danh sach lien ket doi (tu dau den cuoi)
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

// Ham duyet danh sach tu cuoi ve dau va in du lieu tung phan tu
void duyetNguocVaIn(Node* cuoi) {
    Node* hienTai = cuoi;
    while (hienTai != NULL) {
        printf("data: %d\n", hienTai->data);
        hienTai = hienTai->prev;
    }
}

// Ham main
int main() {
    Node* dau = NULL;
    Node* cuoi = NULL;
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    taoDanhSachLienKetDoi(&dau, &cuoi, n);
    printf("Danh sach lien ket doi: ");
    inDanhSach(dau);

    printf("\nDuyet nguoc va in du lieu:\n");
    duyetNguocVaIn(cuoi);

    return 0;
}
