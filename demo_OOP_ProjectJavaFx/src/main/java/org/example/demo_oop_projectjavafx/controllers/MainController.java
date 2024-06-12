package org.example.demo_oop_projectjavafx.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import operation.AccountSerializer;
import operation.PasswordExcep.InvalidPasswordException;
import org.example.demo_oop_projectjavafx.MainApplication;
import operation.LoginObserver;
import users.*;
import java.io.IOException;

public class MainController {
    private static final String ACCOUNT_FILE_PATH = "src/main/resources/org/example/demo_oop_projectjavafx/serializated-data/account_data.dat";
    @FXML
    private LoginObserver loginObserver = new LoginObserver();
    @FXML
    private TextField usernameField;
    @FXML
    private PasswordField passwordField;
    private MainApplication mainApplication;

    @FXML
    protected void handleLoginButtonAction(ActionEvent event) throws IOException {
        String username = usernameField.getText();
        String password = passwordField.getText();

        try {
            UniversalAccount universalAccount = loginObserver.observeLogin(username, password);
            De_serAccount account = new De_serAccount();
            account.setUsername(universalAccount.getUsername());
            account.setPassword(universalAccount.getPassword());
            account.setFirstName(universalAccount.getFirstName());
            account.setLastName(universalAccount.getLastName());
            account.setAge(universalAccount.getAge());
            account.setId(universalAccount.getId());
            account.setScore(universalAccount.getScore());
            try {
                AccountSerializer.saveUniversalAccount(account, ACCOUNT_FILE_PATH);
                System.out.println("Data was sucsecful serialized");
            } catch (IOException e) {
                System.err.println("Error serialize data " + e.getMessage());
            }
            if (universalAccount instanceof User) {
                mainApplication.changeUserRole("user");
            } else if (universalAccount instanceof Admin) {
                mainApplication.changeUserRole("admin");
            } else {
                showErrorAlert("Unknown role");
            }
        } catch (InvalidPasswordException e) {
            showErrorAlert(e.getMessage());
        }
    }


    @FXML
    protected void handleRegisterButtonAction(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/register.fxml"));
        Parent root = loader.load();
        Scene scene = new Scene(root);

        Stage stage = new Stage();
        stage.setScene(scene);
        stage.show();

    }

    private void showErrorAlert(String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error");
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    public void setMainApplication(MainApplication mainApplication) {
        this.mainApplication = mainApplication;
    }}
