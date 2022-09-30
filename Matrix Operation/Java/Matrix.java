package Java;

import java.util.Random;
import java.lang.Math;

public class Matrix {
    private int[][] matrix;
    private int columns;
    private int rows;

    public Matrix (int col,int row){
        Random random = new Random();
        this.columns = col;
        this.rows = row;
        matrix = new int[this.rows][this.columns];
        for (int i = 0; i < this.rows; i++){
            for (int j = 0; j < this.columns; j++){
                matrix[i][j] = random.nextInt(9) + 1;
            }
        }
    }

    public void clearMatrix(){
        for (int i = 0; i < this.rows; i++){
            for (int j = 0; j < this.columns; j++){
                matrix[i][j] = 0;
            }
        }
    }

    public void printMatrix(){
        for (int i = 0; i < this.rows; i++){
            for (int j = 0; j < this.columns; j++){
                System.out.print(matrix[i][j]+"\t");
            }
            System.out.println();
        }
    }
    public Matrix multMatrix(Matrix m1, Matrix m2){
        Matrix m = new Matrix(m1.getColumns(),m2.getRows());
        m.clearMatrix();
        for (int i = 0; i < m1.getRows(); i++) {
            for (int j = 0; j < m1.getColumns(); j++) {
                for (int k = 0; k < m2.getRows(); k++) {
                    for (int l = 0; l < m2.getColumns(); l++) {
                        if (j == k) {
                            m.setData(j, i, m.getData(j, i) + (m1.getData(k, l) * m2.getData(l, i)));
                        }
                    }
                }
            }
        }
        return m;
    }

    public Matrix redim(Matrix m){
        int newSize;
        if((m.getColumns()!=Math.pow(2,Math.ceil(Math.log(m.getColumns())/Math.log(2))))||(m.getRows()!=Math.pow(2,Math.ceil(Math.log(m.getRows())/Math.log(2))))){
            if(m.getColumns()>m.getRows()){
                newSize = (int)Math.round(Math.pow(2,Math.ceil(Math.log(m.getColumns())/Math.log(2))));
            } else {
                newSize = (int)Math.round(Math.pow(2,Math.ceil(Math.log(m.getRows())/Math.log(2))));
            }
            // System.out.println("NSize: "+newSize);
            Matrix auxM = new Matrix(newSize,newSize);
            for (int i = 0; i < newSize; i++){
                for (int j = 0; j < newSize; j++){
                    if((i<m.getRows())&&(j<m.getColumns())){
                        auxM.setData(i,j,m.getData(i,j));
                    } else {
                        auxM.setData(i,j,0);
                    }
                }
            }
            return auxM;
        } else {
            return m;
        }
    }

    public int getColumns() {
        return columns;
    }

    public int getRows() {
        return rows;
    }

    public int getData(int col, int row) {
        return matrix[col][row];
    }

    public void setData(int col, int row, int data) {
        matrix[col][row] = data;
    }
}