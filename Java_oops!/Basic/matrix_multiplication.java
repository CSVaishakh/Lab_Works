package com.vaishakh.Basic;

import java.util.Scanner;

public class matrix_multiplication{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int row1,col1,row2,col2,i,j,k;
		
		System.out.println("Enter the no.of rows in the  first matrix");
		row1 = in.nextInt();
		in.nextLine(); 
		
		System.out.println("Enter the no.of coloumns in the first matrix");
		col1 = in.nextInt();
		in.nextLine(); 
		
		System.out.println("Enter the no.of rows in the  second matrix");
		row2 = in.nextInt();
		in.nextLine(); 
		
		System.out.println("Enter the no.of coloumns in the second matrix");
		col2 = in.nextInt();
		in.nextLine();
		
		if (col1 != row2){
				System.out.println("Matrix multiplication is not possible as no of rows of first matrix is not equal to no of coloumns of second matrix ");
		}else{
			int[][] mat1 = new int[row1][col1];
			int[][] mat2 = new int[row2][col2];
			
			
			System.out.println("Enter the elements of the first matrix");
			for(i=0;i<row1;i++){
				for(j=0;j<col1;j++){
					mat1[i][j]=in.nextInt();
				}
			}
			System.out.println("The first matrix is");
			for(i=0;i<row1;i++){
				System.out.println();
				for(j=0;j<col1;j++){
					System.out.print(" "+mat1[i][j]+" ");
				}
			}
			
			System.out.println();
			
			System.out.println("Enter the elements of the second matrix");
			for(i=0;i<row2;i++){
				for(j=0;j<col2;j++){
					mat2[i][j]=in.nextInt();
				}
			}
			
			System.out.println("The second matrix is");
			for(i=0;i<row2;i++){
				System.out.println();
				for(j=0;j<col2;j++){
					System.out.print(" "+mat2[i][j]+" ");
				}
			}
			System.out.println();
			
			int[][] mat3 = new int[row1][col2];
			
			for(i=0;i<row1;i++){
				for(j=0;j<col2;j++){
					for (k=0;k<row2;k++){
						mat3[i][j] += mat1[i][k] * mat2[k][j];
					}
				}
			}
			
			System.out.println("The product of the two matrices is");
		for(i=0;i<row1;i++){
			System.out.println(); 
			for(j=0;j<col2;j++){
				System.out.print(" "+mat3[i][j]+" ");
			}
		}
		System.out.println();
		}
		
		
	}
}
