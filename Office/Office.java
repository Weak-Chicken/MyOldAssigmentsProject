/**
 *
 * @author Yucheng Xie ID:201138727 This program is designed for COMP104
 * assignment 1.
 */
public class Office {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Tray tray = new Tray("tray");
        Lounge lounge = new Lounge("lounge");
        Manager ManagerA = new Manager("Junior", 2, 19, 20, tray, lounge);
        Manager ManagerB = new Manager("Senior", 4, 9, 60, tray, lounge);
        Secretary SecretaryA = new Secretary("A", 1, 12, tray);
        Secretary SecretaryB = new Secretary("B", 2, 8, tray);
        Secretary SecretaryC = new Secretary("C", 6, 4, tray);
        Secretary SecretaryD = new Secretary("D", 6, 4, tray);
        SecretaryA.start();
        SecretaryB.start();
        SecretaryC.start();
        SecretaryD.start();
        ManagerA.start();
        ManagerB.start();
    }

}

class Tray {

    private String name;
    private int letterInTray = 0;

    public Tray(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public synchronized int getLetterInTray() {
        return this.letterInTray;
    }

    public synchronized void addALetter(String tempName1) {
        while (letterInTray >= 5) {
            try {
                System.out.println("Tray full. Secretary " + tempName1 + " must wait until a letter has been removed before adding another");
                wait();
            } catch (InterruptedException e) {
            }
        }
        letterInTray++;
        System.out.println("A letter has been added by Secretary " + tempName1 + " to the tray. Tray now contains " + letterInTray + " letters");
        notifyAll();
    }

    public synchronized void removeALetter(String tempName2, int tempWorkDone) {
        while (letterInTray <= 0) {
            try {
                System.out.println("Tray empty. " + tempName2 + " manager must wait until a letter has been put in the tray before trying to sign one");
                wait();
            } catch (InterruptedException e) {
            }
        }
        letterInTray--;
        System.out.println("A letter has been removed from the tray by " + tempName2 + " manager. Tray now contains " + letterInTray + " letters");
        System.out.println(tempName2 + " manager is signing letter " + tempWorkDone);
        notifyAll();
    }
}

class Lounge {

    private String name;
    private boolean occupied = false;

    public Lounge(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public synchronized boolean checkLounge() {
        return this.occupied;
    }

    public synchronized void releseLounge() {
        this.occupied = false;
        notify();
    }

    public synchronized void getLounge() {
        while (checkLounge()) {
            try {
                wait();
            } catch (InterruptedException e) {

            }
        }
        this.occupied = true;
    }

}

class Manager extends Thread {

    private String name;
    private int efficiency;
    private int everydayWork;
    private int restTime;
    private int maxWork = 7;
    private int workDone = 0;
    private Tray tray = null;
    private Lounge lounge = null;

    public Manager(String name, int efficiency, int everydayWork, int restTime, Tray tray, Lounge lounge) {
        this.name = name;
        this.efficiency = efficiency;
        this.everydayWork = everydayWork;
        this.restTime = restTime;
        this.tray = tray;
        this.lounge = lounge;
    }

    @Override
    public void run() {
        long timeTempWork = efficiency * 1000;
        long timeTempRest = restTime * 1000;
        while (workDone < everydayWork) {
            for (int i = 0; i < maxWork; i++) {
                if (workDone >= everydayWork) {
                    break;
                }
                workDone = workDone + 1;
                try {
                    tray.removeALetter(name, workDone);
                    Thread.currentThread().sleep(timeTempWork);
                } catch (InterruptedException e) {

                }
            }
            if (workDone >= everydayWork) {
                break;
            }
            System.out.println(name + " manager has signed " + workDone + " letters and feels overworked is going to Lounge to recover");
            if (lounge.checkLounge()) {
                System.out.println("Lounge is occupied; " + name + " manager must wait");
            }
            lounge.getLounge();
            System.out.println(name + " manager is in Lounge recovering");
            try {
                Thread.currentThread().sleep(timeTempRest);
                System.out.println(name + " manager has left the lounge");
                System.out.println(name + " manager has returned from break");
            } catch (InterruptedException e) {

            }
            lounge.releseLounge();
        }
        System.out.println(name + " manager has removed and signed full quota of letters and gone home (via pub)");

    }
}

class Secretary extends Thread {

    private String name;
    private int efficiency;
    private int everydayWork;
    private Tray tray = null;
    private int workDone = 0;

    public Secretary(String name, int efficiency, int everydayWork, Tray tray) {
        this.name = name;
        this.efficiency = efficiency;
        this.everydayWork = everydayWork;
        this.tray = tray;
    }

    @Override
    public void run() {
        while (workDone < everydayWork) {
            workDone = workDone + 1;
            long timeTemp = efficiency * 1000;
            System.out.println("Secretary " + name + " is typing letter " + workDone);
            try {
                Thread.currentThread().sleep(timeTemp);
                System.out.println("Secretary " + name + " has typed a letter, number now typed = " + workDone);
            } catch (InterruptedException e) {

            }
            tray.addALetter(name);
        }
        System.out.println("Secretary " + name + " has typed and filed all " + everydayWork + " letters and has now finished work for today");
    }
}
