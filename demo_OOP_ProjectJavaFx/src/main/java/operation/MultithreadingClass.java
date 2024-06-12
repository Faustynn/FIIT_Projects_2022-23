package operation;

import javafx.application.Platform;
import org.example.demo_oop_projectjavafx.controllers.user.UserVoteController;

import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class MultithreadingClass implements Runnable {
    private int countYes;
    private int countNo;
    private Random random = new Random();
    private Object lock = new Object();
    private UserVoteController controller;

    public MultithreadingClass(int yes, int no, UserVoteController controller) {
        this.countYes = yes;
        this.countNo = no;
        this.controller = controller;
    }

    public void increaseCountYes() {
        synchronized (lock) {
            countYes++;
        }
    }

    public void increaseCountNo() {
        synchronized (lock) {
            countNo++;
        }
    }

    private void updateGUI() {
        Platform.runLater(() -> {
            controller.numberYes.setText(Integer.toString(countYes));
            controller.numberNo.setText(Integer.toString(countNo));
        });
    }

    @Override
    public void run() {
        StartVoting();
    }

    private void StartVoting() {
        Timer timerYes = new Timer();
        timerYes.schedule(new TimerTask() {
            @Override
            public void run() {
                if (random.nextDouble() < 0.5) {
                    increaseCountYes();
                    updateGUI();
                }
            }
        }, 0, 5000);

        Timer timerNo = new Timer();
        timerNo.schedule(new TimerTask() {
            @Override
            public void run() {
                if (random.nextDouble() < 0.25) {
                    increaseCountNo();
                    updateGUI();
                }
            }
        }, 0, 3000);
    }

    public int getCountYes() {
        synchronized (lock) {
            return countYes;
        }
    }

    public int getCountNo() {
        synchronized (lock) {
            return countNo;
        }
    }

    public void resetCounters() {
        countYes = 0;
        countNo = 0;
    }
}
