public class RunnableDemo {
    static class CounterRunnable implements Runnable {
        private String name;
        CounterRunnable(String name) { this.name = name; }
        @Override
        public void run() {
            for (int i = 1; i <= 3; i++) {
                System.out.printf("[%s] Count: %d\n", name, i);
                try { Thread.sleep(500); } catch (InterruptedException e) { e.printStackTrace(); }
            }
            System.out.printf("[%s] Finished!\n", name);
        }
    }
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(new CounterRunnable("Runnable-A"));
        Thread t2 = new Thread(new CounterRunnable("Runnable-B"));
        t1.start();
        t2.start();
        t1.join();
        t2.join();
        System.out.println("Main thread: all runnables finished.");
    }
}

