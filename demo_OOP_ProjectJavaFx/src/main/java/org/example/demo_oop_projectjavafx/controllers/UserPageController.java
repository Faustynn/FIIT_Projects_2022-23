package org.example.demo_oop_projectjavafx.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import org.example.demo_oop_projectjavafx.MainApplication;
import javafx.fxml.FXMLLoader;
import javafx.scene.*;

import java.io.IOException;

public class UserPageController {
    @FXML
    private Text welcomeText;
    private MainApplication mainApplication;

    public void initialize() {
        printHello();
    }

    public void printHello() {
        welcomeText.setText("Welcome dear User!");
    }

    @FXML
    protected void handleLogOutButtonAction(ActionEvent event) throws IOException {
        mainApplication.changeUserRole("main");
    }

    @FXML
    protected void ProfileButtonAction(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/user-fxml/user-profile.fxml"));
        Parent root = loader.load();
        Scene scene = new Scene(root);

        Stage stage = new Stage();
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    protected void CreateAndDeleteLawsButtonAction(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/user-fxml/user-create&delete.fxml"));
        Parent root = loader.load();
        Scene scene = new Scene(root);

        Stage stage = new Stage();
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    protected void LawsButtonAction(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/user-fxml/user-vote.fxml"));
        Parent root = loader.load();
        Scene scene = new Scene(root);

        Stage stage = new Stage();
        stage.setScene(scene);
        stage.show();
    }
}

