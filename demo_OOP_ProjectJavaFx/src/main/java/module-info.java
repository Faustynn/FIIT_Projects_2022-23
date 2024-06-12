module org.example.demo_oop_projectjavafx {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.web;

    opens org.example.demo_oop_projectjavafx to javafx.fxml;
    exports org.example.demo_oop_projectjavafx;
    exports org.example.demo_oop_projectjavafx.controllers;
    exports org.example.demo_oop_projectjavafx.controllers.user to javafx.fxml;
    opens org.example.demo_oop_projectjavafx.controllers to javafx.fxml;
    opens org.example.demo_oop_projectjavafx.controllers.user to javafx.fxml;
}