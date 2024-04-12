/*******************************************************
Matrix Determinant Calculator by Kensley Cadet

Works by taking in input from a text file
Layout of file must be as follows

N
1 2 ... N
.
.
.
1 2 ... N

Where N represents the dimensions of the N by N matrix
and 1 2 ... N represent individual elements in each row

*******************************************************/
import java.util.*;
import java.io.*;

public class matrixDet {
  public static void main(String[] args) throws Exception {

    
    File file = new File(args[0]);
    Scanner scan = new Scanner(file);

    int n = scan.nextInt();
    int [][] matrix = new int [n][n];

    try {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          matrix[i][j] = scan.nextInt();
        }
      }
  
      Matrix det = new Matrix(n, matrix);
      det.printDet();
    } catch (Exception e) {
      System.out.println("Please enter an n * n matrix next time");
      System.out.println("Determinants only exist for such matrices");
      System.out.println();
    }
    scan.close();
  }

}

class Matrix {
  private int n;
  private int [][] matrix;

  public Matrix (int n, int [][] matrix) {
    this.n = n;
    this.matrix = matrix;
  }
  
  public int determinant(int [][] mat, int s) {

    if (s == 2) {
      return twoMatrix(mat);
    }

    int [][] temp = new int [s - 1][s - 1];
    int det = 0;
    int index = 0;
    int neg = 1;

    while (index < s) {

      
      for (int i = 1, k = 0; i < s; i++, k++) {
        for (int j = 0, l = 0; j < s; j++) {
          if (j == index) continue;

          temp[k][l] = mat[i][j];
          l++;
        }
      }
      det += mat[0][index] * determinant(temp, s - 1) * neg;
      
      neg *= (-1);
      index++;
    }

    return det;
  } 
  public int twoMatrix(int [][] matrix) {
    return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
  }

  
  
  public void printDet() {
    int det = determinant(matrix, n);
    
    System.out.println();
    System.out.println("***************************************************");
    System.out.println();
    System.out.println("Corresponding matrix: ");
    System.out.println();
    printMatrix();
    System.out.println();
    System.out.println("The determinant of this " + n + " * " + n + " matrix is " + det);
    System.out.println();

    if (det == 0) System.out.println("Your matrix is not invertible!");
    else System.out.println("Your matrix is invertible!");
    System.out.println();
    System.out.println("***************************************************");
    System.out.println();
  }
  public void printMatrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(matrix[i][j] + " ");
      }
      System.out.println();
    }
  }
}