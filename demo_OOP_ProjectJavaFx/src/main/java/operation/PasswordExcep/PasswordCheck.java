package operation.PasswordExcep;

public class PasswordCheck {

    public static void checkPassword(String password) throws InvalidPasswordException {
        if (password == null || password.isEmpty()) {
            throw new InvalidPasswordException("Password cant be empty!");
        }
        if (password.length() < 3) {
            throw new InvalidPasswordException("Password must have at least 3 characters!");
        }
        if (!password.matches("[0-9]+")) {
            throw new InvalidPasswordException("Password must have only numbers!");
        }
    }
}
