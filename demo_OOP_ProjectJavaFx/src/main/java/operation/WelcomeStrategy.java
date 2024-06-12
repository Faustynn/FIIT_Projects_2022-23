package operation;

public interface WelcomeStrategy {
    String getWelcomeMessage();

    default void LoginCheck(String role) {
        System.out.println(role+" was login successful!");
    }
}
