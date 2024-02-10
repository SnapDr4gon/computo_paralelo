import java.util.Random;

class FillMatrixThread extends Thread {
    private int[][] matrix;
    private int row;
    private int cols;

    public FillMatrixThread(int[][] matrix, int row, int cols) {
        this.matrix = matrix;
        this.row = row;
        this.cols = cols;
    }

    public void run() {
        Random rand = new Random();
        for (int i = 0; i < cols; i++) {
            matrix[row][i] = rand.nextInt(100) + 1;
        }
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException {
        int[][] matrix = new int[3][3];

        Thread[] threads = new Thread[3];

        for (int i = 0; i < 3; i++) {
            threads[i] = new FillMatrixThread(matrix, i, 3);
            threads[i].start();
        }

        for (Thread thread : threads) {
            thread.join();
        }

        for (int[] row : matrix) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
