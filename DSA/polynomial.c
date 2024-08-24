#include<stdio.h>
struct polynomial{
    int coeff;
    int expo;
};

struct polynomial p1[10],p2[10],p3[10];

int main(){
    int n1,n2,i,j,k,max;
    printf("Enter the no of terms in first polynomial");
    scanf("%d",&n1);
    printf("Enter the terms\n");
    for(i=0;i<n1;i++){
        printf("Enter the coefficient");
        scanf("%d",&p1[i].coeff);
        printf("Enter the exponent");
        scanf("%d",&p1[i].expo);
    }
    printf("Enter the no of terms in second polynomial");
    scanf("%d",&n2);
    printf("Enter the terms\n");
    for(j=0;j<n2;j++){
        printf("Enter the coefficient");
        scanf("%d",&p2[j].coeff);
        printf("Enter the exponent");
        scanf("%d",&p2[j].expo);
    }
    i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if (p1[i].expo>p2[j].expo){
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            k++;   
        }
        if (p1[i].expo<p2[j].expo){
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;
            k++;   
        }
        if(p1[i].expo == p2[j].expo){    
            p3[k].coeff = p1[i].coeff+p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;   
        }
    }
    while(i<n1){
         p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;
            k++; 
    }
    while(j<n2){
        p3[k].coeff=p2[j].coeff;
        p3[k].expo=p2[j].expo;
        j++;
        k++; 
    }
    max = k;
    for(i=0;i<max;i++){
        printf(" %d^%d ",p3[i].coeff,p3[i].expo);
        if(i<max-1){
            printf(" + ");
        }
    }
    return 0;
}

