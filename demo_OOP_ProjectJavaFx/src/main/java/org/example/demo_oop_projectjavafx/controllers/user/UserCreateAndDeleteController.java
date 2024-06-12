package org.example.demo_oop_projectjavafx.controllers.user;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import vote.laws.Laws;
import java.io.*;
import java.util.*;
import javafx.scene.control.*;
import vote.laws.type.*;
import javafx.collections.*;


public class UserCreateAndDeleteController {
    private static final String VOTE_FILE_PATH = "src/main/resources/org/example/demo_oop_projectjavafx/data-base/vote-list.txt";
    public ListView<String> vote_list;
    private final List<Laws> lawList = new ArrayList<>();

    @FXML
    public TextField create_need;
    @FXML
    public TextField lawTitle;
    @FXML
    public ChoiceBox<String> create_type;

    public void initialize() {
        scanVoteList();
    }

    public void scanVoteList() {
        lawList.clear();
        ObservableList<String> items = FXCollections.observableArrayList();

        try (BufferedReader reader = new BufferedReader(new FileReader(VOTE_FILE_PATH))) {
            String line;
            while ((line = reader.readLine()) != null) {
                Laws law = parseLaw(line);
                if (law != null) {
                    lawList.add(law);
                    if(Objects.equals(law.getResult(), "y")){
                        items.add(law.getName() + ", " + law.getType() + ", " + "Accepted");
                    }else if(Objects.equals(law.getResult(), "n")) {
                        items.add(law.getName() + ", " + law.getType() + ", " + "Rejected");
                    }else if(Objects.equals(law.getResult(), "0")){
                        items.add(law.getName() + ", " + law.getType() + ", " + "In the process");
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        vote_list.setItems(items);
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
    protected void handleDeleteObjectInList(ActionEvent event) {
        int selectedIndex = vote_list.getSelectionModel().getSelectedIndex();
        if (selectedIndex >= 0) {
            lawList.remove(selectedIndex);

            try {
                List<String> lines = new ArrayList<>();
                try (BufferedReader reader = new BufferedReader(new FileReader(VOTE_FILE_PATH))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        lines.add(line);
                    }
                }
                lines.remove(selectedIndex);

                try (BufferedWriter writer = new BufferedWriter(new FileWriter(VOTE_FILE_PATH))) {
                    for (String line : lines) {
                        writer.write(line);
                        writer.newLine();
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            scanVoteList();
        } else {
            Alert alert = new Alert(Alert.AlertType.WARNING);
            alert.setTitle("No selection");
            alert.setHeaderText("No law selected");
            alert.setContentText("Please select a law in the list to delete.");
            alert.showAndWait();
        }
    }
    @FXML
    protected void handleCreateObjectInList(ActionEvent event){
        String createNeed = create_need.getText();
        String lawTitleValue = lawTitle.getText();
        String createTypeValue = create_type.getValue();

        if (createNeed.isEmpty() || lawTitleValue.isEmpty() || createTypeValue == null) {
            showErrorAlert("Please,fill all blanks");
            return;
        }
        String record="";
        switch (createTypeValue) {
            case "Military" -> record = String.format("0;%s;0/0;%s;%s", createNeed, lawTitleValue, "M");
            case "Education" -> record = String.format("0;%s;0/0;%s;%s", createNeed, lawTitleValue, "E");
            case "Agricultural" -> record = String.format("0;%s;0/0;%s;%s", createNeed, lawTitleValue, "A");
            default -> System.out.println("Err with write new data into the file");
        }

        try (BufferedWriter writer = new BufferedWriter(new FileWriter("src/main/resources/org/example/demo_oop_projectjavafx/data-base/vote-list.txt", true))) {
            writer.newLine();
            writer.write(record);
            System.out.println("Vote created successfully.");
        } catch (IOException e) {
            System.out.println("Error with creating new Vote file: " + e.getMessage());
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
