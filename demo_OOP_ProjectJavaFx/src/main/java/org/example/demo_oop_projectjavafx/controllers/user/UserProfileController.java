package org.example.demo_oop_projectjavafx.controllers.user;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextArea;
import operation.AccountSerializer;
import users.De_serAccount;
import users.UniversalAccount;

import java.io.*;

public class UserProfileController {
    @FXML
    public TextArea loginTextArea;
    @FXML
    public TextArea passwordTextArea;
    @FXML
    public TextArea nameSurnameTextArea;
    @FXML
    public TextArea yearTextArea;
    @FXML
    public TextArea idTextArea;
    public boolean init=false;

    UniversalAccount loadedAccount;


    @FXML
    public void initialize() throws IOException, ClassNotFoundException {
        if(!init) {
            startProfileDetails();
            System.out.println("!"+loadedAccount.getUsername()+loadedAccount.getPassword());
            init = true;
        }
    }

    @FXML
    public void startProfileDetails() throws IOException, ClassNotFoundException {
        if(!init) {
            loadedAccount = AccountSerializer.loadUniversalAccount("src/main/resources/org/example/demo_oop_projectjavafx/serializated-data/account_data.dat");
        }

        loginTextArea.setText(loadedAccount.getUsername());
        passwordTextArea.setText(loadedAccount.getPassword());
        nameSurnameTextArea.setText(loadedAccount.getFirstName() + " " + loadedAccount.getLastName());
        yearTextArea.setText(String.valueOf(loadedAccount.getAge()));
        idTextArea.setText(String.valueOf(loadedAccount.getId()));
    }

    public void saveNewDataProfile() throws IOException, ClassNotFoundException {
        String fullName = nameSurnameTextArea.getText();
        String[] nameParts = fullName.split("\\s+");
        De_serAccount account = null;
        if (loadedAccount instanceof De_serAccount) {
            account = (De_serAccount) loadedAccount;
        } else {
            account = new De_serAccount();
        }

        account.setUsername(loginTextArea.getText());
        account.setPassword(passwordTextArea.getText());
        account.setFirstName(nameParts[0]);
        account.setLastName(nameParts[1]);
        account.setAge(Integer.parseInt(yearTextArea.getText()));
        account.setId(Integer.parseInt(idTextArea.getText()));
        account.setScore(0);

        AccountSerializer.saveUniversalAccount(account, "src/main/resources/org/example/demo_oop_projectjavafx/serializated-data/account_data.dat");

        write_file(loadedAccount.getUsername(), loadedAccount.getPassword(), account);
        loadedAccount.setAge(account.getAge());
        loadedAccount.setId(account.getId());
        loadedAccount.setUsername(account.getUsername());
        loadedAccount.setFirstName(account.getFirstName());
        loadedAccount.setPassword(account.getPassword());
        loadedAccount.setLastName(account.getLastName());
        loadedAccount.setScore(account.getScore());


        System.out.println("!!"+loadedAccount.getUsername()+loadedAccount.getPassword());
        startProfileDetails();
    }

    public void write_file(String oldLogin, String oldPassword, De_serAccount newAccount) {
        String filePath = "src/main/resources/org/example/demo_oop_projectjavafx/data-base/user-list.txt";
        String tempFilePath = "src/main/resources/org/example/demo_oop_projectjavafx/data-base/temp/temp_user-list.txt";
        File inputFile = new File(filePath);
        File tempFile = new File(tempFilePath);
        boolean updated = false;

        try {
            BufferedReader reader = new BufferedReader(new FileReader(inputFile));
            BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(";");
                if (parts.length >= 5) {
                    String username = parts[0];
                    String password = parts[1];

                    if (username.equals(oldLogin) && password.equals(oldPassword)) {
                        line = newAccount.getUsername() + ";" + newAccount.getPassword() + ";" +
                                newAccount.getFirstName() + " " + newAccount.getLastName() + ";" +
                                newAccount.getAge() + ";" + newAccount.getId();
                        updated = true;
                    }
                }
                writer.write(line + System.lineSeparator());
            }
            writer.close();
            reader.close();

            if (!inputFile.delete()) {
                System.out.println("err del user file");
                return;
            }
            if (!tempFile.renameTo(inputFile)) {
                System.out.println("err del temp user file");
            }

            if (updated) {
                System.out.println("user upd. sucsecful");
            } else {
                System.out.println("err user upd.");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
