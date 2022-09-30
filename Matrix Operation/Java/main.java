package Java;

public class main {
    public static void main(String[] args) {
        Matrix m1 = new Matrix(3, 3);
        Matrix m2 = new Matrix(1, 3);
        System.out.println("M1: ");
        m1.printMatrix();
        m1 = m1.redim(m1);
        System.out.println("\nM2: ");
        m2.printMatrix();
        m2 = m2.redim(m2);
        System.out.println("\nRedimed M1: ");
        m1.printMatrix();
        System.out.println("\nRedimed M2: ");
        m2.printMatrix();

        Matrix m3 = new Matrix(m1.getColumns(),m2.getRows());
        m3 = m3.multMatrix(m1,m2);
        System.out.println("\nM3 = (M1 * M2): ");
        m3.printMatrix();
    }
}
