package org.example.demo_oop_projectjavafx.controllers.user;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ListView;
import javafx.scene.text.Text;
import vote.laws.Laws;
import java.io.*;
import java.util.*;
import operation.MultithreadingClass;

import vote.laws.type.*;
import javafx.collections.*;

public class UserVoteController {
    private static final String VOTE_FILE_PATH = "src/main/resources/org/example/demo_oop_projectjavafx/data-base/vote-list.txt";
    public Text numberYes;
    public Text numberNo;
    private int totalYes = 0;
    private int totalNo = 0;
    @FXML
    private ListView<String> vote_list;
    @FXML
    private ListView<String> history_list;
    private MultithreadingClass multithreading;

    @FXML
    public void initialize() {
        scanVoteList();
        scanHistoryList();

        multithreading = new MultithreadingClass(0, 0, this);
        Thread thread = new Thread(multithreading);
        thread.start();

        initCounters();
    }

    public void scanVoteList() {
        ObservableList<String> items = FXCollections.observableArrayList();

        try (BufferedReader reader = new BufferedReader(new FileReader(VOTE_FILE_PATH))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Laws law = parseLaw(line);
                if (law != null) {
                    if (Objects.equals(law.getResult(), "y")) {
                        continue;
                    } else if (Objects.equals(law.getResult(), "n")) {
                        continue;
                    } else if (Objects.equals(law.getResult(), "0")) {
                        items.add(law.getName() + ", " + law.getType() + ", " + "In the process");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        vote_list.setItems(items);
    }
    public void scanHistoryList() {
        ObservableList<String> items = FXCollections.observableArrayList();

        try (BufferedReader reader = new BufferedReader(new FileReader(VOTE_FILE_PATH))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Laws law = parseLaw(line);
                if (law != null) {
                    if (Objects.equals(law.getResult(), "y")) {
                        items.add(law.getName() + ", " + law.getType() + ", " + "Accepted");
                    } else if (Objects.equals(law.getResult(), "n")) {
                        items.add(law.getName() + ", " + law.getType() + ", " + "Rejected");
                    } else if (Objects.equals(law.getResult(), "0")) {
                        continue;
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        history_list.setItems(items);
    }
    public void initCounters(){
        updateCounters();
        numberYes.setText(Integer.toString(totalYes));
        numberNo.setText(Integer.toString(totalNo));
    }

    private void updateCounters() {
        totalYes = multithreading.getCountYes();
        totalNo = multithreading.getCountNo();
    }

    private Laws createLawObject(String need, String title, String type,String result,int yesCount,int noCount) {
        int votesNeeded = Integer.parseInt(need);

        switch (type) {
            case "A":
                return new Agricultural(title, votesNeeded, type,result,yesCount,noCount);
            case "E":
                return new Education(title, votesNeeded, type,result,yesCount,noCount);
            case "M":
                return new Military(title, votesNeeded, type,result,yesCount,noCount);
            default:
                throw new IllegalArgumentException("Invalid law type: " + type);
        }
    }
    private Laws parseLaw(String line) {
        String[] parts = line.split(";");
        if (parts.length == 5) {
            String name = parts[3];
            int votesNeeded = Integer.parseInt(parts[1]);
            String type = parts[4];
            String result = parts[0];
            String statisticStr = parts[2];
            String[] statisticParts = statisticStr.split("/");
            if (statisticParts.length == 2) {
                int yesCount = Integer.parseInt(statisticParts[0]);
                int noCount = Integer.parseInt(statisticParts[1]);
                return createLawObject(Integer.toString(votesNeeded), name, type, result, yesCount, noCount);
            }
        }
        return null;
    }


    @FXML
    protected void buttonActionYes(ActionEvent event) {
        String selectedLaw = vote_list.getSelectionModel().getSelectedItem();
        if (selectedLaw != null) {
            multithreading.increaseCountYes();
            updateCounters();
            numberYes.setText(Integer.toString(totalYes));
        } else {
            showErrorAlert("Please select law before!");
        }
    }

    @FXML
    protected void buttonActionNo(ActionEvent event) {
        String selectedLaw = vote_list.getSelectionModel().getSelectedItem();
        if (selectedLaw != null) {
            multithreading.increaseCountNo();
            updateCounters();
            numberNo.setText(Integer.toString(totalNo));
        } else {
            showErrorAlert("Please select law before!");
        }
    }
    @FXML
    protected void buttonActionEndVote(ActionEvent event) {
        String selectedLaw = vote_list.getSelectionModel().getSelectedItem();
        if (selectedLaw != null) {
            editFileWithVoting(selectedLaw);
            vote_list.getItems().remove(selectedLaw);

            multithreading.resetCounters();
            updateCounters();
            numberYes.setText(Integer.toString(totalYes));
            numberNo.setText(Integer.toString(totalNo));
        } else {
            showErrorAlert("Please select law before!");
        }
    }


    public void editFileWithVoting(String string) {
        String[] elements = string.split(",");
        String lawName = elements[0].trim();
        String newResult = "0";

        try (BufferedReader reader = new BufferedReader(new FileReader(VOTE_FILE_PATH))) {
            List<String> lines = new ArrayList<>();
            String line;

            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                String currentLawName = parts[3].trim();

                if (currentLawName.equals(lawName)) {
                    String statisticStr = parts[2].trim();
                    String[] statisticParts = statisticStr.split("/");
                    int yesCount = Integer.parseInt(statisticParts[0]);
                    int noCount = Integer.parseInt(statisticParts[1]);

                    int newYesCount = yesCount + totalYes;
                    int newNoCount = noCount + totalNo;

                    if (newYesCount > newNoCount) {
                        newResult = "y";
                    } else {
                        newResult = "n";
                    }

                    parts[0] = newResult;
                    parts[2] = newYesCount + "/" + newNoCount;
                    line = String.join(";", parts);

                }
                lines.add(line);
            }

            try (BufferedWriter writer = new BufferedWriter(new FileWriter(VOTE_FILE_PATH))) {
                for (String modifiedLine : lines) {
                    writer.write(modifiedLine);
                    writer.newLine();
                }
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    private void showErrorAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
