#include<stdio.h>
int main(){
    int sp[10][10],tr[10][10],i,j,k=1,r,c;
    printf("Enter the no of rows of the sparse matrix: ");
    scanf("%d",&r);
    printf("Enter the no of coloumns of the sparse matrix: ");
    scanf("%d",&c);
    printf("Input Sparse Matrix: \n");
    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            scanf("%d",&sp[i][j]);
        }
    }

    printf("\nthe Sparse Matrix entered is:");
    for(i=0;i<r;i++){
        printf("\n");
        for (j=0;j<c;j++){
            printf(" %3d ",sp[i][j]);
        }
    }

    for(i=0;i<r;i++){
        for (j=0;j<c;j++){
            if(sp[i][j]!=0){
                tr[k][0]=i;
                tr[k][1]=j;
                tr[k][2]=sp[i][j];
                k++;
            }
        }
    }
    tr[0][0]=r;
    tr[0][1]=c;
    tr[0][2]=k-1;

    
    printf("\nTripplet representation is\n");
    for(i=0;i<=r;i++){
        printf("\n");
        for (j=0;j<3;j++){
            printf(" %3d ",tr[i][j]);
        }
    }
    return 0;
}