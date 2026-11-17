import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class PoolDemo {
    public static void main(String[] args) throws InterruptedException {
        ExecutorService pool = Executors.newFixedThreadPool(2);
        for (int i = 1; i <= 4; i++) {
            final int taskId = i;
            pool.submit(() -> {
                System.out.println("Task " + taskId + " running on thread " + Thread.currentThread().getName());
                try { Thread.sleep(500); } catch (InterruptedException e) { e.printStackTrace(); }
                System.out.println("Task " + taskId + " finished.");
            });
        }
        pool.shutdown();
        pool.awaitTermination(5, TimeUnit.SECONDS);
        System.out.println("Pool shut down.");
    }
}
