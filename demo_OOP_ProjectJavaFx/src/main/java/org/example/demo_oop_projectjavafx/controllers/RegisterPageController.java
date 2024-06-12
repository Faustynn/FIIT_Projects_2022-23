package org.example.demo_oop_projectjavafx.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextField;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class RegisterPageController {

    public TextField loginArea;
    public TextField passArea;
    public TextField nameArea;
    public TextField oldArea;
    public CheckBox ifAdmin;

    @FXML
    protected void RegisterButtonOnAction(ActionEvent event) throws IOException {
        if (isInputValid()) {
            AccountRegistration registration = new AccountRegistration();
            registration.registerAccount(() -> new User(loginArea.getText(), passArea.getText(), nameArea.getText(), Integer.parseInt(oldArea.getText())), ifAdmin.isSelected());
        } else {
            showErrorAlert("Please fill in all fields.");
        }
    }

    private boolean isInputValid() {
        return !loginArea.getText().isEmpty() && !passArea.getText().isEmpty() && !nameArea.getText().isEmpty() && !oldArea.getText().isEmpty();
    }

    private void showErrorAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private static void appendToFile(String filename, String data) throws IOException {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))) {
            writer.newLine();
            writer.write(data);
        }
    }

    private static class AccountRegistration {
        public void registerAccount(UserSupplier userSupplier, boolean isAdmin) throws IOException {
            User user = userSupplier.get();
            String data = user.getUsername() + ";" + user.getPassword() + ";" + user.getFullName() + ";" + user.getAge() + ";";
            if (isAdmin) {
                data += "99999;0";
                appendToFile("src/main/resources/org/example/demo_oop_projectjavafx/data-base/admin-list.txt", data);
            } else {
                data += "stringline";
                appendToFile("src/main/resources/org/example/demo_oop_projectjavafx/data-base/user-list.txt", data);
            }
        }
    }

    @FunctionalInterface
    private interface UserSupplier {
        User get();
    }

    private static class User {
        private String username;
        private String password;
        private String fullName;
        private int age;

        public User(String username, String password, String fullName, int age) {
            this.username = username;
            this.password = password;
            this.fullName = fullName;
            this.age = age;
        }

        public String getUsername() {
            return username;
        }

        public String getPassword() {
            return password;
        }

        public String getFullName() {
            return fullName;
        }

        public int getAge() {
            return age;
        }
    }
}
