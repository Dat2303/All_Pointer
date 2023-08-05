#include <stdio.h>
#include <stdlib.h>

int dong, cot;

void Nhap(void)
{
    printf("dong: ");
    scanf("%d", &dong);
    printf("cot: ");
    scanf("%d", &cot);
}

void NhapMang2Chieu(int **pptr, int dong, int cot)
{
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            printf("pptr[%d][%d]: ", i, j);
            scanf("%d", &pptr[i][j]);
        }
        printf("\n");
    }
}

void XuatMang2Chieu(int **pptr, int dong, int cot)
{
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            printf("%d ", pptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void Xoa(int **pptr, int *dong, int cot)
{
    int hangXoa;
    printf("Nhap hang can xoa: ");
    scanf("%d", &hangXoa);

    (*dong)--;
    for(int i=hangXoa; i<*dong; i++)
    {
        for(int j=0; j<cot; j++)
        {
            pptr[i][j] = pptr[i+1][j];
        }
    }
}

int** Them(int **pptr, int *dong, int cot)
{
    int hangThem;
    int **pptrNew = (int**)calloc(*dong+1,sizeof(int*));
    for(int i=0; i<cot; i++)
    {
        pptrNew[i] = (int*)calloc(cot,sizeof(int));
    }

    do
    {
        printf("Nhap hang can them: ");
        scanf("%d", &hangThem);
    } while(hangThem>*dong);

    for(int i=0; i<hangThem; i++)
    {
        for(int j=0; j<cot; j++)
        {
            pptrNew[i][j] = pptr[i][j];
        }
    }

    for(int j=0; j<cot; j++)
    {
        printf("Nhap phan tu pptrNew[%d][%d]: ",hangThem, j);
        scanf("%d", &pptrNew[hangThem][j]);
    }

    for(int i=hangThem+1; i<*dong+1; i++)
    {
        for(int j=0; j<cot; j++)
        {
            pptrNew[i][j] = pptr[i-1][j];
        }
    }

    *dong +=1;
    for(int i=0; i<cot; i++)
    {
        free(pptr[i]);
    }
    free(pptr);

    return pptrNew;
}

int main()
{
    Nhap();

    int **pptr = (int**)calloc(dong,sizeof(int*));
    for(int i=0; i<cot; i++)
    {
        pptr[i] = (int*)calloc(cot,sizeof(int));
    }

    NhapMang2Chieu(pptr, dong, cot);
    XuatMang2Chieu(pptr, dong, cot);

    Xoa(pptr, &dong, cot);
    XuatMang2Chieu(pptr, dong, cot);

    pptr = Them(pptr, &dong, cot);
    XuatMang2Chieu(pptr, dong, cot);

    for(int i=0; i<cot; i++)
    {
        free(pptr[i]);
    }
    free(pptr);
    return 0;
}
