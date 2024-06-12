package org.example.demo_oop_projectjavafx;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.stage.Stage;
import org.example.demo_oop_projectjavafx.controllers.MainController;

import java.io.IOException;
import java.util.Objects;

public class MainApplication extends Application {
    private Stage stage;

    @Override
    public void start(Stage primaryStage) throws IOException {
        this.stage = primaryStage;
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/main_page.fxml"));
        Parent root = loader.load();

        MainController controller = loader.getController();
        controller.setMainApplication(this);

        Scene scene = new Scene(root, 900, 500);
        stage.setScene(scene);
        stage.setTitle("DIA");
        Image icon = new Image(Objects.requireNonNull(getClass().getResourceAsStream("/org/example/demo_oop_projectjavafx/img/main_icon.png")));
        stage.getIcons().add(icon);
        stage.show();
    }


    public void changeUserRole(String newRole) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader();

        if ("admin".equals(newRole)) {
            fxmlLoader.setLocation(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/admin_page.fxml"));
        } else if ("user".equals(newRole)) {
            fxmlLoader.setLocation(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/user_page.fxml"));
        } else if("main".equals(newRole)){
            fxmlLoader.setLocation(getClass().getResource("/org/example/demo_oop_projectjavafx/FXML/main_page.fxml"));
        }

        Parent root = fxmlLoader.load();
        Scene scene = new Scene(root, 1500, 900);
        stage.setScene(scene);
        stage.show();
    }


    public static void main(String[] args) {
        launch();
    }
}