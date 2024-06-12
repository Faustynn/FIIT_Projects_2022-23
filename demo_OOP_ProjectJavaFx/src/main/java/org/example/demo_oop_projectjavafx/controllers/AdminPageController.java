package org.example.demo_oop_projectjavafx.controllers;

import javafx.fxml.FXML;
import javafx.scene.text.Text;
import operation.WelcomeStrategy;
import org.example.demo_oop_projectjavafx.MainApplication;

public class AdminPageController implements WelcomeStrategy {

    @FXML
    private Text welcomeText2;
    private WelcomeStrategy welcomeStrategy2;
    private MainApplication mainApplication;

    @Override
    public String getWelcomeMessage() {
        return "Welcome dear Admin!";
    }

    public void initialize() {
        String role = "admin";
        setWelcomeStrategy(role);
        printHello();
        welcomeStrategy2.LoginCheck("Admin");
    }

    public void setWelcomeStrategy(String role) {
        welcomeStrategy2 = this;
    }

    public void printHello() {
        welcomeText2.setText(welcomeStrategy2.getWelcomeMessage());
    }
    public void setMainApplication(MainApplication mainApplication) {
        this.mainApplication = mainApplication;
    }
}
