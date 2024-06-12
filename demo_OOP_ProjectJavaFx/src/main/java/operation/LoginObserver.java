package operation;

import operation.PasswordExcep.InvalidPasswordException;
import users.Admin;
import users.UniversalAccount;
import users.User;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class LoginObserver {
    private static final String USER_LIST_FILE = "src/main/resources/org/example/demo_oop_projectjavafx/data-base/user-list.txt";
    private static final String ADMIN_LIST_FILE = "src/main/resources/org/example/demo_oop_projectjavafx/data-base/admin-list.txt";

    public UniversalAccount observeLogin(String username, String password) throws InvalidPasswordException {
        return findAccount(username, password);
    }

    private UniversalAccount findAccount(String username, String password) throws InvalidPasswordException {
        String[] fileList = {USER_LIST_FILE, ADMIN_LIST_FILE};

        for (String file : fileList) {
            try (BufferedReader br = new BufferedReader(new FileReader(file))) {
                String line;
                while ((line = br.readLine()) != null) {
                    String[] parts = line.split(";");
                    if (parts.length >= 2 && parts[0].equals(username) && parts[1].equals(password)) {
                        if (!password.matches("\\d+")) {
                            throw new InvalidPasswordException("Password must contain only digits.");
                        }
                        String[] userInfo = parts[2].split(" ");
                        int old = Integer.parseInt(parts[3]);
                        int id = Integer.parseInt(parts[4]);
                        if (file.equals(USER_LIST_FILE)) {
                            return new User(username, password, userInfo[0], userInfo[1], old, id);
                        } else {
                            int score = id;
                            int money = Integer.parseInt(parts[5]);
                            return new Admin(username, password, userInfo[0], userInfo[1], old, score, money);
                        }
                    }
                }
            } catch (IOException e) {
                throw new RuntimeException("Error reading file: " + file, e);
            }
        }
        throw new InvalidPasswordException("User not found");
    }
}
