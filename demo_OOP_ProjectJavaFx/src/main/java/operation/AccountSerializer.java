package operation;

import users.UniversalAccount;

import java.io.*;

public class AccountSerializer {
    public static void saveUniversalAccount(UniversalAccount account, String filePath) throws IOException {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(filePath))) {
            outputStream.writeObject(account);
        }
    }

    public static UniversalAccount loadUniversalAccount(String filePath) throws IOException, ClassNotFoundException {
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(filePath))) {
            return (UniversalAccount) inputStream.readObject();
        }
    }
}
